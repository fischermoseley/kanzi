/*******************************************************************************
* File Name: HA2.h  
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

#if !defined(CY_PINS_HA2_H) /* Pins HA2_H */
#define CY_PINS_HA2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HA2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HA2__PORT == 15 && ((HA2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HA2_Write(uint8 value);
void    HA2_SetDriveMode(uint8 mode);
uint8   HA2_ReadDataReg(void);
uint8   HA2_Read(void);
void    HA2_SetInterruptMode(uint16 position, uint16 mode);
uint8   HA2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HA2_SetDriveMode() function.
     *  @{
     */
        #define HA2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HA2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HA2_DM_RES_UP          PIN_DM_RES_UP
        #define HA2_DM_RES_DWN         PIN_DM_RES_DWN
        #define HA2_DM_OD_LO           PIN_DM_OD_LO
        #define HA2_DM_OD_HI           PIN_DM_OD_HI
        #define HA2_DM_STRONG          PIN_DM_STRONG
        #define HA2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HA2_MASK               HA2__MASK
#define HA2_SHIFT              HA2__SHIFT
#define HA2_WIDTH              1u

/* Interrupt constants */
#if defined(HA2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HA2_SetInterruptMode() function.
     *  @{
     */
        #define HA2_INTR_NONE      (uint16)(0x0000u)
        #define HA2_INTR_RISING    (uint16)(0x0001u)
        #define HA2_INTR_FALLING   (uint16)(0x0002u)
        #define HA2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HA2_INTR_MASK      (0x01u) 
#endif /* (HA2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HA2_PS                     (* (reg8 *) HA2__PS)
/* Data Register */
#define HA2_DR                     (* (reg8 *) HA2__DR)
/* Port Number */
#define HA2_PRT_NUM                (* (reg8 *) HA2__PRT) 
/* Connect to Analog Globals */                                                  
#define HA2_AG                     (* (reg8 *) HA2__AG)                       
/* Analog MUX bux enable */
#define HA2_AMUX                   (* (reg8 *) HA2__AMUX) 
/* Bidirectional Enable */                                                        
#define HA2_BIE                    (* (reg8 *) HA2__BIE)
/* Bit-mask for Aliased Register Access */
#define HA2_BIT_MASK               (* (reg8 *) HA2__BIT_MASK)
/* Bypass Enable */
#define HA2_BYP                    (* (reg8 *) HA2__BYP)
/* Port wide control signals */                                                   
#define HA2_CTL                    (* (reg8 *) HA2__CTL)
/* Drive Modes */
#define HA2_DM0                    (* (reg8 *) HA2__DM0) 
#define HA2_DM1                    (* (reg8 *) HA2__DM1)
#define HA2_DM2                    (* (reg8 *) HA2__DM2) 
/* Input Buffer Disable Override */
#define HA2_INP_DIS                (* (reg8 *) HA2__INP_DIS)
/* LCD Common or Segment Drive */
#define HA2_LCD_COM_SEG            (* (reg8 *) HA2__LCD_COM_SEG)
/* Enable Segment LCD */
#define HA2_LCD_EN                 (* (reg8 *) HA2__LCD_EN)
/* Slew Rate Control */
#define HA2_SLW                    (* (reg8 *) HA2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HA2_PRTDSI__CAPS_SEL       (* (reg8 *) HA2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HA2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HA2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HA2_PRTDSI__OE_SEL0        (* (reg8 *) HA2__PRTDSI__OE_SEL0) 
#define HA2_PRTDSI__OE_SEL1        (* (reg8 *) HA2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HA2_PRTDSI__OUT_SEL0       (* (reg8 *) HA2__PRTDSI__OUT_SEL0) 
#define HA2_PRTDSI__OUT_SEL1       (* (reg8 *) HA2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HA2_PRTDSI__SYNC_OUT       (* (reg8 *) HA2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HA2__SIO_CFG)
    #define HA2_SIO_HYST_EN        (* (reg8 *) HA2__SIO_HYST_EN)
    #define HA2_SIO_REG_HIFREQ     (* (reg8 *) HA2__SIO_REG_HIFREQ)
    #define HA2_SIO_CFG            (* (reg8 *) HA2__SIO_CFG)
    #define HA2_SIO_DIFF           (* (reg8 *) HA2__SIO_DIFF)
#endif /* (HA2__SIO_CFG) */

/* Interrupt Registers */
#if defined(HA2__INTSTAT)
    #define HA2_INTSTAT            (* (reg8 *) HA2__INTSTAT)
    #define HA2_SNAP               (* (reg8 *) HA2__SNAP)
    
	#define HA2_0_INTTYPE_REG 		(* (reg8 *) HA2__0__INTTYPE)
#endif /* (HA2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HA2_H */


/* [] END OF FILE */
