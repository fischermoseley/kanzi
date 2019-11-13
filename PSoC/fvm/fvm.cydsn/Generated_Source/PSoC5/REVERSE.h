/*******************************************************************************
* File Name: REVERSE.h  
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

#if !defined(CY_PINS_REVERSE_H) /* Pins REVERSE_H */
#define CY_PINS_REVERSE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "REVERSE_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 REVERSE__PORT == 15 && ((REVERSE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    REVERSE_Write(uint8 value);
void    REVERSE_SetDriveMode(uint8 mode);
uint8   REVERSE_ReadDataReg(void);
uint8   REVERSE_Read(void);
void    REVERSE_SetInterruptMode(uint16 position, uint16 mode);
uint8   REVERSE_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the REVERSE_SetDriveMode() function.
     *  @{
     */
        #define REVERSE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define REVERSE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define REVERSE_DM_RES_UP          PIN_DM_RES_UP
        #define REVERSE_DM_RES_DWN         PIN_DM_RES_DWN
        #define REVERSE_DM_OD_LO           PIN_DM_OD_LO
        #define REVERSE_DM_OD_HI           PIN_DM_OD_HI
        #define REVERSE_DM_STRONG          PIN_DM_STRONG
        #define REVERSE_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define REVERSE_MASK               REVERSE__MASK
#define REVERSE_SHIFT              REVERSE__SHIFT
#define REVERSE_WIDTH              1u

/* Interrupt constants */
#if defined(REVERSE__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in REVERSE_SetInterruptMode() function.
     *  @{
     */
        #define REVERSE_INTR_NONE      (uint16)(0x0000u)
        #define REVERSE_INTR_RISING    (uint16)(0x0001u)
        #define REVERSE_INTR_FALLING   (uint16)(0x0002u)
        #define REVERSE_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define REVERSE_INTR_MASK      (0x01u) 
#endif /* (REVERSE__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define REVERSE_PS                     (* (reg8 *) REVERSE__PS)
/* Data Register */
#define REVERSE_DR                     (* (reg8 *) REVERSE__DR)
/* Port Number */
#define REVERSE_PRT_NUM                (* (reg8 *) REVERSE__PRT) 
/* Connect to Analog Globals */                                                  
#define REVERSE_AG                     (* (reg8 *) REVERSE__AG)                       
/* Analog MUX bux enable */
#define REVERSE_AMUX                   (* (reg8 *) REVERSE__AMUX) 
/* Bidirectional Enable */                                                        
#define REVERSE_BIE                    (* (reg8 *) REVERSE__BIE)
/* Bit-mask for Aliased Register Access */
#define REVERSE_BIT_MASK               (* (reg8 *) REVERSE__BIT_MASK)
/* Bypass Enable */
#define REVERSE_BYP                    (* (reg8 *) REVERSE__BYP)
/* Port wide control signals */                                                   
#define REVERSE_CTL                    (* (reg8 *) REVERSE__CTL)
/* Drive Modes */
#define REVERSE_DM0                    (* (reg8 *) REVERSE__DM0) 
#define REVERSE_DM1                    (* (reg8 *) REVERSE__DM1)
#define REVERSE_DM2                    (* (reg8 *) REVERSE__DM2) 
/* Input Buffer Disable Override */
#define REVERSE_INP_DIS                (* (reg8 *) REVERSE__INP_DIS)
/* LCD Common or Segment Drive */
#define REVERSE_LCD_COM_SEG            (* (reg8 *) REVERSE__LCD_COM_SEG)
/* Enable Segment LCD */
#define REVERSE_LCD_EN                 (* (reg8 *) REVERSE__LCD_EN)
/* Slew Rate Control */
#define REVERSE_SLW                    (* (reg8 *) REVERSE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define REVERSE_PRTDSI__CAPS_SEL       (* (reg8 *) REVERSE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define REVERSE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) REVERSE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define REVERSE_PRTDSI__OE_SEL0        (* (reg8 *) REVERSE__PRTDSI__OE_SEL0) 
#define REVERSE_PRTDSI__OE_SEL1        (* (reg8 *) REVERSE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define REVERSE_PRTDSI__OUT_SEL0       (* (reg8 *) REVERSE__PRTDSI__OUT_SEL0) 
#define REVERSE_PRTDSI__OUT_SEL1       (* (reg8 *) REVERSE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define REVERSE_PRTDSI__SYNC_OUT       (* (reg8 *) REVERSE__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(REVERSE__SIO_CFG)
    #define REVERSE_SIO_HYST_EN        (* (reg8 *) REVERSE__SIO_HYST_EN)
    #define REVERSE_SIO_REG_HIFREQ     (* (reg8 *) REVERSE__SIO_REG_HIFREQ)
    #define REVERSE_SIO_CFG            (* (reg8 *) REVERSE__SIO_CFG)
    #define REVERSE_SIO_DIFF           (* (reg8 *) REVERSE__SIO_DIFF)
#endif /* (REVERSE__SIO_CFG) */

/* Interrupt Registers */
#if defined(REVERSE__INTSTAT)
    #define REVERSE_INTSTAT            (* (reg8 *) REVERSE__INTSTAT)
    #define REVERSE_SNAP               (* (reg8 *) REVERSE__SNAP)
    
	#define REVERSE_0_INTTYPE_REG 		(* (reg8 *) REVERSE__0__INTTYPE)
#endif /* (REVERSE__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_REVERSE_H */


/* [] END OF FILE */
