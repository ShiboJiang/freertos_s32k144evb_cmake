/**
 *-----------------------------------------------------------------------------
 * @file uart_app.c
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-13
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */
#include "uart_app.h"

/* Function which sends a string to user via LPUART
 * param sourceStr: pointer to the array of characters
 *                  that you wish to send.
 * return:          None
 */
void print(const char *sourceStr)
{
    uint32_t bytesRemaining;
    status_t transSts;

    /* Send data via LPUART */
    LPUART_DRV_SendData(INST_LPUART1, (uint8_t *) sourceStr, strlen(sourceStr));
    /* Wait for transmission to be successful */
    transSts = LPUART_DRV_GetTransmitStatus(INST_LPUART1, &bytesRemaining);
    while (transSts != STATUS_SUCCESS)
    {
        transSts = LPUART_DRV_GetTransmitStatus(INST_LPUART1, &bytesRemaining);
    }
}