/**
 *-----------------------------------------------------------------------------
 * @file LedControl.h
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-12
 * @note [change history] 
 * 
 * @copyright GEELY AUTOMOBILE RESEARCH INSTITUTE CO.,LTD Copyright (c) 2020
 *-----------------------------------------------------------------------------
 */

#ifndef _LEDCONTROL_H_
#define _LEDCONTROL_H_

#include "FreeRTOS.h"
#include "Rte_LedControl_Type.h"
#include "pin_mux.h"
#include "BoardDefines.h"
#include "queue.h"

/* Macro Define -------------------------------------------------------------*/
#define userQUEUE_SEND_MS_10            ( 10 / portTICK_PERIOD_MS )

/* Import Parameters --------------------------------------------------------*/
extern QueueHandle_t xLedCtrlSig;


/* Export Parameters --------------------------------------------------------*/
extern void vLedControl(void *pvParameters);

#endif