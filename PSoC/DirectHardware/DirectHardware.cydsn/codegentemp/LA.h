/*******************************************************************************
* File Name: LA.h  
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

#if !defined(CY_PINS_LA_H) /* Pins LA_H */
#define CY_PINS_LA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LA__PORT == 15 && ((LA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LA_Write(uint8 value);
void    LA_SetDriveMode(uint8 mode);
uint8   LA_ReadDataReg(void);
uint8   LA_Read(void);
void    LA_SetInterruptMode(uint16 position, uint16 mode);
uint8   LA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LA_SetDriveMode() function.
     *  @{
     */
        #define LA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LA_DM_RES_UP          PIN_DM_RES_UP
        #define LA_DM_RES_DWN         PIN_DM_RES_DWN
        #define LA_DM_OD_LO           PIN_DM_OD_LO
        #define LA_DM_OD_HI           PIN_DM_OD_HI
        #define LA_DM_STRONG          PIN_DM_STRONG
        #define LA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LA_MASK               LA__MASK
#define LA_SHIFT              LA__SHIFT
#define LA_WIDTH              1u

/* Interrupt constants */
#if defined(LA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LA_SetInterruptMode() function.
     *  @{
     */
        #define LA_INTR_NONE      (uint16)(0x0000u)
        #define LA_INTR_RISING    (uint16)(0x0001u)
        #define LA_INTR_FALLING   (uint16)(0x0002u)
        #define LA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LA_INTR_MASK      (0x01u) 
#endif /* (LA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LA_PS                     (* (reg8 *) LA__PS)
/* Data Register */
#define LA_DR                     (* (reg8 *) LA__DR)
/* Port Number */
#define LA_PRT_NUM                (* (reg8 *) LA__PRT) 
/* Connect to Analog Globals */                                                  
#define LA_AG                     (* (reg8 *) LA__AG)                       
/* Analog MUX bux enable */
#define LA_AMUX                   (* (reg8 *) LA__AMUX) 
/* Bidirectional Enable */                                                        
#define LA_BIE                    (* (reg8 *) LA__BIE)
/* Bit-mask for Aliased Register Access */
#define LA_BIT_MASK               (* (reg8 *) LA__BIT_MASK)
/* Bypass Enable */
#define LA_BYP                    (* (reg8 *) LA__BYP)
/* Port wide control signals */                                                   
#define LA_CTL                    (* (reg8 *) LA__CTL)
/* Drive Modes */
#define LA_DM0                    (* (reg8 *) LA__DM0) 
#define LA_DM1                    (* (reg8 *) LA__DM1)
#define LA_DM2                    (* (reg8 *) LA__DM2) 
/* Input Buffer Disable Override */
#define LA_INP_DIS                (* (reg8 *) LA__INP_DIS)
/* LCD Common or Segment Drive */
#define LA_LCD_COM_SEG            (* (reg8 *) LA__LCD_COM_SEG)
/* Enable Segment LCD */
#define LA_LCD_EN                 (* (reg8 *) LA__LCD_EN)
/* Slew Rate Control */
#define LA_SLW                    (* (reg8 *) LA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LA_PRTDSI__CAPS_SEL       (* (reg8 *) LA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LA_PRTDSI__OE_SEL0        (* (reg8 *) LA__PRTDSI__OE_SEL0) 
#define LA_PRTDSI__OE_SEL1        (* (reg8 *) LA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LA_PRTDSI__OUT_SEL0       (* (reg8 *) LA__PRTDSI__OUT_SEL0) 
#define LA_PRTDSI__OUT_SEL1       (* (reg8 *) LA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LA_PRTDSI__SYNC_OUT       (* (reg8 *) LA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LA__SIO_CFG)
    #define LA_SIO_HYST_EN        (* (reg8 *) LA__SIO_HYST_EN)
    #define LA_SIO_REG_HIFREQ     (* (reg8 *) LA__SIO_REG_HIFREQ)
    #define LA_SIO_CFG            (* (reg8 *) LA__SIO_CFG)
    #define LA_SIO_DIFF           (* (reg8 *) LA__SIO_DIFF)
#endif /* (LA__SIO_CFG) */

/* Interrupt Registers */
#if defined(LA__INTSTAT)
    #define LA_INTSTAT            (* (reg8 *) LA__INTSTAT)
    #define LA_SNAP               (* (reg8 *) LA__SNAP)
    
	#define LA_0_INTTYPE_REG 		(* (reg8 *) LA__0__INTTYPE)
#endif /* (LA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LA_H */


/* [] END OF FILE */
