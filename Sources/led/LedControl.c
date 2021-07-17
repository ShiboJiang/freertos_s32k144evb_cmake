/**
 *-----------------------------------------------------------------------------
 * @file LedControl.c
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-12
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */

#include "LedControl.h"


void vLedControl(void *pvParameters)
{
    /* Casting pvParameters to void because it is unused */
    (void)pvParameters;
    TickType_t xNextWakeTime;
    LedCtlType uLedCtlSig = LedCtlType_Invalid;

    // xNextWakeTime = xTaskGetTickCount();
    for( ;; )
    {
        // print("Thread - vLedControl Run - 200ms\r\n");
        /* Wait until something arrives in the queue - this task will block
        indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
        FreeRTOSConfig.h. */
        xQueueReceive( xLedCtrlSig, &uLedCtlSig, portMAX_DELAY);

        /*  To get here something must have been received from the queue, but
        is it the expected value?  If it is, toggle the LED. */
        if( uLedCtlSig == LedCtlType_ON )
        {
            PINS_DRV_SetPins(LED_GPIO, (1 << LED2));
        }
        else if (uLedCtlSig == LedCtlType_OFF)
        {
            PINS_DRV_ClearPins(LED_GPIO, (1 << LED2));
        }
        else
        {
            /*Do Nothing*/
        }
        vTaskDelayUntil( &xNextWakeTime, TASK_PERIOD_10_MS );
    }
}