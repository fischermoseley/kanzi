/*******************************************************************************
* File Name: IMU_UARTINT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service functionality of the UART component
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IMU_UART.h"
#include "cyapicallbacks.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if (IMU_UART_RX_INTERRUPT_ENABLED && (IMU_UART_RX_ENABLED || IMU_UART_HD_ENABLED))
    /*******************************************************************************
    * Function Name: IMU_UART_RXISR
    ********************************************************************************
    *
    * Summary:
    *  Interrupt Service Routine for RX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  IMU_UART_rxBuffer - RAM buffer pointer for save received data.
    *  IMU_UART_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  IMU_UART_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  IMU_UART_rxBufferOverflow - software overflow flag. Set to one
    *     when IMU_UART_rxBufferWrite index overtakes
    *     IMU_UART_rxBufferRead index.
    *  IMU_UART_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when IMU_UART_rxBufferWrite is equal to
    *    IMU_UART_rxBufferRead
    *  IMU_UART_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  IMU_UART_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(IMU_UART_RXISR)
    {
        uint8 readData;
        uint8 readStatus;
        uint8 increment_pointer = 0u;

    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

    #ifdef IMU_UART_RXISR_ENTRY_CALLBACK
        IMU_UART_RXISR_EntryCallback();
    #endif /* IMU_UART_RXISR_ENTRY_CALLBACK */

        /* User code required at start of ISR */
        /* `#START IMU_UART_RXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        do
        {
            /* Read receiver status register */
            readStatus = IMU_UART_RXSTATUS_REG;
            /* Copy the same status to readData variable for backward compatibility support 
            *  of the user code in IMU_UART_RXISR_ERROR` section. 
            */
            readData = readStatus;

            if((readStatus & (IMU_UART_RX_STS_BREAK | 
                            IMU_UART_RX_STS_PAR_ERROR |
                            IMU_UART_RX_STS_STOP_ERROR | 
                            IMU_UART_RX_STS_OVERRUN)) != 0u)
            {
                /* ERROR handling. */
                IMU_UART_errorStatus |= readStatus & ( IMU_UART_RX_STS_BREAK | 
                                                            IMU_UART_RX_STS_PAR_ERROR | 
                                                            IMU_UART_RX_STS_STOP_ERROR | 
                                                            IMU_UART_RX_STS_OVERRUN);
                /* `#START IMU_UART_RXISR_ERROR` */

                /* `#END` */
                
            #ifdef IMU_UART_RXISR_ERROR_CALLBACK
                IMU_UART_RXISR_ERROR_Callback();
            #endif /* IMU_UART_RXISR_ERROR_CALLBACK */
            }
            
            if((readStatus & IMU_UART_RX_STS_FIFO_NOTEMPTY) != 0u)
            {
                /* Read data from the RX data register */
                readData = IMU_UART_RXDATA_REG;
            #if (IMU_UART_RXHW_ADDRESS_ENABLED)
                if(IMU_UART_rxAddressMode == (uint8)IMU_UART__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readStatus & IMU_UART_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readStatus & IMU_UART_RX_STS_ADDR_MATCH) != 0u)
                        {
                            IMU_UART_rxAddressDetected = 1u;
                        }
                        else
                        {
                            IMU_UART_rxAddressDetected = 0u;
                        }
                    }
                    if(IMU_UART_rxAddressDetected != 0u)
                    {   /* Store only addressed data */
                        IMU_UART_rxBuffer[IMU_UART_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* Without software addressing */
                {
                    IMU_UART_rxBuffer[IMU_UART_rxBufferWrite] = readData;
                    increment_pointer = 1u;
                }
            #else  /* Without addressing */
                IMU_UART_rxBuffer[IMU_UART_rxBufferWrite] = readData;
                increment_pointer = 1u;
            #endif /* (IMU_UART_RXHW_ADDRESS_ENABLED) */

                /* Do not increment buffer pointer when skip not addressed data */
                if(increment_pointer != 0u)
                {
                    if(IMU_UART_rxBufferLoopDetect != 0u)
                    {   /* Set Software Buffer status Overflow */
                        IMU_UART_rxBufferOverflow = 1u;
                    }
                    /* Set next pointer. */
                    IMU_UART_rxBufferWrite++;

                    /* Check pointer for a loop condition */
                    if(IMU_UART_rxBufferWrite >= IMU_UART_RX_BUFFER_SIZE)
                    {
                        IMU_UART_rxBufferWrite = 0u;
                    }

                    /* Detect pre-overload condition and set flag */
                    if(IMU_UART_rxBufferWrite == IMU_UART_rxBufferRead)
                    {
                        IMU_UART_rxBufferLoopDetect = 1u;
                        /* When Hardware Flow Control selected */
                        #if (IMU_UART_FLOW_CONTROL != 0u)
                            /* Disable RX interrupt mask, it is enabled when user read data from the buffer using APIs */
                            IMU_UART_RXSTATUS_MASK_REG  &= (uint8)~IMU_UART_RX_STS_FIFO_NOTEMPTY;
                            CyIntClearPending(IMU_UART_RX_VECT_NUM);
                            break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                        #endif /* (IMU_UART_FLOW_CONTROL != 0u) */
                    }
                }
            }
        }while((readStatus & IMU_UART_RX_STS_FIFO_NOTEMPTY) != 0u);

        /* User code required at end of ISR (Optional) */
        /* `#START IMU_UART_RXISR_END` */

        /* `#END` */

    #ifdef IMU_UART_RXISR_EXIT_CALLBACK
        IMU_UART_RXISR_ExitCallback();
    #endif /* IMU_UART_RXISR_EXIT_CALLBACK */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
    }
    
#endif /* (IMU_UART_RX_INTERRUPT_ENABLED && (IMU_UART_RX_ENABLED || IMU_UART_HD_ENABLED)) */


#if (IMU_UART_TX_INTERRUPT_ENABLED && IMU_UART_TX_ENABLED)
    /*******************************************************************************
    * Function Name: IMU_UART_TXISR
    ********************************************************************************
    *
    * Summary:
    * Interrupt Service Routine for the TX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  IMU_UART_txBuffer - RAM buffer pointer for transmit data from.
    *  IMU_UART_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmitted byte.
    *  IMU_UART_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(IMU_UART_TXISR)
    {
    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

    #ifdef IMU_UART_TXISR_ENTRY_CALLBACK
        IMU_UART_TXISR_EntryCallback();
    #endif /* IMU_UART_TXISR_ENTRY_CALLBACK */

        /* User code required at start of ISR */
        /* `#START IMU_UART_TXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        while((IMU_UART_txBufferRead != IMU_UART_txBufferWrite) &&
             ((IMU_UART_TXSTATUS_REG & IMU_UART_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer wrap around */
            if(IMU_UART_txBufferRead >= IMU_UART_TX_BUFFER_SIZE)
            {
                IMU_UART_txBufferRead = 0u;
            }

            IMU_UART_TXDATA_REG = IMU_UART_txBuffer[IMU_UART_txBufferRead];

            /* Set next pointer */
            IMU_UART_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START IMU_UART_TXISR_END` */

        /* `#END` */

    #ifdef IMU_UART_TXISR_EXIT_CALLBACK
        IMU_UART_TXISR_ExitCallback();
    #endif /* IMU_UART_TXISR_EXIT_CALLBACK */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
   }
#endif /* (IMU_UART_TX_INTERRUPT_ENABLED && IMU_UART_TX_ENABLED) */


/* [] END OF FILE */
