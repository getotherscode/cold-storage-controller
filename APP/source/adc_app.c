#include "adc_app.h"
#include "adc.h"
#include "portmacro.h"
#include "projdefs.h"
#include "stm32g0xx_hal_adc.h"

TaskHandle_t adcTaskHandle = NULL;

uint16_t g_adc_buffer[ADC_CHANNEL_NUM];

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    vTaskNotifyGiveFromISR(adcTaskHandle, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void adc_task(void* pvParameters)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)g_adc_buffer, ADC_CHANNEL_NUM);

    for(;;)
    {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }
}
