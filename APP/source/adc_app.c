#include "adc_app.h"
#include "FreeRTOS.h"
#include "adc.h"
#include "stm32g0xx_hal_adc.h"

uint16_t g_adc_buffer[ADC_CHANNEL_NUM];

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
    
}

void adc_task(void* pvParameters)
{
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)g_adc_buffer, ADC_CHANNEL_NUM);

  for(;;)
  {
    
  }
}
