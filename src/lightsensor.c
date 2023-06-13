#include "stm32f10x.h"

void LightSensor_Init () {
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = {.GPIO_Mode = GPIO_Mode_IN_FLOATING,
                                           .GPIO_Pin = GPIO_Pin_9};
    GPIO_Init (GPIOB, &GPIO_InitStructure);
}

uint8_t LightSensor_Read() {
    return GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_9);
}

