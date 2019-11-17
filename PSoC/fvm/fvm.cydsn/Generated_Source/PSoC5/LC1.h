/*******************************************************************************
* File Name: LC1.h  
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

#if !defined(CY_PINS_LC1_H) /* Pins LC1_H */
#define CY_PINS_LC1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LC1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LC1__PORT == 15 && ((LC1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LC1_Write(uint8 value);
void    LC1_SetDriveMode(uint8 mode);
uint8   LC1_ReadDataReg(void);
uint8   LC1_Read(void);
void    LC1_SetInterruptMode(uint16 position, uint16 mode);
uint8   LC1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LC1_SetDriveMode() function.
     *  @{
     */
        #define LC1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LC1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LC1_DM_RES_UP          PIN_DM_RES_UP
        #define LC1_DM_RES_DWN         PIN_DM_RES_DWN
        #define LC1_DM_OD_LO           PIN_DM_OD_LO
        #define LC1_DM_OD_HI           PIN_DM_OD_HI
        #define LC1_DM_STRONG          PIN_DM_STRONG
        #define LC1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LC1_MASK               LC1__MASK
#define LC1_SHIFT              LC1__SHIFT
#define LC1_WIDTH              1u

/* Interrupt constants */
#if defined(LC1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LC1_SetInterruptMode() function.
     *  @{
     */
        #define LC1_INTR_NONE      (uint16)(0x0000u)
        #define LC1_INTR_RISING    (uint16)(0x0001u)
        #define LC1_INTR_FALLING   (uint16)(0x0002u)
        #define LC1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LC1_INTR_MASK      (0x01u) 
#endif /* (LC1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LC1_PS                     (* (reg8 *) LC1__PS)
/* Data Register */
#define LC1_DR                     (* (reg8 *) LC1__DR)
/* Port Number */
#define LC1_PRT_NUM                (* (reg8 *) LC1__PRT) 
/* Connect to Analog Globals */                                                  
#define LC1_AG                     (* (reg8 *) LC1__AG)                       
/* Analog MUX bux enable */
#define LC1_AMUX                   (* (reg8 *) LC1__AMUX) 
/* Bidirectional Enable */                                                        
#define LC1_BIE                    (* (reg8 *) LC1__BIE)
/* Bit-mask for Aliased Register Access */
#define LC1_BIT_MASK               (* (reg8 *) LC1__BIT_MASK)
/* Bypass Enable */
#define LC1_BYP                    (* (reg8 *) LC1__BYP)
/* Port wide control signals */                                                   
#define LC1_CTL                    (* (reg8 *) LC1__CTL)
/* Drive Modes */
#define LC1_DM0                    (* (reg8 *) LC1__DM0) 
#define LC1_DM1                    (* (reg8 *) LC1__DM1)
#define LC1_DM2                    (* (reg8 *) LC1__DM2) 
/* Input Buffer Disable Override */
#define LC1_INP_DIS                (* (reg8 *) LC1__INP_DIS)
/* LCD Common or Segment Drive */
#define LC1_LCD_COM_SEG            (* (reg8 *) LC1__LCD_COM_SEG)
/* Enable Segment LCD */
#define LC1_LCD_EN                 (* (reg8 *) LC1__LCD_EN)
/* Slew Rate Control */
#define LC1_SLW                    (* (reg8 *) LC1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LC1_PRTDSI__CAPS_SEL       (* (reg8 *) LC1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LC1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LC1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LC1_PRTDSI__OE_SEL0        (* (reg8 *) LC1__PRTDSI__OE_SEL0) 
#define LC1_PRTDSI__OE_SEL1        (* (reg8 *) LC1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LC1_PRTDSI__OUT_SEL0       (* (reg8 *) LC1__PRTDSI__OUT_SEL0) 
#define LC1_PRTDSI__OUT_SEL1       (* (reg8 *) LC1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LC1_PRTDSI__SYNC_OUT       (* (reg8 *) LC1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LC1__SIO_CFG)
    #define LC1_SIO_HYST_EN        (* (reg8 *) LC1__SIO_HYST_EN)
    #define LC1_SIO_REG_HIFREQ     (* (reg8 *) LC1__SIO_REG_HIFREQ)
    #define LC1_SIO_CFG            (* (reg8 *) LC1__SIO_CFG)
    #define LC1_SIO_DIFF           (* (reg8 *) LC1__SIO_DIFF)
#endif /* (LC1__SIO_CFG) */

/* Interrupt Registers */
#if defined(LC1__INTSTAT)
    #define LC1_INTSTAT            (* (reg8 *) LC1__INTSTAT)
    #define LC1_SNAP               (* (reg8 *) LC1__SNAP)
    
	#define LC1_0_INTTYPE_REG 		(* (reg8 *) LC1__0__INTTYPE)
#endif /* (LC1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LC1_H */


/* [] END OF FILE */
