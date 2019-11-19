#define True 1
#define False 0
#include "project.h"

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

void writeToFETs(uint8_t status) {
  LEFT_HA_Write(bitRead(status, 5));
  LEFT_LA_Write(bitRead(status, 4));
  LEFT_HB_Write(bitRead(status, 3));
  LEFT_LB_Write(bitRead(status, 2));
  LEFT_HC_Write(bitRead(status, 1));
  LEFT_LC_Write(bitRead(status, 0));
}


int main(void) {
  CyGlobalIntEnable;

  while(True) {
    uint8_t left_direction = LEFT_DIR_Read();

    //grab hall effect sensor states
    uint8_t left_hall_a = LEFT_HALL_A_Read();
    uint8_t left_hall_b = LEFT_HALL_B_Read();
    uint8_t left_hall_c = LEFT_HALL_C_Read();

    //check to see what direction we're running in, and select the appropriate commutation table
    if(left_direction == 1) { //use forward commutation table
      if(left_hall_c && !left_hall_b && left_hall_a) writeToFETs(36); //101
      if(left_hall_c && !left_hall_b && !left_hall_a) writeToFETs(6); //100
      if(left_hall_c && left_hall_b && !left_hall_a) writeToFETs(18); //110
      if(!left_hall_c && left_hall_b && !left_hall_a) writeToFETs(24); //010
      if(!left_hall_c && left_hall_b && left_hall_a) writeToFETs(9); //011
      if(!left_hall_c && !left_hall_b && left_hall_a) writeToFETs(33); //001
    }

    if(left_direction == 0) { //use reverse commutation table
      if(!left_hall_c && !left_hall_b && left_hall_a) writeToFETs(18); //001
      if(!left_hall_c && left_hall_b && !left_hall_a) writeToFETs(36); //010
      if(!left_hall_c && left_hall_b && left_hall_a) writeToFETs(6); //011
      if(left_hall_c && !left_hall_b && !left_hall_a) writeToFETs(9); //100
      if(left_hall_c && !left_hall_b && left_hall_a) writeToFETs(24); //101
      if(left_hall_c && left_hall_b && !left_hall_a) writeToFETs(33); //110
    }
  }
}