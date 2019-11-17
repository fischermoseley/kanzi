/*******************************************************************************
* File Name: LA1.h  
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

#if !defined(CY_PINS_LA1_H) /* Pins LA1_H */
#define CY_PINS_LA1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LA1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LA1__PORT == 15 && ((LA1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LA1_Write(uint8 value);
void    LA1_SetDriveMode(uint8 mode);
uint8   LA1_ReadDataReg(void);
uint8   LA1_Read(void);
void    LA1_SetInterruptMode(uint16 position, uint16 mode);
uint8   LA1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LA1_SetDriveMode() function.
     *  @{
     */
        #define LA1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LA1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LA1_DM_RES_UP          PIN_DM_RES_UP
        #define LA1_DM_RES_DWN         PIN_DM_RES_DWN
        #define LA1_DM_OD_LO           PIN_DM_OD_LO
        #define LA1_DM_OD_HI           PIN_DM_OD_HI
        #define LA1_DM_STRONG          PIN_DM_STRONG
        #define LA1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LA1_MASK               LA1__MASK
#define LA1_SHIFT              LA1__SHIFT
#define LA1_WIDTH              1u

/* Interrupt constants */
#if defined(LA1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LA1_SetInterruptMode() function.
     *  @{
     */
        #define LA1_INTR_NONE      (uint16)(0x0000u)
        #define LA1_INTR_RISING    (uint16)(0x0001u)
        #define LA1_INTR_FALLING   (uint16)(0x0002u)
        #define LA1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LA1_INTR_MASK      (0x01u) 
#endif /* (LA1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LA1_PS                     (* (reg8 *) LA1__PS)
/* Data Register */
#define LA1_DR                     (* (reg8 *) LA1__DR)
/* Port Number */
#define LA1_PRT_NUM                (* (reg8 *) LA1__PRT) 
/* Connect to Analog Globals */                                                  
#define LA1_AG                     (* (reg8 *) LA1__AG)                       
/* Analog MUX bux enable */
#define LA1_AMUX                   (* (reg8 *) LA1__AMUX) 
/* Bidirectional Enable */                                                        
#define LA1_BIE                    (* (reg8 *) LA1__BIE)
/* Bit-mask for Aliased Register Access */
#define LA1_BIT_MASK               (* (reg8 *) LA1__BIT_MASK)
/* Bypass Enable */
#define LA1_BYP                    (* (reg8 *) LA1__BYP)
/* Port wide control signals */                                                   
#define LA1_CTL                    (* (reg8 *) LA1__CTL)
/* Drive Modes */
#define LA1_DM0                    (* (reg8 *) LA1__DM0) 
#define LA1_DM1                    (* (reg8 *) LA1__DM1)
#define LA1_DM2                    (* (reg8 *) LA1__DM2) 
/* Input Buffer Disable Override */
#define LA1_INP_DIS                (* (reg8 *) LA1__INP_DIS)
/* LCD Common or Segment Drive */
#define LA1_LCD_COM_SEG            (* (reg8 *) LA1__LCD_COM_SEG)
/* Enable Segment LCD */
#define LA1_LCD_EN                 (* (reg8 *) LA1__LCD_EN)
/* Slew Rate Control */
#define LA1_SLW                    (* (reg8 *) LA1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LA1_PRTDSI__CAPS_SEL       (* (reg8 *) LA1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LA1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LA1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LA1_PRTDSI__OE_SEL0        (* (reg8 *) LA1__PRTDSI__OE_SEL0) 
#define LA1_PRTDSI__OE_SEL1        (* (reg8 *) LA1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LA1_PRTDSI__OUT_SEL0       (* (reg8 *) LA1__PRTDSI__OUT_SEL0) 
#define LA1_PRTDSI__OUT_SEL1       (* (reg8 *) LA1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LA1_PRTDSI__SYNC_OUT       (* (reg8 *) LA1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LA1__SIO_CFG)
    #define LA1_SIO_HYST_EN        (* (reg8 *) LA1__SIO_HYST_EN)
    #define LA1_SIO_REG_HIFREQ     (* (reg8 *) LA1__SIO_REG_HIFREQ)
    #define LA1_SIO_CFG            (* (reg8 *) LA1__SIO_CFG)
    #define LA1_SIO_DIFF           (* (reg8 *) LA1__SIO_DIFF)
#endif /* (LA1__SIO_CFG) */

/* Interrupt Registers */
#if defined(LA1__INTSTAT)
    #define LA1_INTSTAT            (* (reg8 *) LA1__INTSTAT)
    #define LA1_SNAP               (* (reg8 *) LA1__SNAP)
    
	#define LA1_0_INTTYPE_REG 		(* (reg8 *) LA1__0__INTTYPE)
#endif /* (LA1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LA1_H */


/* [] END OF FILE */
