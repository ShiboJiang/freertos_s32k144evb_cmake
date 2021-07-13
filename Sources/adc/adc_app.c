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