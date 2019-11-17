/*******************************************************************************
* File Name: REVERSE1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_REVERSE1_ALIASES_H) /* Pins REVERSE1_ALIASES_H */
#define CY_PINS_REVERSE1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define REVERSE1_0			(REVERSE1__0__PC)
#define REVERSE1_0_INTR	((uint16)((uint16)0x0001u << REVERSE1__0__SHIFT))

#define REVERSE1_INTR_ALL	 ((uint16)(REVERSE1_0_INTR))

#endif /* End Pins REVERSE1_ALIASES_H */


/* [] END OF FILE */
