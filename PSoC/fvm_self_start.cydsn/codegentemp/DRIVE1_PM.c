/*******************************************************************************
* File Name: DRIVE1_PM.c
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

#include "DRIVE1.h"

/* Check for removal by optimization */
#if !defined(DRIVE1_Sync_ctrl_reg__REMOVED)

static DRIVE1_BACKUP_STRUCT  DRIVE1_backup = {0u};

    
/*******************************************************************************
* Function Name: DRIVE1_SaveConfig
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
void DRIVE1_SaveConfig(void) 
{
    DRIVE1_backup.controlState = DRIVE1_Control;
}


/*******************************************************************************
* Function Name: DRIVE1_RestoreConfig
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
void DRIVE1_RestoreConfig(void) 
{
     DRIVE1_Control = DRIVE1_backup.controlState;
}


/*******************************************************************************
* Function Name: DRIVE1_Sleep
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
void DRIVE1_Sleep(void) 
{
    DRIVE1_SaveConfig();
}


/*******************************************************************************
* Function Name: DRIVE1_Wakeup
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
void DRIVE1_Wakeup(void)  
{
    DRIVE1_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
