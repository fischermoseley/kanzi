/*******************************************************************************
* File Name: HB2.h  
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

#if !defined(CY_PINS_HB2_H) /* Pins HB2_H */
#define CY_PINS_HB2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HB2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HB2__PORT == 15 && ((HB2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HB2_Write(uint8 value);
void    HB2_SetDriveMode(uint8 mode);
uint8   HB2_ReadDataReg(void);
uint8   HB2_Read(void);
void    HB2_SetInterruptMode(uint16 position, uint16 mode);
uint8   HB2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HB2_SetDriveMode() function.
     *  @{
     */
        #define HB2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HB2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HB2_DM_RES_UP          PIN_DM_RES_UP
        #define HB2_DM_RES_DWN         PIN_DM_RES_DWN
        #define HB2_DM_OD_LO           PIN_DM_OD_LO
        #define HB2_DM_OD_HI           PIN_DM_OD_HI
        #define HB2_DM_STRONG          PIN_DM_STRONG
        #define HB2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HB2_MASK               HB2__MASK
#define HB2_SHIFT              HB2__SHIFT
#define HB2_WIDTH              1u

/* Interrupt constants */
#if defined(HB2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HB2_SetInterruptMode() function.
     *  @{
     */
        #define HB2_INTR_NONE      (uint16)(0x0000u)
        #define HB2_INTR_RISING    (uint16)(0x0001u)
        #define HB2_INTR_FALLING   (uint16)(0x0002u)
        #define HB2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HB2_INTR_MASK      (0x01u) 
#endif /* (HB2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HB2_PS                     (* (reg8 *) HB2__PS)
/* Data Register */
#define HB2_DR                     (* (reg8 *) HB2__DR)
/* Port Number */
#define HB2_PRT_NUM                (* (reg8 *) HB2__PRT) 
/* Connect to Analog Globals */                                                  
#define HB2_AG                     (* (reg8 *) HB2__AG)                       
/* Analog MUX bux enable */
#define HB2_AMUX                   (* (reg8 *) HB2__AMUX) 
/* Bidirectional Enable */                                                        
#define HB2_BIE                    (* (reg8 *) HB2__BIE)
/* Bit-mask for Aliased Register Access */
#define HB2_BIT_MASK               (* (reg8 *) HB2__BIT_MASK)
/* Bypass Enable */
#define HB2_BYP                    (* (reg8 *) HB2__BYP)
/* Port wide control signals */                                                   
#define HB2_CTL                    (* (reg8 *) HB2__CTL)
/* Drive Modes */
#define HB2_DM0                    (* (reg8 *) HB2__DM0) 
#define HB2_DM1                    (* (reg8 *) HB2__DM1)
#define HB2_DM2                    (* (reg8 *) HB2__DM2) 
/* Input Buffer Disable Override */
#define HB2_INP_DIS                (* (reg8 *) HB2__INP_DIS)
/* LCD Common or Segment Drive */
#define HB2_LCD_COM_SEG            (* (reg8 *) HB2__LCD_COM_SEG)
/* Enable Segment LCD */
#define HB2_LCD_EN                 (* (reg8 *) HB2__LCD_EN)
/* Slew Rate Control */
#define HB2_SLW                    (* (reg8 *) HB2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HB2_PRTDSI__CAPS_SEL       (* (reg8 *) HB2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HB2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HB2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HB2_PRTDSI__OE_SEL0        (* (reg8 *) HB2__PRTDSI__OE_SEL0) 
#define HB2_PRTDSI__OE_SEL1        (* (reg8 *) HB2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HB2_PRTDSI__OUT_SEL0       (* (reg8 *) HB2__PRTDSI__OUT_SEL0) 
#define HB2_PRTDSI__OUT_SEL1       (* (reg8 *) HB2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HB2_PRTDSI__SYNC_OUT       (* (reg8 *) HB2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HB2__SIO_CFG)
    #define HB2_SIO_HYST_EN        (* (reg8 *) HB2__SIO_HYST_EN)
    #define HB2_SIO_REG_HIFREQ     (* (reg8 *) HB2__SIO_REG_HIFREQ)
    #define HB2_SIO_CFG            (* (reg8 *) HB2__SIO_CFG)
    #define HB2_SIO_DIFF           (* (reg8 *) HB2__SIO_DIFF)
#endif /* (HB2__SIO_CFG) */

/* Interrupt Registers */
#if defined(HB2__INTSTAT)
    #define HB2_INTSTAT            (* (reg8 *) HB2__INTSTAT)
    #define HB2_SNAP               (* (reg8 *) HB2__SNAP)
    
	#define HB2_0_INTTYPE_REG 		(* (reg8 *) HB2__0__INTTYPE)
#endif /* (HB2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HB2_H */


/* [] END OF FILE */
