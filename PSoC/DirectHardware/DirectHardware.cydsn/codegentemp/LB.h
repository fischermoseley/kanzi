/*******************************************************************************
* File Name: LB.h  
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

#if !defined(CY_PINS_LB_H) /* Pins LB_H */
#define CY_PINS_LB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LB__PORT == 15 && ((LB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LB_Write(uint8 value);
void    LB_SetDriveMode(uint8 mode);
uint8   LB_ReadDataReg(void);
uint8   LB_Read(void);
void    LB_SetInterruptMode(uint16 position, uint16 mode);
uint8   LB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LB_SetDriveMode() function.
     *  @{
     */
        #define LB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LB_DM_RES_UP          PIN_DM_RES_UP
        #define LB_DM_RES_DWN         PIN_DM_RES_DWN
        #define LB_DM_OD_LO           PIN_DM_OD_LO
        #define LB_DM_OD_HI           PIN_DM_OD_HI
        #define LB_DM_STRONG          PIN_DM_STRONG
        #define LB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LB_MASK               LB__MASK
#define LB_SHIFT              LB__SHIFT
#define LB_WIDTH              1u

/* Interrupt constants */
#if defined(LB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LB_SetInterruptMode() function.
     *  @{
     */
        #define LB_INTR_NONE      (uint16)(0x0000u)
        #define LB_INTR_RISING    (uint16)(0x0001u)
        #define LB_INTR_FALLING   (uint16)(0x0002u)
        #define LB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LB_INTR_MASK      (0x01u) 
#endif /* (LB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LB_PS                     (* (reg8 *) LB__PS)
/* Data Register */
#define LB_DR                     (* (reg8 *) LB__DR)
/* Port Number */
#define LB_PRT_NUM                (* (reg8 *) LB__PRT) 
/* Connect to Analog Globals */                                                  
#define LB_AG                     (* (reg8 *) LB__AG)                       
/* Analog MUX bux enable */
#define LB_AMUX                   (* (reg8 *) LB__AMUX) 
/* Bidirectional Enable */                                                        
#define LB_BIE                    (* (reg8 *) LB__BIE)
/* Bit-mask for Aliased Register Access */
#define LB_BIT_MASK               (* (reg8 *) LB__BIT_MASK)
/* Bypass Enable */
#define LB_BYP                    (* (reg8 *) LB__BYP)
/* Port wide control signals */                                                   
#define LB_CTL                    (* (reg8 *) LB__CTL)
/* Drive Modes */
#define LB_DM0                    (* (reg8 *) LB__DM0) 
#define LB_DM1                    (* (reg8 *) LB__DM1)
#define LB_DM2                    (* (reg8 *) LB__DM2) 
/* Input Buffer Disable Override */
#define LB_INP_DIS                (* (reg8 *) LB__INP_DIS)
/* LCD Common or Segment Drive */
#define LB_LCD_COM_SEG            (* (reg8 *) LB__LCD_COM_SEG)
/* Enable Segment LCD */
#define LB_LCD_EN                 (* (reg8 *) LB__LCD_EN)
/* Slew Rate Control */
#define LB_SLW                    (* (reg8 *) LB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LB_PRTDSI__CAPS_SEL       (* (reg8 *) LB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LB_PRTDSI__OE_SEL0        (* (reg8 *) LB__PRTDSI__OE_SEL0) 
#define LB_PRTDSI__OE_SEL1        (* (reg8 *) LB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LB_PRTDSI__OUT_SEL0       (* (reg8 *) LB__PRTDSI__OUT_SEL0) 
#define LB_PRTDSI__OUT_SEL1       (* (reg8 *) LB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LB_PRTDSI__SYNC_OUT       (* (reg8 *) LB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LB__SIO_CFG)
    #define LB_SIO_HYST_EN        (* (reg8 *) LB__SIO_HYST_EN)
    #define LB_SIO_REG_HIFREQ     (* (reg8 *) LB__SIO_REG_HIFREQ)
    #define LB_SIO_CFG            (* (reg8 *) LB__SIO_CFG)
    #define LB_SIO_DIFF           (* (reg8 *) LB__SIO_DIFF)
#endif /* (LB__SIO_CFG) */

/* Interrupt Registers */
#if defined(LB__INTSTAT)
    #define LB_INTSTAT            (* (reg8 *) LB__INTSTAT)
    #define LB_SNAP               (* (reg8 *) LB__SNAP)
    
	#define LB_0_INTTYPE_REG 		(* (reg8 *) LB__0__INTTYPE)
#endif /* (LB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LB_H */


/* [] END OF FILE */
