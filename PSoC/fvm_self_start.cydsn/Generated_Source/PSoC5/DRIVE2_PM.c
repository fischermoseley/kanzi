/*******************************************************************************
* File Name: DRIVE2_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "DRIVE2.h"

/* Check for removal by optimization */
#if !defined(DRIVE2_Sync_ctrl_reg__REMOVED)

static DRIVE2_BACKUP_STRUCT  DRIVE2_backup = {0u};

    
/*******************************************************************************
* Function Name: DRIVE2_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DRIVE2_SaveConfig(void) 
{
    DRIVE2_backup.controlState = DRIVE2_Control;
}


/*******************************************************************************
* Function Name: DRIVE2_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void DRIVE2_RestoreConfig(void) 
{
     DRIVE2_Control = DRIVE2_backup.controlState;
}


/*******************************************************************************
* Function Name: DRIVE2_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DRIVE2_Sleep(void) 
{
    DRIVE2_SaveConfig();
}


/*******************************************************************************
* Function Name: DRIVE2_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DRIVE2_Wakeup(void)  
{
    DRIVE2_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
