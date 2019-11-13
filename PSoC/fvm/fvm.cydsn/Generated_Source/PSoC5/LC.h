/*******************************************************************************
* File Name: LC.h  
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

#if !defined(CY_PINS_LC_H) /* Pins LC_H */
#define CY_PINS_LC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LC__PORT == 15 && ((LC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LC_Write(uint8 value);
void    LC_SetDriveMode(uint8 mode);
uint8   LC_ReadDataReg(void);
uint8   LC_Read(void);
void    LC_SetInterruptMode(uint16 position, uint16 mode);
uint8   LC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LC_SetDriveMode() function.
     *  @{
     */
        #define LC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LC_DM_RES_UP          PIN_DM_RES_UP
        #define LC_DM_RES_DWN         PIN_DM_RES_DWN
        #define LC_DM_OD_LO           PIN_DM_OD_LO
        #define LC_DM_OD_HI           PIN_DM_OD_HI
        #define LC_DM_STRONG          PIN_DM_STRONG
        #define LC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LC_MASK               LC__MASK
#define LC_SHIFT              LC__SHIFT
#define LC_WIDTH              1u

/* Interrupt constants */
#if defined(LC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LC_SetInterruptMode() function.
     *  @{
     */
        #define LC_INTR_NONE      (uint16)(0x0000u)
        #define LC_INTR_RISING    (uint16)(0x0001u)
        #define LC_INTR_FALLING   (uint16)(0x0002u)
        #define LC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LC_INTR_MASK      (0x01u) 
#endif /* (LC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LC_PS                     (* (reg8 *) LC__PS)
/* Data Register */
#define LC_DR                     (* (reg8 *) LC__DR)
/* Port Number */
#define LC_PRT_NUM                (* (reg8 *) LC__PRT) 
/* Connect to Analog Globals */                                                  
#define LC_AG                     (* (reg8 *) LC__AG)                       
/* Analog MUX bux enable */
#define LC_AMUX                   (* (reg8 *) LC__AMUX) 
/* Bidirectional Enable */                                                        
#define LC_BIE                    (* (reg8 *) LC__BIE)
/* Bit-mask for Aliased Register Access */
#define LC_BIT_MASK               (* (reg8 *) LC__BIT_MASK)
/* Bypass Enable */
#define LC_BYP                    (* (reg8 *) LC__BYP)
/* Port wide control signals */                                                   
#define LC_CTL                    (* (reg8 *) LC__CTL)
/* Drive Modes */
#define LC_DM0                    (* (reg8 *) LC__DM0) 
#define LC_DM1                    (* (reg8 *) LC__DM1)
#define LC_DM2                    (* (reg8 *) LC__DM2) 
/* Input Buffer Disable Override */
#define LC_INP_DIS                (* (reg8 *) LC__INP_DIS)
/* LCD Common or Segment Drive */
#define LC_LCD_COM_SEG            (* (reg8 *) LC__LCD_COM_SEG)
/* Enable Segment LCD */
#define LC_LCD_EN                 (* (reg8 *) LC__LCD_EN)
/* Slew Rate Control */
#define LC_SLW                    (* (reg8 *) LC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LC_PRTDSI__CAPS_SEL       (* (reg8 *) LC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LC_PRTDSI__OE_SEL0        (* (reg8 *) LC__PRTDSI__OE_SEL0) 
#define LC_PRTDSI__OE_SEL1        (* (reg8 *) LC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LC_PRTDSI__OUT_SEL0       (* (reg8 *) LC__PRTDSI__OUT_SEL0) 
#define LC_PRTDSI__OUT_SEL1       (* (reg8 *) LC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LC_PRTDSI__SYNC_OUT       (* (reg8 *) LC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LC__SIO_CFG)
    #define LC_SIO_HYST_EN        (* (reg8 *) LC__SIO_HYST_EN)
    #define LC_SIO_REG_HIFREQ     (* (reg8 *) LC__SIO_REG_HIFREQ)
    #define LC_SIO_CFG            (* (reg8 *) LC__SIO_CFG)
    #define LC_SIO_DIFF           (* (reg8 *) LC__SIO_DIFF)
#endif /* (LC__SIO_CFG) */

/* Interrupt Registers */
#if defined(LC__INTSTAT)
    #define LC_INTSTAT            (* (reg8 *) LC__INTSTAT)
    #define LC_SNAP               (* (reg8 *) LC__SNAP)
    
	#define LC_0_INTTYPE_REG 		(* (reg8 *) LC__0__INTTYPE)
#endif /* (LC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LC_H */


/* [] END OF FILE */
