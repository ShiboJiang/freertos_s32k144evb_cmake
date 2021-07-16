/**
 *-----------------------------------------------------------------------------
 * @file Rte_Type.h
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-12
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */
#ifndef _RTE_TYPE_H_
#define _RTE_TYPE_H_

#include "stdint.h"

/* A block time of zero simply means "don't block". */
#define mainDONT_BLOCK                        ( 0UL )

#define TASK_PERIOD_10_MS             ( 10 / portTICK_PERIOD_MS )
#define TASK_PERIOD_100_MS            ( 100 / portTICK_PERIOD_MS )
#define TASK_PERIOD_200_MS            ( 200 / portTICK_PERIOD_MS )
#define TASK_PERIOD_500_MS            ( 500 / portTICK_PERIOD_MS )
#define TASK_PERIOD_1000_MS           ( 1000 / portTICK_PERIOD_MS )

#define TASK_ADC_STACK_SIZE           ((uint16) 500)
#define TASK_CAN_STACK_SIZE           ((uint16) 500)

/* AUTOSAR Base to Platform types mapping */
typedef uint8_t boolean_T;
typedef int16_t int16_T;
typedef int32_t int32_T;
typedef int8_t int8_T;
typedef uint16_t uint16_T;
typedef uint32_t uint32_T;
typedef uint8_t uint8_T;
typedef float float32;
// typedef real_T float64;

typedef boolean_T boolean;
typedef int16_T sint16;
typedef int32_T sint32;
typedef int8_T sint8;
typedef uint16_T uint16;
typedef uint32_T uint32;
typedef uint8_T uint8;
// typedef real32_T float32;
// typedef real_T float64;

// #define false 0u
// #define true 1u

/* Type Define --------------------------------------------------------------*/
typedef uint8 LedCtlType;

/* Macro Define -------------------------------------------------------------*/
#define LedCtlType_Invalid  0u
#define LedCtlType_ON       1u
#define LedCtlType_OFF      2u

#endif