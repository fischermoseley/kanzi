/*******************************************************************************
* File Name: LEFT_HA.h  
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

#if !defined(CY_PINS_LEFT_HA_H) /* Pins LEFT_HA_H */
#define CY_PINS_LEFT_HA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LEFT_HA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LEFT_HA__PORT == 15 && ((LEFT_HA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LEFT_HA_Write(uint8 value);
void    LEFT_HA_SetDriveMode(uint8 mode);
uint8   LEFT_HA_ReadDataReg(void);
uint8   LEFT_HA_Read(void);
void    LEFT_HA_SetInterruptMode(uint16 position, uint16 mode);
uint8   LEFT_HA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LEFT_HA_SetDriveMode() function.
     *  @{
     */
        #define LEFT_HA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LEFT_HA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LEFT_HA_DM_RES_UP          PIN_DM_RES_UP
        #define LEFT_HA_DM_RES_DWN         PIN_DM_RES_DWN
        #define LEFT_HA_DM_OD_LO           PIN_DM_OD_LO
        #define LEFT_HA_DM_OD_HI           PIN_DM_OD_HI
        #define LEFT_HA_DM_STRONG          PIN_DM_STRONG
        #define LEFT_HA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LEFT_HA_MASK               LEFT_HA__MASK
#define LEFT_HA_SHIFT              LEFT_HA__SHIFT
#define LEFT_HA_WIDTH              1u

/* Interrupt constants */
#if defined(LEFT_HA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LEFT_HA_SetInterruptMode() function.
     *  @{
     */
        #define LEFT_HA_INTR_NONE      (uint16)(0x0000u)
        #define LEFT_HA_INTR_RISING    (uint16)(0x0001u)
        #define LEFT_HA_INTR_FALLING   (uint16)(0x0002u)
        #define LEFT_HA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LEFT_HA_INTR_MASK      (0x01u) 
#endif /* (LEFT_HA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LEFT_HA_PS                     (* (reg8 *) LEFT_HA__PS)
/* Data Register */
#define LEFT_HA_DR                     (* (reg8 *) LEFT_HA__DR)
/* Port Number */
#define LEFT_HA_PRT_NUM                (* (reg8 *) LEFT_HA__PRT) 
/* Connect to Analog Globals */                                                  
#define LEFT_HA_AG                     (* (reg8 *) LEFT_HA__AG)                       
/* Analog MUX bux enable */
#define LEFT_HA_AMUX                   (* (reg8 *) LEFT_HA__AMUX) 
/* Bidirectional Enable */                                                        
#define LEFT_HA_BIE                    (* (reg8 *) LEFT_HA__BIE)
/* Bit-mask for Aliased Register Access */
#define LEFT_HA_BIT_MASK               (* (reg8 *) LEFT_HA__BIT_MASK)
/* Bypass Enable */
#define LEFT_HA_BYP                    (* (reg8 *) LEFT_HA__BYP)
/* Port wide control signals */                                                   
#define LEFT_HA_CTL                    (* (reg8 *) LEFT_HA__CTL)
/* Drive Modes */
#define LEFT_HA_DM0                    (* (reg8 *) LEFT_HA__DM0) 
#define LEFT_HA_DM1                    (* (reg8 *) LEFT_HA__DM1)
#define LEFT_HA_DM2                    (* (reg8 *) LEFT_HA__DM2) 
/* Input Buffer Disable Override */
#define LEFT_HA_INP_DIS                (* (reg8 *) LEFT_HA__INP_DIS)
/* LCD Common or Segment Drive */
#define LEFT_HA_LCD_COM_SEG            (* (reg8 *) LEFT_HA__LCD_COM_SEG)
/* Enable Segment LCD */
#define LEFT_HA_LCD_EN                 (* (reg8 *) LEFT_HA__LCD_EN)
/* Slew Rate Control */
#define LEFT_HA_SLW                    (* (reg8 *) LEFT_HA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LEFT_HA_PRTDSI__CAPS_SEL       (* (reg8 *) LEFT_HA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LEFT_HA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LEFT_HA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LEFT_HA_PRTDSI__OE_SEL0        (* (reg8 *) LEFT_HA__PRTDSI__OE_SEL0) 
#define LEFT_HA_PRTDSI__OE_SEL1        (* (reg8 *) LEFT_HA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LEFT_HA_PRTDSI__OUT_SEL0       (* (reg8 *) LEFT_HA__PRTDSI__OUT_SEL0) 
#define LEFT_HA_PRTDSI__OUT_SEL1       (* (reg8 *) LEFT_HA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LEFT_HA_PRTDSI__SYNC_OUT       (* (reg8 *) LEFT_HA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LEFT_HA__SIO_CFG)
    #define LEFT_HA_SIO_HYST_EN        (* (reg8 *) LEFT_HA__SIO_HYST_EN)
    #define LEFT_HA_SIO_REG_HIFREQ     (* (reg8 *) LEFT_HA__SIO_REG_HIFREQ)
    #define LEFT_HA_SIO_CFG            (* (reg8 *) LEFT_HA__SIO_CFG)
    #define LEFT_HA_SIO_DIFF           (* (reg8 *) LEFT_HA__SIO_DIFF)
#endif /* (LEFT_HA__SIO_CFG) */

/* Interrupt Registers */
#if defined(LEFT_HA__INTSTAT)
    #define LEFT_HA_INTSTAT            (* (reg8 *) LEFT_HA__INTSTAT)
    #define LEFT_HA_SNAP               (* (reg8 *) LEFT_HA__SNAP)
    
	#define LEFT_HA_0_INTTYPE_REG 		(* (reg8 *) LEFT_HA__0__INTTYPE)
#endif /* (LEFT_HA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LEFT_HA_H */


/* [] END OF FILE */
