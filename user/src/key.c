#include "delay.h"
#include "stm32f10x.h"

void Key_Init() {
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = {
        .GPIO_Mode = GPIO_Mode_IPD, .GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_10};
    GPIO_Init (GPIOB, &GPIO_InitStructure);
}

uint8_t Key1_Read() {
    if (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_0) == 1) {
        Delay_ms (20);
        while (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_0) == 1)
            ;
        Delay_ms (20);
        return 1;
    }
    return 0;
}

uint8_t Key2_Read() {
    if (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_10) == 1) {
        Delay_ms (20);
        while (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_10) == 1)
            ;
        Delay_ms (20);
        return 1;
    }
    return 0;
}
