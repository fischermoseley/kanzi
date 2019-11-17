/*******************************************************************************
* File Name: DRIVE2_LB.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DRIVE2_LB_H) /* Pins DRIVE2_LB_H */
#define CY_PINS_DRIVE2_LB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DRIVE2_LB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DRIVE2_LB__PORT == 15 && ((DRIVE2_LB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DRIVE2_LB_Write(uint8 value);
void    DRIVE2_LB_SetDriveMode(uint8 mode);
uint8   DRIVE2_LB_ReadDataReg(void);
uint8   DRIVE2_LB_Read(void);
void    DRIVE2_LB_SetInterruptMode(uint16 position, uint16 mode);
uint8   DRIVE2_LB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DRIVE2_LB_SetDriveMode() function.
     *  @{
     */
        #define DRIVE2_LB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DRIVE2_LB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DRIVE2_LB_DM_RES_UP          PIN_DM_RES_UP
        #define DRIVE2_LB_DM_RES_DWN         PIN_DM_RES_DWN
        #define DRIVE2_LB_DM_OD_LO           PIN_DM_OD_LO
        #define DRIVE2_LB_DM_OD_HI           PIN_DM_OD_HI
        #define DRIVE2_LB_DM_STRONG          PIN_DM_STRONG
        #define DRIVE2_LB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DRIVE2_LB_MASK               DRIVE2_LB__MASK
#define DRIVE2_LB_SHIFT              DRIVE2_LB__SHIFT
#define DRIVE2_LB_WIDTH              1u

/* Interrupt constants */
#if defined(DRIVE2_LB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DRIVE2_LB_SetInterruptMode() function.
     *  @{
     */
        #define DRIVE2_LB_INTR_NONE      (uint16)(0x0000u)
        #define DRIVE2_LB_INTR_RISING    (uint16)(0x0001u)
        #define DRIVE2_LB_INTR_FALLING   (uint16)(0x0002u)
        #define DRIVE2_LB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DRIVE2_LB_INTR_MASK      (0x01u) 
#endif /* (DRIVE2_LB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DRIVE2_LB_PS                     (* (reg8 *) DRIVE2_LB__PS)
/* Data Register */
#define DRIVE2_LB_DR                     (* (reg8 *) DRIVE2_LB__DR)
/* Port Number */
#define DRIVE2_LB_PRT_NUM                (* (reg8 *) DRIVE2_LB__PRT) 
/* Connect to Analog Globals */                                                  
#define DRIVE2_LB_AG                     (* (reg8 *) DRIVE2_LB__AG)                       
/* Analog MUX bux enable */
#define DRIVE2_LB_AMUX                   (* (reg8 *) DRIVE2_LB__AMUX) 
/* Bidirectional Enable */                                                        
#define DRIVE2_LB_BIE                    (* (reg8 *) DRIVE2_LB__BIE)
/* Bit-mask for Aliased Register Access */
#define DRIVE2_LB_BIT_MASK               (* (reg8 *) DRIVE2_LB__BIT_MASK)
/* Bypass Enable */
#define DRIVE2_LB_BYP                    (* (reg8 *) DRIVE2_LB__BYP)
/* Port wide control signals */                                                   
#define DRIVE2_LB_CTL                    (* (reg8 *) DRIVE2_LB__CTL)
/* Drive Modes */
#define DRIVE2_LB_DM0                    (* (reg8 *) DRIVE2_LB__DM0) 
#define DRIVE2_LB_DM1                    (* (reg8 *) DRIVE2_LB__DM1)
#define DRIVE2_LB_DM2                    (* (reg8 *) DRIVE2_LB__DM2) 
/* Input Buffer Disable Override */
#define DRIVE2_LB_INP_DIS                (* (reg8 *) DRIVE2_LB__INP_DIS)
/* LCD Common or Segment Drive */
#define DRIVE2_LB_LCD_COM_SEG            (* (reg8 *) DRIVE2_LB__LCD_COM_SEG)
/* Enable Segment LCD */
#define DRIVE2_LB_LCD_EN                 (* (reg8 *) DRIVE2_LB__LCD_EN)
/* Slew Rate Control */
#define DRIVE2_LB_SLW                    (* (reg8 *) DRIVE2_LB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DRIVE2_LB_PRTDSI__CAPS_SEL       (* (reg8 *) DRIVE2_LB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DRIVE2_LB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DRIVE2_LB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DRIVE2_LB_PRTDSI__OE_SEL0        (* (reg8 *) DRIVE2_LB__PRTDSI__OE_SEL0) 
#define DRIVE2_LB_PRTDSI__OE_SEL1        (* (reg8 *) DRIVE2_LB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DRIVE2_LB_PRTDSI__OUT_SEL0       (* (reg8 *) DRIVE2_LB__PRTDSI__OUT_SEL0) 
#define DRIVE2_LB_PRTDSI__OUT_SEL1       (* (reg8 *) DRIVE2_LB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DRIVE2_LB_PRTDSI__SYNC_OUT       (* (reg8 *) DRIVE2_LB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DRIVE2_LB__SIO_CFG)
    #define DRIVE2_LB_SIO_HYST_EN        (* (reg8 *) DRIVE2_LB__SIO_HYST_EN)
    #define DRIVE2_LB_SIO_REG_HIFREQ     (* (reg8 *) DRIVE2_LB__SIO_REG_HIFREQ)
    #define DRIVE2_LB_SIO_CFG            (* (reg8 *) DRIVE2_LB__SIO_CFG)
    #define DRIVE2_LB_SIO_DIFF           (* (reg8 *) DRIVE2_LB__SIO_DIFF)
#endif /* (DRIVE2_LB__SIO_CFG) */

/* Interrupt Registers */
#if defined(DRIVE2_LB__INTSTAT)
    #define DRIVE2_LB_INTSTAT            (* (reg8 *) DRIVE2_LB__INTSTAT)
    #define DRIVE2_LB_SNAP               (* (reg8 *) DRIVE2_LB__SNAP)
    
	#define DRIVE2_LB_0_INTTYPE_REG 		(* (reg8 *) DRIVE2_LB__0__INTTYPE)
#endif /* (DRIVE2_LB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DRIVE2_LB_H */


/* [] END OF FILE */
