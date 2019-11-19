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
#include <math.h>
#define FORWARD 0 //the logic level on the direction pin that makes the motor go forwards
#define REVERSE 1 //the logic level on the direction pin that makes the motor go backwards

/*--------------- State Variables -----------------*/
struct eulerAngle{ double yaw; double pitch; double roll; };
eulerAngle rotationVector;
eulerAngle gyroRate;

struct stateVector { double left_motor; double right_motor; };
stateVector controlVector;

struct Motor {
  //configuration
  uint8_t stopThresholdTime = 10; //the amount of time (in ms) that has to pass where the hall effect sensors don't change to be considered "stopped"
  const int16_t MIN_MOTOR_OUTPUT = -255;
  const uint8_t MAX_MOTOR_OUTPUT = 255;

  //IO pin definitions
  uint8_t HALL_A_PIN = 0;
  uint8_t HALL_B_PIN = 0;
  uint8_t HALL_C_PIN = 0;
  uint8_t PWM_PIN = 0;
  uint8_t DIR_PIN = 0;

  //state variables
  uint8_t lastHallState = 0;
  unsigned long lastHallChange = millis(); //timestamp (in MCU time) of the last time that the hall effect sensor's state changed

  int16_t pwm = 0; // the duty cycle of the PWM on the high side motor FETS, from -255 (full reverse) to 255 (full forwards)
  
  //set internal variables and configure GPIO
  void init(uint8_t Hall_A, uint8_t Hall_B, uint8_t Hall_C, uint8_t PWM, uint8_t Dir) {
    //set internal variables with pin definitions
    HALL_A_PIN = Hall_A;
    HALL_B_PIN = Hall_B;
    HALL_C_PIN = Hall_C;

    PWM_PIN = PWM;
    DIR_PIN = Dir;

    //configure IO
    pinMode(HALL_A_PIN, INPUT);
    pinMode(HALL_B_PIN, INPUT);
    pinMode(HALL_C_PIN, INPUT);
    
    pinMode(PWM_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
  }

  //returns true if the motor's hall effect sensors haven't changed in the last 10ms, false otherwise
  bool isStopped() {
    //get the current state of the hall effect array
    uint8_t currentState = 0x00;
    bitWrite(currentState, 2, digitalRead(HALL_A_PIN));
    bitWrite(currentState, 1, digitalRead(HALL_B_PIN));
    bitWrite(currentState, 0, digitalRead(HALL_C_PIN));


    if(currentState == lastHallState) { //the motor hasn't changed position, so check if enough time has passed
      if(millis() - lastHallChange > stopThresholdTime) {
        //the motor is stopped because it's halls haven't changed in stopThresholdTime (~10ms)
        //leave both lastHallState and lastHallChange alone, because we have no reason to change them.
        return true;
      }

      //the motor could be stopped, but we need to wait longer
      //leave both lastHallState and lastHallChange alone, because we'll want to check those later
    }

    //the hall positions have changed, so the motor must be turning
    //the last state of the hall effect sensors is no longer valid, so update both it and when it was last changed
    lastHallState = currentState;
    lastHallChange = millis();
    
    return false;
  }

  //updates IO, pushes motor state
  bool update(double new_pwm){
    //cast the left and right motor controls to int16_t, as they are stored as doubles (required by PID library :/)
    uint16_t pwm = static_cast<int16_t>(new_pwm);

    //if the new PWM command is outside the allowable range, don't do anything and return with error
    if(pwm > MAX_MOTOR_OUTPUT || pwm < MIN_MOTOR_OUTPUT) return 1;

    if(pwm < 0) digitalWrite(DIR_PIN, REVERSE);
    if(pwm > 0) digitalWrite(DIR_PIN, FORWARD);

    analogWrite(PWM_PIN, abs(pwm));
    return 0;
  }
};


/*------------- Hardware Configuration ----------- */
//IO pins to use for interfacing with the PSoC controller
#define LEFT_MOTOR_PWM 5
#define RIGHT_MOTOR_PWM 6
#define LEFT_MOTOR_DIR 7
#define RIGHT_MOTOR_DIR 8

//IO pins to use for interfacing with the hall effect sensors
#define LEFT_HALL_A 1
#define LEFT_HALL_B 1
#define LEFT_HALL_C 1
#define RIGHT_HALL_A 1
#define RIGHT_HALL_B 1
#define RIGHT_HALL_C 1

//Motor configuration
Motor leftMotor, rightMotor;

//IMU configuration
BNO080 IMU;

struct PIDconfigContainer { 
  double yawSetpoint = 0;
  double pitchSetpoint = 0;
  double rollSetpoint = 90;
  double K_p = 10;
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
    y = sq(r) - sq(k) - sq(j) + sq(i); 
    rotationVector->yaw = degrees(atan2(y, x));

    /* PITCH */ 
    rotationVector->pitch = degrees(asin(-2 * (i * k - j * r)));

    /* ROLL */ 
    x = 2 * ((j * k) + (i * r)); 
    y = sq(r) + sq(k) - sq(j) - sq(i); 
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

void printStateVector(struct stateVector* controlVector){
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

  //configure the motor GPIO
  leftMotor.init(LEFT_HALL_A, LEFT_HALL_B, LEFT_HALL_C, LEFT_MOTOR_PWM, LEFT_MOTOR_DIR);
  rightMotor.init(RIGHT_HALL_A, RIGHT_HALL_B, RIGHT_HALL_C, RIGHT_MOTOR_PWM, RIGHT_MOTOR_DIR);

  //turn on PID
  leftPID.SetOutputLimits(leftMotor.MIN_MOTOR_OUTPUT, leftMotor.MAX_MOTOR_OUTPUT); //set the output limits of the PID controllers
  rightPID.SetOutputLimits(rightMotor.MIN_MOTOR_OUTPUT, rightMotor.MAX_MOTOR_OUTPUT);
  leftPID.SetMode(AUTOMATIC);
  rightPID.SetMode(AUTOMATIC);
}

void loop() {
  updateRotationVector(&rotationVector); //get new rotation vector data

  leftPID.Compute(); //recompute motor PIDs
  rightPID.Compute();

  printStateVector(&controlVector);
  Serial.println(leftMotor.isStopped());
}
