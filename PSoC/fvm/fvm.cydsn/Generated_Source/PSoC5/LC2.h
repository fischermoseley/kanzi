/*******************************************************************************
* File Name: LC2.h  
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

#if !defined(CY_PINS_LC2_H) /* Pins LC2_H */
#define CY_PINS_LC2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LC2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LC2__PORT == 15 && ((LC2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LC2_Write(uint8 value);
void    LC2_SetDriveMode(uint8 mode);
uint8   LC2_ReadDataReg(void);
uint8   LC2_Read(void);
void    LC2_SetInterruptMode(uint16 position, uint16 mode);
uint8   LC2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LC2_SetDriveMode() function.
     *  @{
     */
        #define LC2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LC2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LC2_DM_RES_UP          PIN_DM_RES_UP
        #define LC2_DM_RES_DWN         PIN_DM_RES_DWN
        #define LC2_DM_OD_LO           PIN_DM_OD_LO
        #define LC2_DM_OD_HI           PIN_DM_OD_HI
        #define LC2_DM_STRONG          PIN_DM_STRONG
        #define LC2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LC2_MASK               LC2__MASK
#define LC2_SHIFT              LC2__SHIFT
#define LC2_WIDTH              1u

/* Interrupt constants */
#if defined(LC2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LC2_SetInterruptMode() function.
     *  @{
     */
        #define LC2_INTR_NONE      (uint16)(0x0000u)
        #define LC2_INTR_RISING    (uint16)(0x0001u)
        #define LC2_INTR_FALLING   (uint16)(0x0002u)
        #define LC2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LC2_INTR_MASK      (0x01u) 
#endif /* (LC2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LC2_PS                     (* (reg8 *) LC2__PS)
/* Data Register */
#define LC2_DR                     (* (reg8 *) LC2__DR)
/* Port Number */
#define LC2_PRT_NUM                (* (reg8 *) LC2__PRT) 
/* Connect to Analog Globals */                                                  
#define LC2_AG                     (* (reg8 *) LC2__AG)                       
/* Analog MUX bux enable */
#define LC2_AMUX                   (* (reg8 *) LC2__AMUX) 
/* Bidirectional Enable */                                                        
#define LC2_BIE                    (* (reg8 *) LC2__BIE)
/* Bit-mask for Aliased Register Access */
#define LC2_BIT_MASK               (* (reg8 *) LC2__BIT_MASK)
/* Bypass Enable */
#define LC2_BYP                    (* (reg8 *) LC2__BYP)
/* Port wide control signals */                                                   
#define LC2_CTL                    (* (reg8 *) LC2__CTL)
/* Drive Modes */
#define LC2_DM0                    (* (reg8 *) LC2__DM0) 
#define LC2_DM1                    (* (reg8 *) LC2__DM1)
#define LC2_DM2                    (* (reg8 *) LC2__DM2) 
/* Input Buffer Disable Override */
#define LC2_INP_DIS                (* (reg8 *) LC2__INP_DIS)
/* LCD Common or Segment Drive */
#define LC2_LCD_COM_SEG            (* (reg8 *) LC2__LCD_COM_SEG)
/* Enable Segment LCD */
#define LC2_LCD_EN                 (* (reg8 *) LC2__LCD_EN)
/* Slew Rate Control */
#define LC2_SLW                    (* (reg8 *) LC2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LC2_PRTDSI__CAPS_SEL       (* (reg8 *) LC2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LC2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LC2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LC2_PRTDSI__OE_SEL0        (* (reg8 *) LC2__PRTDSI__OE_SEL0) 
#define LC2_PRTDSI__OE_SEL1        (* (reg8 *) LC2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LC2_PRTDSI__OUT_SEL0       (* (reg8 *) LC2__PRTDSI__OUT_SEL0) 
#define LC2_PRTDSI__OUT_SEL1       (* (reg8 *) LC2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LC2_PRTDSI__SYNC_OUT       (* (reg8 *) LC2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LC2__SIO_CFG)
    #define LC2_SIO_HYST_EN        (* (reg8 *) LC2__SIO_HYST_EN)
    #define LC2_SIO_REG_HIFREQ     (* (reg8 *) LC2__SIO_REG_HIFREQ)
    #define LC2_SIO_CFG            (* (reg8 *) LC2__SIO_CFG)
    #define LC2_SIO_DIFF           (* (reg8 *) LC2__SIO_DIFF)
#endif /* (LC2__SIO_CFG) */

/* Interrupt Registers */
#if defined(LC2__INTSTAT)
    #define LC2_INTSTAT            (* (reg8 *) LC2__INTSTAT)
    #define LC2_SNAP               (* (reg8 *) LC2__SNAP)
    
	#define LC2_0_INTTYPE_REG 		(* (reg8 *) LC2__0__INTTYPE)
#endif /* (LC2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LC2_H */


/* [] END OF FILE */
