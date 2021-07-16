/**
 *-----------------------------------------------------------------------------
 * @file can_app.h
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-16
 * @note [change history] 
 * 
 * @copyright GEELY AUTOMOBILE RESEARCH INSTITUTE CO.,LTD Copyright (c) 2020
 *-----------------------------------------------------------------------------
 */
#ifndef _CAN_APP_H_
#define _CAN_APP_H_

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "Rte_Type.h"
#include "Cpu.h"
#include "pin_mux.h"
#include "dmaController1.h"
#include "lpuart1.h"
#include "clockMan1.h"
#include "string.h"
#include "uart_app.h"

/* Import Parameters --------------------------------------------------------*/
extern QueueHandle_t xVolSig;
extern QueueHandle_t xLedCtrlSig;

/* Export Parameters --------------------------------------------------------*/

extern void vCanApp (void *pvParameters);


#endif