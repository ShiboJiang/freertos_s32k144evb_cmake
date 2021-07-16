/**
 *-----------------------------------------------------------------------------
 * @file can_app.c
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-16
 * @note [change history] 
 * 
 * @copyright GEELY AUTOMOBILE RESEARCH INSTITUTE CO.,LTD Copyright (c) 2020
 *-----------------------------------------------------------------------------
 */
#include "can_app.h"

void vCanApp (void *pvParameters)
{
    TickType_t xNextWakeTime;
    /* Casting pvParameters to void because it is unused */
    (void)pvParameters; 
    float32 avgVolts;
    // char msg[255] = { 0, };
    LedCtlType uLedCtlSig = LedCtlType_Invalid;

    /* Thread start */
    uLedCtlSig = LedCtlType_ON;
    xNextWakeTime = xTaskGetTickCount();
    for( ;; )
    {
        print("Thread - vCanApp Run - 100ms\r\n");
        xQueuePeek(xVolSig, &avgVolts, mainDONT_BLOCK);

        if (uLedCtlSig == LedCtlType_ON)
        {
            uLedCtlSig = LedCtlType_OFF;
        }
        else if (uLedCtlSig == LedCtlType_OFF)
        {
            uLedCtlSig = LedCtlType_ON;
        }
        else
        {
            /* code */
        }

        xQueueSend(xLedCtrlSig, &uLedCtlSig, mainDONT_BLOCK );
        vTaskDelayUntil( &xNextWakeTime, TASK_PERIOD_100_MS );
    }
}