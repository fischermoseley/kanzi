/*******************************************************************************
* File Name: HC.h  
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

#if !defined(CY_PINS_HC_H) /* Pins HC_H */
#define CY_PINS_HC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HC__PORT == 15 && ((HC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HC_Write(uint8 value);
void    HC_SetDriveMode(uint8 mode);
uint8   HC_ReadDataReg(void);
uint8   HC_Read(void);
void    HC_SetInterruptMode(uint16 position, uint16 mode);
uint8   HC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HC_SetDriveMode() function.
     *  @{
     */
        #define HC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HC_DM_RES_UP          PIN_DM_RES_UP
        #define HC_DM_RES_DWN         PIN_DM_RES_DWN
        #define HC_DM_OD_LO           PIN_DM_OD_LO
        #define HC_DM_OD_HI           PIN_DM_OD_HI
        #define HC_DM_STRONG          PIN_DM_STRONG
        #define HC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HC_MASK               HC__MASK
#define HC_SHIFT              HC__SHIFT
#define HC_WIDTH              1u

/* Interrupt constants */
#if defined(HC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HC_SetInterruptMode() function.
     *  @{
     */
        #define HC_INTR_NONE      (uint16)(0x0000u)
        #define HC_INTR_RISING    (uint16)(0x0001u)
        #define HC_INTR_FALLING   (uint16)(0x0002u)
        #define HC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HC_INTR_MASK      (0x01u) 
#endif /* (HC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HC_PS                     (* (reg8 *) HC__PS)
/* Data Register */
#define HC_DR                     (* (reg8 *) HC__DR)
/* Port Number */
#define HC_PRT_NUM                (* (reg8 *) HC__PRT) 
/* Connect to Analog Globals */                                                  
#define HC_AG                     (* (reg8 *) HC__AG)                       
/* Analog MUX bux enable */
#define HC_AMUX                   (* (reg8 *) HC__AMUX) 
/* Bidirectional Enable */                                                        
#define HC_BIE                    (* (reg8 *) HC__BIE)
/* Bit-mask for Aliased Register Access */
#define HC_BIT_MASK               (* (reg8 *) HC__BIT_MASK)
/* Bypass Enable */
#define HC_BYP                    (* (reg8 *) HC__BYP)
/* Port wide control signals */                                                   
#define HC_CTL                    (* (reg8 *) HC__CTL)
/* Drive Modes */
#define HC_DM0                    (* (reg8 *) HC__DM0) 
#define HC_DM1                    (* (reg8 *) HC__DM1)
#define HC_DM2                    (* (reg8 *) HC__DM2) 
/* Input Buffer Disable Override */
#define HC_INP_DIS                (* (reg8 *) HC__INP_DIS)
/* LCD Common or Segment Drive */
#define HC_LCD_COM_SEG            (* (reg8 *) HC__LCD_COM_SEG)
/* Enable Segment LCD */
#define HC_LCD_EN                 (* (reg8 *) HC__LCD_EN)
/* Slew Rate Control */
#define HC_SLW                    (* (reg8 *) HC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HC_PRTDSI__CAPS_SEL       (* (reg8 *) HC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HC_PRTDSI__OE_SEL0        (* (reg8 *) HC__PRTDSI__OE_SEL0) 
#define HC_PRTDSI__OE_SEL1        (* (reg8 *) HC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HC_PRTDSI__OUT_SEL0       (* (reg8 *) HC__PRTDSI__OUT_SEL0) 
#define HC_PRTDSI__OUT_SEL1       (* (reg8 *) HC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HC_PRTDSI__SYNC_OUT       (* (reg8 *) HC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HC__SIO_CFG)
    #define HC_SIO_HYST_EN        (* (reg8 *) HC__SIO_HYST_EN)
    #define HC_SIO_REG_HIFREQ     (* (reg8 *) HC__SIO_REG_HIFREQ)
    #define HC_SIO_CFG            (* (reg8 *) HC__SIO_CFG)
    #define HC_SIO_DIFF           (* (reg8 *) HC__SIO_DIFF)
#endif /* (HC__SIO_CFG) */

/* Interrupt Registers */
#if defined(HC__INTSTAT)
    #define HC_INTSTAT            (* (reg8 *) HC__INTSTAT)
    #define HC_SNAP               (* (reg8 *) HC__SNAP)
    
	#define HC_0_INTTYPE_REG 		(* (reg8 *) HC__0__INTTYPE)
#endif /* (HC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HC_H */


/* [] END OF FILE */
