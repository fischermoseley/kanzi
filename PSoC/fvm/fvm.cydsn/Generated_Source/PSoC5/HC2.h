/*******************************************************************************
* File Name: HC2.h  
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

#if !defined(CY_PINS_HC2_H) /* Pins HC2_H */
#define CY_PINS_HC2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HC2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HC2__PORT == 15 && ((HC2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HC2_Write(uint8 value);
void    HC2_SetDriveMode(uint8 mode);
uint8   HC2_ReadDataReg(void);
uint8   HC2_Read(void);
void    HC2_SetInterruptMode(uint16 position, uint16 mode);
uint8   HC2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HC2_SetDriveMode() function.
     *  @{
     */
        #define HC2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HC2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HC2_DM_RES_UP          PIN_DM_RES_UP
        #define HC2_DM_RES_DWN         PIN_DM_RES_DWN
        #define HC2_DM_OD_LO           PIN_DM_OD_LO
        #define HC2_DM_OD_HI           PIN_DM_OD_HI
        #define HC2_DM_STRONG          PIN_DM_STRONG
        #define HC2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HC2_MASK               HC2__MASK
#define HC2_SHIFT              HC2__SHIFT
#define HC2_WIDTH              1u

/* Interrupt constants */
#if defined(HC2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HC2_SetInterruptMode() function.
     *  @{
     */
        #define HC2_INTR_NONE      (uint16)(0x0000u)
        #define HC2_INTR_RISING    (uint16)(0x0001u)
        #define HC2_INTR_FALLING   (uint16)(0x0002u)
        #define HC2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HC2_INTR_MASK      (0x01u) 
#endif /* (HC2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HC2_PS                     (* (reg8 *) HC2__PS)
/* Data Register */
#define HC2_DR                     (* (reg8 *) HC2__DR)
/* Port Number */
#define HC2_PRT_NUM                (* (reg8 *) HC2__PRT) 
/* Connect to Analog Globals */                                                  
#define HC2_AG                     (* (reg8 *) HC2__AG)                       
/* Analog MUX bux enable */
#define HC2_AMUX                   (* (reg8 *) HC2__AMUX) 
/* Bidirectional Enable */                                                        
#define HC2_BIE                    (* (reg8 *) HC2__BIE)
/* Bit-mask for Aliased Register Access */
#define HC2_BIT_MASK               (* (reg8 *) HC2__BIT_MASK)
/* Bypass Enable */
#define HC2_BYP                    (* (reg8 *) HC2__BYP)
/* Port wide control signals */                                                   
#define HC2_CTL                    (* (reg8 *) HC2__CTL)
/* Drive Modes */
#define HC2_DM0                    (* (reg8 *) HC2__DM0) 
#define HC2_DM1                    (* (reg8 *) HC2__DM1)
#define HC2_DM2                    (* (reg8 *) HC2__DM2) 
/* Input Buffer Disable Override */
#define HC2_INP_DIS                (* (reg8 *) HC2__INP_DIS)
/* LCD Common or Segment Drive */
#define HC2_LCD_COM_SEG            (* (reg8 *) HC2__LCD_COM_SEG)
/* Enable Segment LCD */
#define HC2_LCD_EN                 (* (reg8 *) HC2__LCD_EN)
/* Slew Rate Control */
#define HC2_SLW                    (* (reg8 *) HC2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HC2_PRTDSI__CAPS_SEL       (* (reg8 *) HC2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HC2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HC2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HC2_PRTDSI__OE_SEL0        (* (reg8 *) HC2__PRTDSI__OE_SEL0) 
#define HC2_PRTDSI__OE_SEL1        (* (reg8 *) HC2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HC2_PRTDSI__OUT_SEL0       (* (reg8 *) HC2__PRTDSI__OUT_SEL0) 
#define HC2_PRTDSI__OUT_SEL1       (* (reg8 *) HC2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HC2_PRTDSI__SYNC_OUT       (* (reg8 *) HC2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HC2__SIO_CFG)
    #define HC2_SIO_HYST_EN        (* (reg8 *) HC2__SIO_HYST_EN)
    #define HC2_SIO_REG_HIFREQ     (* (reg8 *) HC2__SIO_REG_HIFREQ)
    #define HC2_SIO_CFG            (* (reg8 *) HC2__SIO_CFG)
    #define HC2_SIO_DIFF           (* (reg8 *) HC2__SIO_DIFF)
#endif /* (HC2__SIO_CFG) */

/* Interrupt Registers */
#if defined(HC2__INTSTAT)
    #define HC2_INTSTAT            (* (reg8 *) HC2__INTSTAT)
    #define HC2_SNAP               (* (reg8 *) HC2__SNAP)
    
	#define HC2_0_INTTYPE_REG 		(* (reg8 *) HC2__0__INTTYPE)
#endif /* (HC2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HC2_H */


/* [] END OF FILE */
