/**
 *-----------------------------------------------------------------------------
 * @file LedControl.h
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-12
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */

#ifndef _LEDCONTROL_H_
#define _LEDCONTROL_H_

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "Rte_LedControl_Type.h"
#include "pin_mux.h"
#include "BoardDefines.h"
#include "uart_app.h"

/* Macro Define -------------------------------------------------------------*/
#define userQUEUE_SEND_MS_10            ( 10 / portTICK_PERIOD_MS )
#define LED_2_St		        (PINS_DRV_GetPinsOutput(LED_GPIO)>>LED2)&0x01

/* Import Parameters --------------------------------------------------------*/
extern QueueHandle_t xLedCtrlSig;


/* Export Parameters --------------------------------------------------------*/
extern void vLedControl(void *pvParameters);

#endif