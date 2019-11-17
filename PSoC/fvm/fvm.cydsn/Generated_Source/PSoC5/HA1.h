/*******************************************************************************
* File Name: HA1.h  
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

#if !defined(CY_PINS_HA1_H) /* Pins HA1_H */
#define CY_PINS_HA1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HA1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HA1__PORT == 15 && ((HA1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HA1_Write(uint8 value);
void    HA1_SetDriveMode(uint8 mode);
uint8   HA1_ReadDataReg(void);
uint8   HA1_Read(void);
void    HA1_SetInterruptMode(uint16 position, uint16 mode);
uint8   HA1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HA1_SetDriveMode() function.
     *  @{
     */
        #define HA1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HA1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HA1_DM_RES_UP          PIN_DM_RES_UP
        #define HA1_DM_RES_DWN         PIN_DM_RES_DWN
        #define HA1_DM_OD_LO           PIN_DM_OD_LO
        #define HA1_DM_OD_HI           PIN_DM_OD_HI
        #define HA1_DM_STRONG          PIN_DM_STRONG
        #define HA1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HA1_MASK               HA1__MASK
#define HA1_SHIFT              HA1__SHIFT
#define HA1_WIDTH              1u

/* Interrupt constants */
#if defined(HA1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HA1_SetInterruptMode() function.
     *  @{
     */
        #define HA1_INTR_NONE      (uint16)(0x0000u)
        #define HA1_INTR_RISING    (uint16)(0x0001u)
        #define HA1_INTR_FALLING   (uint16)(0x0002u)
        #define HA1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HA1_INTR_MASK      (0x01u) 
#endif /* (HA1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HA1_PS                     (* (reg8 *) HA1__PS)
/* Data Register */
#define HA1_DR                     (* (reg8 *) HA1__DR)
/* Port Number */
#define HA1_PRT_NUM                (* (reg8 *) HA1__PRT) 
/* Connect to Analog Globals */                                                  
#define HA1_AG                     (* (reg8 *) HA1__AG)                       
/* Analog MUX bux enable */
#define HA1_AMUX                   (* (reg8 *) HA1__AMUX) 
/* Bidirectional Enable */                                                        
#define HA1_BIE                    (* (reg8 *) HA1__BIE)
/* Bit-mask for Aliased Register Access */
#define HA1_BIT_MASK               (* (reg8 *) HA1__BIT_MASK)
/* Bypass Enable */
#define HA1_BYP                    (* (reg8 *) HA1__BYP)
/* Port wide control signals */                                                   
#define HA1_CTL                    (* (reg8 *) HA1__CTL)
/* Drive Modes */
#define HA1_DM0                    (* (reg8 *) HA1__DM0) 
#define HA1_DM1                    (* (reg8 *) HA1__DM1)
#define HA1_DM2                    (* (reg8 *) HA1__DM2) 
/* Input Buffer Disable Override */
#define HA1_INP_DIS                (* (reg8 *) HA1__INP_DIS)
/* LCD Common or Segment Drive */
#define HA1_LCD_COM_SEG            (* (reg8 *) HA1__LCD_COM_SEG)
/* Enable Segment LCD */
#define HA1_LCD_EN                 (* (reg8 *) HA1__LCD_EN)
/* Slew Rate Control */
#define HA1_SLW                    (* (reg8 *) HA1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HA1_PRTDSI__CAPS_SEL       (* (reg8 *) HA1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HA1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HA1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HA1_PRTDSI__OE_SEL0        (* (reg8 *) HA1__PRTDSI__OE_SEL0) 
#define HA1_PRTDSI__OE_SEL1        (* (reg8 *) HA1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HA1_PRTDSI__OUT_SEL0       (* (reg8 *) HA1__PRTDSI__OUT_SEL0) 
#define HA1_PRTDSI__OUT_SEL1       (* (reg8 *) HA1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HA1_PRTDSI__SYNC_OUT       (* (reg8 *) HA1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HA1__SIO_CFG)
    #define HA1_SIO_HYST_EN        (* (reg8 *) HA1__SIO_HYST_EN)
    #define HA1_SIO_REG_HIFREQ     (* (reg8 *) HA1__SIO_REG_HIFREQ)
    #define HA1_SIO_CFG            (* (reg8 *) HA1__SIO_CFG)
    #define HA1_SIO_DIFF           (* (reg8 *) HA1__SIO_DIFF)
#endif /* (HA1__SIO_CFG) */

/* Interrupt Registers */
#if defined(HA1__INTSTAT)
    #define HA1_INTSTAT            (* (reg8 *) HA1__INTSTAT)
    #define HA1_SNAP               (* (reg8 *) HA1__SNAP)
    
	#define HA1_0_INTTYPE_REG 		(* (reg8 *) HA1__0__INTTYPE)
#endif /* (HA1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HA1_H */


/* [] END OF FILE */
