/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for Example Project: 8-ch DelSig ADC with I2C Master.
*
* Parameters used:
*  I2C Master
*   Implementation        Fixed function
*   Data rate            100kbps
*   SDA SCL pin config  Open drain, drives low
*   Pull-up resistors    2.67k each
*
*  Delta Sigma ADC
*      Conversion mode     1-Multi Sample
*    Resolution            16 bits
*    Conversion Rate        5000 SPS
*    Input mode            Differential
*
*  IDAC
*    Polarity            Positive
*    Range                0-31.875 uA
*    Speed                Slow
*    Current output        10 uA
*
*  Sequencing Max
*    Mux type            Differential
*    Channels            8
*
* In this project, data converted by the 8-channel, sequenced ADC is sent via
* a I2C Master. The project is tested with a separate project containing a I2C
* slave. The data output by the ADC is made visible on an Character LCD. This
* can be used to verify the data received by the I2C slave which is also
* displayed on an LCD screen.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>

/* The I2C Slave address by default in a PSoC device is 8 */
#define I2C_SLAVE_ADDRESS    (8u)
/* Set the write buffer length to be 16 bits or 2 bytes */
#define WR_BUFFER_SIZE       (2u)


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main function performs following functions:
*   1. Starts all used components.
*   2. Controls sequencing of ADC inputs.
*   3. Reads ADC converted data, sends this data via a I2C Master.
*   4. Displays ADC converted data on Character LCD.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void main()
{
    uint8 temp;
    uint8 sample_segment[WR_BUFFER_SIZE];
    uint16 sample_full;

    I2CM_Start();
    IDAC8_Start();

    /* The Start API for Mux sets it up, but disconnects all the channels.
     * To connect the first channel, call the 'AMuxSeq_Next' function.
     */
    AMuxSeq_Start();
    AMuxSeq_Next();

    /* The LCD will display the values read from ADC in hex */
    LCD_Char_Start();
    LCD_Char_PrintString("0x");

    ADC_DelSig_Start();
    ADC_DelSig_StartConvert();

    /* Enable global interrupts - required for I2C */
    CyGlobalIntEnable;

    for(;;)
    {
        ADC_DelSig_StartConvert();
        /* Wait until the ADC conversion is complete */
        ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT);
        /* Since the ADC conversion is complete, stop the conversion */
        ADC_DelSig_StopConvert();
        sample_full = ADC_DelSig_GetResult16();
        AMuxSeq_Next();
        sample_segment[0] = sample_full >> 8u & 0x00FFu;
        sample_segment[1] = sample_full & 0x00FFu;

        /* Attempt to initiate communication with the slave until the function
         * completes without error.
         */
        do
        {
            /* The syntax below automatically writes a buffer of data to a slave
             * device from start to stop.
              */
            temp = I2CM_MasterWriteBuf(I2C_SLAVE_ADDRESS, (uint8 *)sample_segment,
                                        WR_BUFFER_SIZE, I2CM_MODE_COMPLETE_XFER);
        }
        while (temp != I2CM_MSTR_NO_ERROR);

        /* Wait for the data transfer to complete */
        while(I2CM_MasterStatus() & I2CM_MSTAT_XFER_INP);

        temp = I2CM_MasterClearStatus();

        LCD_Char_ClearDisplay();

        /* If there is an error while transferring data */
        if(temp & I2CM_MSTAT_ERR_XFER)
        {
            /* Indicate the error */
            LCD_Char_PrintString("I2C Error! ");
            /* Place error handling code here */
        }
        else /* Write completed without error */
        {
            /* For verification purposes, display the adcReading on the LCD */
            LCD_Char_PrintString("0x");
            LCD_Char_PrintInt16(sample_full);
        }

        /* Delay introduced for ease of reading LCD */
        CyDelay(2000u/*ms*/);

    }  /* End forever loop */
} /* End main */


/* [] END OF FILE */
