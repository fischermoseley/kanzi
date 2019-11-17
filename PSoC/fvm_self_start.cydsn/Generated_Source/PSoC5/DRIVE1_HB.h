/*******************************************************************************
* File Name: DRIVE1_HB.h  
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

#if !defined(CY_PINS_DRIVE1_HB_H) /* Pins DRIVE1_HB_H */
#define CY_PINS_DRIVE1_HB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DRIVE1_HB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DRIVE1_HB__PORT == 15 && ((DRIVE1_HB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DRIVE1_HB_Write(uint8 value);
void    DRIVE1_HB_SetDriveMode(uint8 mode);
uint8   DRIVE1_HB_ReadDataReg(void);
uint8   DRIVE1_HB_Read(void);
void    DRIVE1_HB_SetInterruptMode(uint16 position, uint16 mode);
uint8   DRIVE1_HB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DRIVE1_HB_SetDriveMode() function.
     *  @{
     */
        #define DRIVE1_HB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DRIVE1_HB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DRIVE1_HB_DM_RES_UP          PIN_DM_RES_UP
        #define DRIVE1_HB_DM_RES_DWN         PIN_DM_RES_DWN
        #define DRIVE1_HB_DM_OD_LO           PIN_DM_OD_LO
        #define DRIVE1_HB_DM_OD_HI           PIN_DM_OD_HI
        #define DRIVE1_HB_DM_STRONG          PIN_DM_STRONG
        #define DRIVE1_HB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DRIVE1_HB_MASK               DRIVE1_HB__MASK
#define DRIVE1_HB_SHIFT              DRIVE1_HB__SHIFT
#define DRIVE1_HB_WIDTH              1u

/* Interrupt constants */
#if defined(DRIVE1_HB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DRIVE1_HB_SetInterruptMode() function.
     *  @{
     */
        #define DRIVE1_HB_INTR_NONE      (uint16)(0x0000u)
        #define DRIVE1_HB_INTR_RISING    (uint16)(0x0001u)
        #define DRIVE1_HB_INTR_FALLING   (uint16)(0x0002u)
        #define DRIVE1_HB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DRIVE1_HB_INTR_MASK      (0x01u) 
#endif /* (DRIVE1_HB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DRIVE1_HB_PS                     (* (reg8 *) DRIVE1_HB__PS)
/* Data Register */
#define DRIVE1_HB_DR                     (* (reg8 *) DRIVE1_HB__DR)
/* Port Number */
#define DRIVE1_HB_PRT_NUM                (* (reg8 *) DRIVE1_HB__PRT) 
/* Connect to Analog Globals */                                                  
#define DRIVE1_HB_AG                     (* (reg8 *) DRIVE1_HB__AG)                       
/* Analog MUX bux enable */
#define DRIVE1_HB_AMUX                   (* (reg8 *) DRIVE1_HB__AMUX) 
/* Bidirectional Enable */                                                        
#define DRIVE1_HB_BIE                    (* (reg8 *) DRIVE1_HB__BIE)
/* Bit-mask for Aliased Register Access */
#define DRIVE1_HB_BIT_MASK               (* (reg8 *) DRIVE1_HB__BIT_MASK)
/* Bypass Enable */
#define DRIVE1_HB_BYP                    (* (reg8 *) DRIVE1_HB__BYP)
/* Port wide control signals */                                                   
#define DRIVE1_HB_CTL                    (* (reg8 *) DRIVE1_HB__CTL)
/* Drive Modes */
#define DRIVE1_HB_DM0                    (* (reg8 *) DRIVE1_HB__DM0) 
#define DRIVE1_HB_DM1                    (* (reg8 *) DRIVE1_HB__DM1)
#define DRIVE1_HB_DM2                    (* (reg8 *) DRIVE1_HB__DM2) 
/* Input Buffer Disable Override */
#define DRIVE1_HB_INP_DIS                (* (reg8 *) DRIVE1_HB__INP_DIS)
/* LCD Common or Segment Drive */
#define DRIVE1_HB_LCD_COM_SEG            (* (reg8 *) DRIVE1_HB__LCD_COM_SEG)
/* Enable Segment LCD */
#define DRIVE1_HB_LCD_EN                 (* (reg8 *) DRIVE1_HB__LCD_EN)
/* Slew Rate Control */
#define DRIVE1_HB_SLW                    (* (reg8 *) DRIVE1_HB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DRIVE1_HB_PRTDSI__CAPS_SEL       (* (reg8 *) DRIVE1_HB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DRIVE1_HB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DRIVE1_HB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DRIVE1_HB_PRTDSI__OE_SEL0        (* (reg8 *) DRIVE1_HB__PRTDSI__OE_SEL0) 
#define DRIVE1_HB_PRTDSI__OE_SEL1        (* (reg8 *) DRIVE1_HB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DRIVE1_HB_PRTDSI__OUT_SEL0       (* (reg8 *) DRIVE1_HB__PRTDSI__OUT_SEL0) 
#define DRIVE1_HB_PRTDSI__OUT_SEL1       (* (reg8 *) DRIVE1_HB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DRIVE1_HB_PRTDSI__SYNC_OUT       (* (reg8 *) DRIVE1_HB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DRIVE1_HB__SIO_CFG)
    #define DRIVE1_HB_SIO_HYST_EN        (* (reg8 *) DRIVE1_HB__SIO_HYST_EN)
    #define DRIVE1_HB_SIO_REG_HIFREQ     (* (reg8 *) DRIVE1_HB__SIO_REG_HIFREQ)
    #define DRIVE1_HB_SIO_CFG            (* (reg8 *) DRIVE1_HB__SIO_CFG)
    #define DRIVE1_HB_SIO_DIFF           (* (reg8 *) DRIVE1_HB__SIO_DIFF)
#endif /* (DRIVE1_HB__SIO_CFG) */

/* Interrupt Registers */
#if defined(DRIVE1_HB__INTSTAT)
    #define DRIVE1_HB_INTSTAT            (* (reg8 *) DRIVE1_HB__INTSTAT)
    #define DRIVE1_HB_SNAP               (* (reg8 *) DRIVE1_HB__SNAP)
    
	#define DRIVE1_HB_0_INTTYPE_REG 		(* (reg8 *) DRIVE1_HB__0__INTTYPE)
#endif /* (DRIVE1_HB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DRIVE1_HB_H */


/* [] END OF FILE */
