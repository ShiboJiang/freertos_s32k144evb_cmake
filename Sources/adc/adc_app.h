/**
 *-----------------------------------------------------------------------------
 * @file adc_app.h
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-13
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */
#ifndef _ADC_APP_H_
#define _ADC_APP_H_

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "Rte_Type.h"
#include "Cpu.h"
#include "pin_mux.h"
#include "adc_pal1.h"
#include "clockMan1.h"
#include "uart_app.h"

/* Macro Define -------------------------------------------------------------*/
#define ADC_INSTANCE    0UL
#define ADC_CHN         12U
#define ADC_VREFH       5.0f
#define ADC_VREFL       0.0f

#define NUM_CONV_GROUP_ITERATIONS       10UL
#define DELAY_BETWEEN_SW_TRIG_GROUPS    1500UL /* [milliseconds] */


/* Import Parameters --------------------------------------------------------*/
extern QueueHandle_t xVolSig;

/* Export Parameters --------------------------------------------------------*/
extern uint16 adcMax;
extern uint8 selectedGroupIndex;

extern void vAdcApp (void *pvParameters);


#endif