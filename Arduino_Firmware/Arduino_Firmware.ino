/*
Kanzi is a onewheel-inspired skateboard built as a final project for MIT's
6.1311 Power Electronics Laboratory Class taken in the fall of 2019. Kanzi
uses two motors mounted in the center of a skateboard to self-balance and
then drive the user around.

She's named after Kanzi the Bonobo, which is an endangered species of great ape.
This is in reference to a point in class where Steve Leeb was discussing the
step response of proportional controllers, and proceeded to use the term "ape"
to describe the intermediate system outputs. We thought it was hilarious.

This firmware is designed to take in position vector readings from a BNO080 IMU,
run a PID loop, and then output a PWM signal and a direction pin for each motor.
These signals get fed into a PSoC 5LP, which then combines them with the motor
commutation logic to control the phase windings.

Firmware by Fischer Moseley '22, a sophomore at MIT studying Electrical Eningeering
and Physics. Feel free to use it as you wish, but do tell me if you do something
cool with it!
*/

#include <PID_v1.h>
#include <Wire.h>
#include "SparkFun_BNO080_Arduino_Library.h"


/*--------------- State Variables -----------------*/
struct eulerAngle{ double yaw; double pitch; double roll; };
eulerAngle rotationVector;
eulerAngle gyroRate;

struct stateVector { double left_motor; double right_motor; };
stateVector controlVector;

/*------------- Hardware Configuration ----------- */
//PSoC motor controller configuration
#define MIN_MOTOR_OUTPUT -255
#define MAX_MOTOR_OUTPUT 255
#define FORWARD 0 //the logic level on the direction pin that makes the motor go forwards
#define REVERSE 1 //the logic level on the direction pin that makes the motor go backwards

#define LEFT_MOTOR_PWM 13
#define LEFT_MOTOR_DIR 11
#define RIGHT_MOTOR_PWM 12
#define RIGHT_MOTOR_DIR 10

//IMU configuration
BNO080 IMU;

struct PIDconfigContainer { 
  double yawSetpoint = 0;
  double pitchSetpoint = 0;
  double rollSetpoint = 90;
  double K_p = 100;
  double K_i = 0;
  double K_d = 0;
} PIDconfig;

//Specify links and initial tuning parameters
PID leftPID(&rotationVector.pitch, &controlVector.left_motor, &PIDconfig.pitchSetpoint, PIDconfig.K_p, PIDconfig.K_i, PIDconfig.K_d, DIRECT);
PID rightPID(&rotationVector.pitch, &controlVector.right_motor, &PIDconfig.pitchSetpoint, PIDconfig.K_p, PIDconfig.K_i, PIDconfig.K_d, DIRECT);

/*------------- Wrapper Functions ----------- */
void updateRotationVector(struct eulerAngle* rotationVector){
  if(IMU.dataAvailable()){
    float i = IMU.getQuatI();
    float j = IMU.getQuatJ();
    float k = IMU.getQuatK();
    float r = IMU.getQuatReal();
    float x; float y;

    /* YAW */ 
    x = 2 * ((i * j) + (r * k)); 
    y = square(r) - square(k) - square(j) + square(i); 
    rotationVector->yaw = degrees(atan2(y, x));

    /* PITCH */ 
    rotationVector->pitch = degrees(asin(-2 * (i * k - j * r)));

    /* ROLL */ 
    x = 2 * ((j * k) + (i * r)); 
    y = square(r) + square(k) - square(j) - square(i); 
    rotationVector->roll = degrees(atan2(y , x));
  }
}

void updateGyroRate(struct eulerAngle* angleVariable){
  if(IMU.dataAvailable()){
    angleVariable->yaw    =  IMU.getGyroX();
    angleVariable->pitch  =  IMU.getGyroY();
    angleVariable->roll   =  IMU.getGyroZ();
  }
}

uint8_t updateMotors(struct stateVector* controlVector){
    //send command to the PSoC motor controller with the new motor command using the values in controlVector.

    //cast the left and right motor controls to uint8_t, as they are stored as doubles (required by PID library :/)
    uint8_t left_motor = static_cast<uint8_t>(controlVector->left_motor);
    uint8_t right_motor = static_cast<uint8_t>(controlVector->right_motor);

    //check to see that both values are in check
    if(left_motor > MAX_MOTOR_OUTPUT || left_motor < MIN_MOTOR_OUTPUT) return 1;
    if(right_motor > MAX_MOTOR_OUTPUT || right_motor < MIN_MOTOR_OUTPUT) return 2;

    //update the left motor
    if(left_motor > 0) digitalWrite(LEFT_MOTOR_DIR, FORWARD);
    if(left_motor < 0) digitalWrite(LEFT_MOTOR_DIR, REVERSE);
    analogWrite(LEFT_MOTOR_PWM, controlVector->left_motor);

    //update the right motor
    if(right_motor > 0) digitalWrite(RIGHT_MOTOR_DIR, FORWARD);
    if(right_motor < 0) digitalWrite(RIGHT_MOTOR_DIR, REVERSE);
    analogWrite(RIGHT_MOTOR_PWM, controlVector->right_motor);

    return 0;
}

void printControlVector(struct stateVector* controlVector){
  //prints to the serial port the current contents of controlVector.

  Serial.print("ControlVector: left_motor: ");
  Serial.print(controlVector->left_motor);
  Serial.print("  right_motor: ");
  Serial.print(controlVector->right_motor);
  Serial.println();
}

void setup() {
  //start up all them interfaces
  Serial.begin(115200);

  Wire.begin();
  Wire.setClock(400000);
  IMU.begin();
  IMU.enableRotationVector(10); //enable the rotation vector to be updated every 10ms

  pinMode(LEFT_MOTOR_DIR, OUTPUT); //configure all the I/O
  pinMode(LEFT_MOTOR_PWM, OUTPUT);
  pinMode(RIGHT_MOTOR_DIR, OUTPUT);
  pinMode(RIGHT_MOTOR_PWM, OUTPUT);

  //turn on PID
  leftPID.SetOutputLimits(MIN_MOTOR_OUTPUT, MAX_MOTOR_OUTPUT); //set the output limits of the PID controllers
  rightPID.SetOutputLimits(MIN_MOTOR_OUTPUT, MAX_MOTOR_OUTPUT);
  leftPID.SetMode(AUTOMATIC);
  rightPID.SetMode(AUTOMATIC);
}

void loop() {
  updateRotationVector(&rotationVector); //get new rotation vector data

  leftPID.Compute(); //recompute motor PIDs
  rightPID.Compute();

  updateMotors(&controlVector); //update motor speeds
}