/*******************************************************************************
* File Name: REVERSE1.h  
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

#if !defined(CY_PINS_REVERSE1_H) /* Pins REVERSE1_H */
#define CY_PINS_REVERSE1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "REVERSE1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 REVERSE1__PORT == 15 && ((REVERSE1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    REVERSE1_Write(uint8 value);
void    REVERSE1_SetDriveMode(uint8 mode);
uint8   REVERSE1_ReadDataReg(void);
uint8   REVERSE1_Read(void);
void    REVERSE1_SetInterruptMode(uint16 position, uint16 mode);
uint8   REVERSE1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the REVERSE1_SetDriveMode() function.
     *  @{
     */
        #define REVERSE1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define REVERSE1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define REVERSE1_DM_RES_UP          PIN_DM_RES_UP
        #define REVERSE1_DM_RES_DWN         PIN_DM_RES_DWN
        #define REVERSE1_DM_OD_LO           PIN_DM_OD_LO
        #define REVERSE1_DM_OD_HI           PIN_DM_OD_HI
        #define REVERSE1_DM_STRONG          PIN_DM_STRONG
        #define REVERSE1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define REVERSE1_MASK               REVERSE1__MASK
#define REVERSE1_SHIFT              REVERSE1__SHIFT
#define REVERSE1_WIDTH              1u

/* Interrupt constants */
#if defined(REVERSE1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in REVERSE1_SetInterruptMode() function.
     *  @{
     */
        #define REVERSE1_INTR_NONE      (uint16)(0x0000u)
        #define REVERSE1_INTR_RISING    (uint16)(0x0001u)
        #define REVERSE1_INTR_FALLING   (uint16)(0x0002u)
        #define REVERSE1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define REVERSE1_INTR_MASK      (0x01u) 
#endif /* (REVERSE1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define REVERSE1_PS                     (* (reg8 *) REVERSE1__PS)
/* Data Register */
#define REVERSE1_DR                     (* (reg8 *) REVERSE1__DR)
/* Port Number */
#define REVERSE1_PRT_NUM                (* (reg8 *) REVERSE1__PRT) 
/* Connect to Analog Globals */                                                  
#define REVERSE1_AG                     (* (reg8 *) REVERSE1__AG)                       
/* Analog MUX bux enable */
#define REVERSE1_AMUX                   (* (reg8 *) REVERSE1__AMUX) 
/* Bidirectional Enable */                                                        
#define REVERSE1_BIE                    (* (reg8 *) REVERSE1__BIE)
/* Bit-mask for Aliased Register Access */
#define REVERSE1_BIT_MASK               (* (reg8 *) REVERSE1__BIT_MASK)
/* Bypass Enable */
#define REVERSE1_BYP                    (* (reg8 *) REVERSE1__BYP)
/* Port wide control signals */                                                   
#define REVERSE1_CTL                    (* (reg8 *) REVERSE1__CTL)
/* Drive Modes */
#define REVERSE1_DM0                    (* (reg8 *) REVERSE1__DM0) 
#define REVERSE1_DM1                    (* (reg8 *) REVERSE1__DM1)
#define REVERSE1_DM2                    (* (reg8 *) REVERSE1__DM2) 
/* Input Buffer Disable Override */
#define REVERSE1_INP_DIS                (* (reg8 *) REVERSE1__INP_DIS)
/* LCD Common or Segment Drive */
#define REVERSE1_LCD_COM_SEG            (* (reg8 *) REVERSE1__LCD_COM_SEG)
/* Enable Segment LCD */
#define REVERSE1_LCD_EN                 (* (reg8 *) REVERSE1__LCD_EN)
/* Slew Rate Control */
#define REVERSE1_SLW                    (* (reg8 *) REVERSE1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define REVERSE1_PRTDSI__CAPS_SEL       (* (reg8 *) REVERSE1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define REVERSE1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) REVERSE1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define REVERSE1_PRTDSI__OE_SEL0        (* (reg8 *) REVERSE1__PRTDSI__OE_SEL0) 
#define REVERSE1_PRTDSI__OE_SEL1        (* (reg8 *) REVERSE1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define REVERSE1_PRTDSI__OUT_SEL0       (* (reg8 *) REVERSE1__PRTDSI__OUT_SEL0) 
#define REVERSE1_PRTDSI__OUT_SEL1       (* (reg8 *) REVERSE1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define REVERSE1_PRTDSI__SYNC_OUT       (* (reg8 *) REVERSE1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(REVERSE1__SIO_CFG)
    #define REVERSE1_SIO_HYST_EN        (* (reg8 *) REVERSE1__SIO_HYST_EN)
    #define REVERSE1_SIO_REG_HIFREQ     (* (reg8 *) REVERSE1__SIO_REG_HIFREQ)
    #define REVERSE1_SIO_CFG            (* (reg8 *) REVERSE1__SIO_CFG)
    #define REVERSE1_SIO_DIFF           (* (reg8 *) REVERSE1__SIO_DIFF)
#endif /* (REVERSE1__SIO_CFG) */

/* Interrupt Registers */
#if defined(REVERSE1__INTSTAT)
    #define REVERSE1_INTSTAT            (* (reg8 *) REVERSE1__INTSTAT)
    #define REVERSE1_SNAP               (* (reg8 *) REVERSE1__SNAP)
    
	#define REVERSE1_0_INTTYPE_REG 		(* (reg8 *) REVERSE1__0__INTTYPE)
#endif /* (REVERSE1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_REVERSE1_H */


/* [] END OF FILE */
