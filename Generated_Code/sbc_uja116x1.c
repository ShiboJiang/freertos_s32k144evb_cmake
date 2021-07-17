/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : sbc_uja116x1.c
**     Project     : freertos_s32k144
**     Processor   : S32K144_100
**     Component   : sbc_uja116x
**     Version     : Component SDK_S32K1xx_15, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K1xx_15
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-07-17, 17:24, # CodeGen: 21
**     Abstract    :
**
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc. 
**     Copyright 2016-2017 NXP 
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file sbc_uja116x1.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup sbc_uja116x1_module sbc_uja116x1 module documentation
**  @{
*/         

/*!
 * @file "sbc_uja116x1.c
 *
 * @page misra_violations MISRA-C:2012 violations
 * 
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variable will be used in other source file that user initialize
 * to use this module.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 10.3, Expression assigned to a narrower or
 * different essential type.
 * This is required by the conversion of a bit-field (uint8_t) of a register
 * into a enum type. Enum type is strictly defined as unsigned integer.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 10.5, Impermissible cast; cannot cast from
 * 'essentially unsigned' type to 'essentially enum<i>'.
 * This is required by the conversion of a bit-field (uint8_t) of a register
 * into a enum type. Enum type is strictly defined as unsigned integer.
 */


/* MODULE sbc_uja116x1. */

#include "sbc_uja116x1.h"
  
/*! @brief User configuration structure 0 */
const sbc_int_config_t sbc_uja116x1_InitConfig0 =
{
    /* Regulator control register group. */
    .regulatorCtr = 
    {
        /* Regulator control register. */
        .regulator  = 
        {
            .pdc   = SBC_UJA_REGULATOR_PDC_HV,
            .v2c   = SBC_UJA_REGULATOR_V2C_OFF,
            .v1rtc = SBC_UJA_REGULATOR_V1RTC_90,
        },
        /* Supply event capture enable register. */
        .supplyEvnt = 
        {
            .v2oe  = SBC_UJA_SUPPLY_EVNT_V2OE_DIS,
            .v2ue  = SBC_UJA_SUPPLY_EVNT_V2UE_DIS,
            .v1ue  = SBC_UJA_SUPPLY_EVNT_V1UE_DIS,
        },
    },
    /* Watchdog control register. */
    .watchdog = 
    {
        .modeControl   = SBC_UJA_WTDOG_CTR_WMC_TIME, 
        .nominalPeriod = SBC_UJA_WTDOG_CTR_NWP_128, 
    },
    /* Mode control register. */
    .mode = SBC_UJA_MODE_MC_STANDBY,
    /* LIMP home control. */
    .lhc  = SBC_UJA_FAIL_SAFE_LHC_FLOAT,     
    /* System event capture enable registers. */
    .sysEvnt = 
    {
        .owte  = SBC_UJA_SYS_EVNT_OTWE_DIS,
        .spife = SBC_UJA_SYS_EVNT_SPIFE_DIS,
    },
    /* Lock control register. */
    .lockMask  = (sbc_lock_t)( SBC_UJA_LOCK_LK0C_F(0) \
                  | SBC_UJA_LOCK_LK1C_F(0U) \
                  | SBC_UJA_LOCK_LK2C_F(0U) \
                  | SBC_UJA_LOCK_LK3C_F(0U) \
                  | SBC_UJA_LOCK_LK4C_F(0U) \
                  | SBC_UJA_LOCK_LK5C_F(0U) \
                  | SBC_UJA_LOCK_LK6C_F(0U) ),
    /* CAN configuration group. */
    .can = 
    {
        /* CAN control register. */
        .canConf  = 
        {
            .cfdc  = SBC_UJA_CAN_CFDC_EN,
            .pncok = SBC_UJA_CAN_PNCOK_DIS,
            .cpnc  = SBC_UJA_CAN_CPNC_DIS,
            .cmc   = SBC_UJA_CAN_CMC_OFMODE,
        },
        /* Transceiver event capture enable register. */
        .canTransEvnt = 
        {
            .cbse  = SBC_UJA_TRANS_EVNT_CBSE_DIS,
            .cfe   = SBC_UJA_TRANS_EVNT_CFE_DIS,
            .cwe   = SBC_UJA_TRANS_EVNT_CWE_DIS,
        },
        /* CAN data rate selection. */
        .datRate = SBC_UJA_DAT_RATE_CDR_500KB,
        /* ID registers. */
        .identif = {
            (sbc_identifier_t)0U, 
            (sbc_identifier_t)0U, 
            (sbc_identifier_t)0U, 
            (sbc_identifier_t)0U, 
          },
        /* ID mask registers. */
        .mask = {
            (sbc_identif_mask_t)0U, 
            (sbc_identif_mask_t)0U, 
            (sbc_identif_mask_t)0U, 
            (sbc_identif_mask_t)0U, 
          },
        /* Frame control register. */
        .frame  = 
        {
            .ide  = SBC_UJA_FRAME_CTR_IDE_11B,
            .pndm = SBC_UJA_FRAME_CTR_PNDM_DCARE,
            .dlc  = (sbc_frame_ctr_dlc_t)0U,
        },
        /* Data mask 0 - 7 configuration. */
        .dataMask = {
         (sbc_data_mask_t)0U,
         (sbc_data_mask_t)0U,
         (sbc_data_mask_t)0U,
         (sbc_data_mask_t)0U,
         (sbc_data_mask_t)0U,
         (sbc_data_mask_t)0U,
         (sbc_data_mask_t)0U,
         (sbc_data_mask_t)0U,
       }
    },
    .wakePin = 
     {
        .wpre = SBC_UJA_WAKE_EN_WPRE_DIS,
        .wpfe = SBC_UJA_WAKE_EN_WPFE_DIS,
    },
};
/*! sbc_uja116x1 configuration structure */
/* END sbc_uja116x1. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/