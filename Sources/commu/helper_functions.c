/**
 *-----------------------------------------------------------------------------
 * @file helper_functions.c
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-13
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */

#include "helper_functions.h"

/***********************************
 * @brief: Convert a float to null terminated char array
 * @param srcValue:  pointer to the source float value
 * @param destStr:   pointer to the destination string
 * @param maxLen:    maximum lenght of the string
 ***********************************/
void floatToStr(const float *srcValue, char *destStr, uint8_t maxLen)
{
    uint8_t i, lessThanOne = 0;
    float tempVal = (*srcValue);
    uint8_t currentVal;

    if (tempVal < 0)
    {
        tempVal *= -1;
        *destStr = '-';
        destStr++;
    }
    for (i = 0; i < maxLen; i++)
    {
        currentVal = (uint8_t)(tempVal);
        *destStr = currentVal + 48;
        destStr++;
        tempVal -= currentVal;
        if ((tempVal < 1) && (lessThanOne == 0))
        {
            *destStr = '.';
            destStr++;
            lessThanOne = 1;
        }
        tempVal *= 10;
    }
    *destStr = 0;
}