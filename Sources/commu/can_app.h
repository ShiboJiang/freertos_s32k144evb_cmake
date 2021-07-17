/**
 *-----------------------------------------------------------------------------
 * @file can_app.h
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-16
 * @note [change history] 
 * 
 * @copyright NAAA_
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
#include "dmaController1.h"
#include "lpuart1.h"
#include "clockMan1.h"
#include "string.h"
#include "uart_app.h"

/* Macro Define -------------------------------------------------------------*/
#define TX_MAILBOX  (1UL)
#define TX_MSG_ID   (0x100UL)
#define RX_MAILBOX  (0UL)
#define RX_MSG_ID   (0x101UL)
#define MSG_ALL_ACCEPT (0UL)

/* Import Parameters --------------------------------------------------------*/
extern QueueHandle_t xVolSig;
extern QueueHandle_t xLedCtrlSig;

/* Export Parameters --------------------------------------------------------*/

extern void vCanApp (void *pvParameters);


#endif