/**
 *-----------------------------------------------------------------------------
 * @file can_app.c
 * @brief 
 * @author shibo jiang
 * @version 0.0.0.1
 * @date 2021-07-16
 * @note [change history] 
 * 
 * @copyright NAAA_
 *-----------------------------------------------------------------------------
 */
#include "can_app.h"

can_buff_config_t g_CanBufferConfig =
{
    .enableFD = false,
    .enableBRS = false,
    .fdPadding = 0U,
    .idType = CAN_MSG_ID_STD,
    .isRemote = false
};

static void CAN_Config(void);

void vCanApp (void *pvParameters)
{
    TickType_t xNextWakeTime;
    /* Casting pvParameters to void because it is unused */
    (void)pvParameters; 
    float32 avgVolts;
    /* Define receive buffer */
    can_message_t recvMsg;
    can_message_t sendMsg;
    LedCtlType uLedCtlSig = LedCtlType_Invalid;

    /* Thread start */
    uLedCtlSig = LedCtlType_ON;
    CAN_Config();
    /* Initial struct value */
    memset(&recvMsg, 0u, sizeof(can_message_t));
    memset(&sendMsg, 0u, sizeof(can_message_t));

    xNextWakeTime = xTaskGetTickCount();
    for( ;; )
    {
        // print("Thread - vCanApp Run - 100ms\r\n");
        xQueuePeek(xVolSig, &avgVolts, mainDONT_BLOCK);
        
        /* Start receiving data in RX_MAILBOX. */
        CAN_Receive(&can_pal1_instance, RX_MAILBOX, &recvMsg);

        /* Wait until the previous FlexCAN receive is completed */
        // while(CAN_GetTransferStatus(&can_pal1_instance, RX_MAILBOX) == STATUS_BUSY);

        /* Check the received message ID and payload */
        if((recvMsg.data[0] == LedCtlType_OFF) &&
            recvMsg.id == RX_MSG_ID)
        {
            uLedCtlSig = LedCtlType_OFF;
        }
        else if((recvMsg.data[0] == LedCtlType_ON) &&
                recvMsg.id == RX_MSG_ID)
        {
            uLedCtlSig = LedCtlType_ON;
        }
        else
        {
            uLedCtlSig = LedCtlType_Invalid;
        }

        xQueueSend(xLedCtrlSig, &uLedCtlSig, mainDONT_BLOCK );
        /* Send the information via CAN */
        sendMsg.cs = 0U;
        sendMsg.id = TX_MSG_ID;
        sendMsg.data[0] = (uint8)(avgVolts*50);
        sendMsg.data[1] = (uint8)LED_2_St;
        sendMsg.length = 8U;
        CAN_Send(&can_pal1_instance, TX_MAILBOX, &sendMsg);
        vTaskDelayUntil( &xNextWakeTime, TASK_PERIOD_10_MS );
    }
}

static void CAN_Config(void)
{
	CAN_ConfigRxBuff(&can_pal1_instance, RX_MAILBOX, &g_CanBufferConfig, MSG_ALL_ACCEPT);
	CAN_SetRxFilter(&can_pal1_instance,FLEXCAN_MSG_ID_STD, RX_MAILBOX,MSG_ALL_ACCEPT);
	CAN_ConfigTxBuff(&can_pal1_instance, TX_MAILBOX, &g_CanBufferConfig);
}