/**
 *-----------------------------------------------------------------------------
 * @file uart_app.h
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-13
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */
#ifndef _UART_APP_H_
#define _UART_APP_H_

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
#include "helper_functions.h"

/* Macro Define -------------------------------------------------------------*/
#define initOKStr "\r\n Initial OK! \r\n"
#define welcomeStr "\r\nThis is an example for ADC PAL: it will print the average value of the conversion results in groups of conversions.\
                   \r\nMeasurements are done on ADC0 Input 12\r\n"
#define part1Str  "\r\n*** Part 1: software triggered conversion group \r\n\r\n"
#define part2Str  "\r\n*** Part 2: hardware triggered conversion group \r\n\r\n"
#define headerStr  "ADC avg result: "
#define exitStr    "\r\nADC PAL example execution finished successfully.\r\n"

/* Export Parameters --------------------------------------------------------*/
extern void print(const char *sourceStr);



#endif