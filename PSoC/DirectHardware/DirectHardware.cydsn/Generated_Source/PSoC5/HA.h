/*******************************************************************************
* File Name: HA.h  
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

#if !defined(CY_PINS_HA_H) /* Pins HA_H */
#define CY_PINS_HA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HA__PORT == 15 && ((HA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HA_Write(uint8 value);
void    HA_SetDriveMode(uint8 mode);
uint8   HA_ReadDataReg(void);
uint8   HA_Read(void);
void    HA_SetInterruptMode(uint16 position, uint16 mode);
uint8   HA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HA_SetDriveMode() function.
     *  @{
     */
        #define HA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HA_DM_RES_UP          PIN_DM_RES_UP
        #define HA_DM_RES_DWN         PIN_DM_RES_DWN
        #define HA_DM_OD_LO           PIN_DM_OD_LO
        #define HA_DM_OD_HI           PIN_DM_OD_HI
        #define HA_DM_STRONG          PIN_DM_STRONG
        #define HA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HA_MASK               HA__MASK
#define HA_SHIFT              HA__SHIFT
#define HA_WIDTH              1u

/* Interrupt constants */
#if defined(HA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HA_SetInterruptMode() function.
     *  @{
     */
        #define HA_INTR_NONE      (uint16)(0x0000u)
        #define HA_INTR_RISING    (uint16)(0x0001u)
        #define HA_INTR_FALLING   (uint16)(0x0002u)
        #define HA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HA_INTR_MASK      (0x01u) 
#endif /* (HA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HA_PS                     (* (reg8 *) HA__PS)
/* Data Register */
#define HA_DR                     (* (reg8 *) HA__DR)
/* Port Number */
#define HA_PRT_NUM                (* (reg8 *) HA__PRT) 
/* Connect to Analog Globals */                                                  
#define HA_AG                     (* (reg8 *) HA__AG)                       
/* Analog MUX bux enable */
#define HA_AMUX                   (* (reg8 *) HA__AMUX) 
/* Bidirectional Enable */                                                        
#define HA_BIE                    (* (reg8 *) HA__BIE)
/* Bit-mask for Aliased Register Access */
#define HA_BIT_MASK               (* (reg8 *) HA__BIT_MASK)
/* Bypass Enable */
#define HA_BYP                    (* (reg8 *) HA__BYP)
/* Port wide control signals */                                                   
#define HA_CTL                    (* (reg8 *) HA__CTL)
/* Drive Modes */
#define HA_DM0                    (* (reg8 *) HA__DM0) 
#define HA_DM1                    (* (reg8 *) HA__DM1)
#define HA_DM2                    (* (reg8 *) HA__DM2) 
/* Input Buffer Disable Override */
#define HA_INP_DIS                (* (reg8 *) HA__INP_DIS)
/* LCD Common or Segment Drive */
#define HA_LCD_COM_SEG            (* (reg8 *) HA__LCD_COM_SEG)
/* Enable Segment LCD */
#define HA_LCD_EN                 (* (reg8 *) HA__LCD_EN)
/* Slew Rate Control */
#define HA_SLW                    (* (reg8 *) HA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HA_PRTDSI__CAPS_SEL       (* (reg8 *) HA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HA_PRTDSI__OE_SEL0        (* (reg8 *) HA__PRTDSI__OE_SEL0) 
#define HA_PRTDSI__OE_SEL1        (* (reg8 *) HA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HA_PRTDSI__OUT_SEL0       (* (reg8 *) HA__PRTDSI__OUT_SEL0) 
#define HA_PRTDSI__OUT_SEL1       (* (reg8 *) HA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HA_PRTDSI__SYNC_OUT       (* (reg8 *) HA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HA__SIO_CFG)
    #define HA_SIO_HYST_EN        (* (reg8 *) HA__SIO_HYST_EN)
    #define HA_SIO_REG_HIFREQ     (* (reg8 *) HA__SIO_REG_HIFREQ)
    #define HA_SIO_CFG            (* (reg8 *) HA__SIO_CFG)
    #define HA_SIO_DIFF           (* (reg8 *) HA__SIO_DIFF)
#endif /* (HA__SIO_CFG) */

/* Interrupt Registers */
#if defined(HA__INTSTAT)
    #define HA_INTSTAT            (* (reg8 *) HA__INTSTAT)
    #define HA_SNAP               (* (reg8 *) HA__SNAP)
    
	#define HA_0_INTTYPE_REG 		(* (reg8 *) HA__0__INTTYPE)
#endif /* (HA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HA_H */


/* [] END OF FILE */
