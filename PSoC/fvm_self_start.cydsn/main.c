#include "project.h"
#define True 1 
#define False 0
#define FORWARD 1
#define REVERSE 0

uint8_t getState(uint8_t port) {
    //Returns a byte containing the current rotational position of the motor.

    uint8_t a = 0;
    uint8_t b = 0;
    uint8_t c = 0;


    // casting to an 8-bit byte just because the cypress documentation is garbage and doesn't say
    // whether or not it returns a bool or uint8_t
    if(port == 1){
        a = HALL1_A_Read(); 
        b = HALL1_B_Read();
        c = HALL1_C_Read();
    }

    if(port == 2){
        a = HALL2_A_Read();
        b = HALL2_B_Read();
        c = HALL2_C_Read();
    }

    return ( a || (b << 1) || (c << 2) );
}

uint8_t advanceState(uint8_t current_state, uint8_t direction, uint8_t port) {
    //Takes in the current state of the motor and computes the next state of the
    //drive FETS, and returns this state.
    //Set direction to true for forward, and false for backwards.

    //Find what the next state to be commutated is
    uint8_t advanceState = 0;

    if(direction == True) advanceState = (current_state + 0x01) % 0x07;
    if(direction == False) advanceState = (current_state + 0x06) % 0x07;


    //Send the new state to the given motor
    switch (port) {
    case 1:
        DRIVE1_Write(advanceState);
        break;

    case 2:
        DRIVE2_Write(advanceState);
        break;
    
    default:
        break;
    }
    return advanceState; //return the new state of the drive FETs. 
}

void init(void) {
    CyGlobalIntEnable; //enable global interrupts
}

void loop(void) {
    uint8_t motor1_current_state = getState(1);
    advanceState(motor1_current_state, FORWARD, 1);    
}

int main(void){
    init();

    while(True) {
        loop();
    }
}
