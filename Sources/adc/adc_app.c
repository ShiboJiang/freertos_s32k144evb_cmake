/**
 *-----------------------------------------------------------------------------
 * @file adc_app.c
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-13
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */
#include "adc_app.h"

/* Flag used to store if an ADC PAL conversion group has finished executing */
volatile boolean groupConvDone = false;
/* Flag used to store the offset of the most recent result in the result buffer */
volatile uint32 resultLastOffset = 0;
/* Select the index of a SW triggered group of conversions (see ADC PAL component) */
uint8 selectedGroupIndex = 0u;

/* Variable to store value from ADC conversion */
volatile uint16 adcRawValue;

/**
 *-----------------------------------------------------------------------------
 * @brief 
 * 
 * @param callbackInfo 
 * @param userData 
 *-----------------------------------------------------------------------------
 */
void adc_pal1_callback00(const adc_callback_info_t * const callbackInfo, 
                        void * userData)
{
    (void) userData;

    groupConvDone = true;
    resultLastOffset = callbackInfo->resultBufferTail;
}

/**
 *-----------------------------------------------------------------------------
 * @brief 
 * 
 * @param callbackInfo 
 * @param userData 
 *-----------------------------------------------------------------------------
 */
void adc_pal1_callback02(const adc_callback_info_t * const callbackInfo, void * userData)
{
    (void) userData;

    groupConvDone = true;
    resultLastOffset = callbackInfo->resultBufferTail;
}

void vAdcApp (void *pvParameters)
{
    // status_t status;
    uint16 resultStartOffset;
    uint32 sum, avg;
    float32 avgVolts, lastAvgVolts;
    char msg[255] = { 0, };
    TickType_t xNextWakeTime;
    size_t heap_msg;

    /* Casting pvParameters to void because it is unused */
    (void)pvParameters; 

    xNextWakeTime = xTaskGetTickCount();
    for( ;; )
    {
        // print("Thread - vAdcApp Run - 500ms\r\n");
        /* Wait until something arrives in the queue - this task will block
        indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
        FreeRTOSConfig.h. */

        uint8_t numChans = adc_pal1_InitConfig0.groupConfigArray[selectedGroupIndex].numChannels;
        resultStartOffset = 0u;
        /* Wait for group to finish */
        if(groupConvDone == true)
        {
            /* Stop the extra SW triggered conversion */
            // status = ADC_StopGroupConversion(&adc_pal1_instance, selectedGroupIndex, 1 /* millisecond */);
            // DEV_ASSERT(status == STATUS_SUCCESS);
            /* Calculate average value of the results in the group of conversions */
            sum = 0;
            for(uint8_t idx = resultStartOffset; idx <= resultLastOffset; idx++)
            {
                sum += adc_pal1_Results00[idx]; /* Results are directly available in resultBuffer associated with the group at initialization */
            }
            DEV_ASSERT((resultLastOffset - resultStartOffset + 1) == numChans);
            avg = sum / numChans;

            /* Convert avg to volts */
            avgVolts = ((float) avg / adcMax) * (ADC_VREFH - ADC_VREFL);
            /* Convert avg to string */
            floatToStr(&avgVolts, msg, 5);

            /* Send the result to the user via LPUART */
            print(headerStr);
            print(msg);
            print(" V\r\n");

            /* Reset flag for group conversion status */
            groupConvDone = false;
            /* Restart the SW triggered group of conversions */
            // status = ADC_StartGroupConversion(&adc_pal1_instance, selectedGroupIndex); /* Restart can be avoided if SW triggered group is configured to run in continuous mode */
            // DEV_ASSERT(status == STATUS_SUCCESS);
        }

        // status = ADC_Deinit(&adc_pal1_instance);
        // DEV_ASSERT(status == STATUS_SUCCESS);

        // status = LPUART_DRV_Deinit(INST_LPUART1);
        // DEV_ASSERT(status == STATUS_SUCCESS);
        heap_msg = xPortGetFreeHeapSize();
        // printf("ADC Free Heap is (bytes) %d \r\n",(int32_t)heap_msg);
        // printf("ADC Free Stack size is (bits) %d \r\n",(int32_t)uxTaskGetStackHighWaterMark(NULL));
        xQueueReceive( xVolSig, &lastAvgVolts, mainDONT_BLOCK);
        xQueueSend( xVolSig, &avgVolts, mainDONT_BLOCK );
        vTaskDelayUntil( &xNextWakeTime, TASK_PERIOD_1000_MS );
    }
}