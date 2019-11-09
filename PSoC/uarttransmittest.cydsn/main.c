#include "project.h"
#include <stdio.h>

#define True 1
#define False 0

int main(void){
    CyGlobalIntEnable; // Enable global interrupts
    HOST_UART_Start();
    IMU_UART_Start();
    

    uint8_t tempVar = 17;
    char outputBuffer[20];
    sprintf(outputBuffer, "howdy: %d\r\n", tempVar);
    HOST_UART_PutString(outputBuffer);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    while(True){
        // Poll IMU UART and print any new data to host
        while(IMU_UART_ReadRxStatus() == IMU_UART_RX_STS_FIFO_NOTEMPTY){
            // There must be some data available, let's read it and send it over HOST_UART
            uint8_t recieved = IMU_UART_GetChar();
            HOST_UART_PutChar(recieved);
            HOST_UART_PutString("\r\n\r\n");
            HOST_UART_PutChar(IMU_UART_ReadRxStatus());
        }
    }
}
