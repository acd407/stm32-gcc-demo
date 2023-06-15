#include "Led.h"

void LED_Init() {
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = {.GPIO_Mode = GPIO_Mode_Out_PP,
                                           .GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1,
                                           .GPIO_Speed = GPIO_Speed_50MHz};
    GPIO_Init (GPIOA, &GPIO_InitStructure);
    GPIO_SetBits (GPIOA, GPIO_Pin_0 | GPIO_Pin_1);
}

void LED1_On() { GPIO_ResetBits (GPIOA, GPIO_Pin_0); }
void LED2_On() { GPIO_ResetBits (GPIOA, GPIO_Pin_1); }
void LED1_Off() { GPIO_SetBits (GPIOA, GPIO_Pin_0); }
void LED2_Off() { GPIO_SetBits (GPIOA, GPIO_Pin_1); }

void LED1_Turn() {
    if (GPIO_ReadOutputDataBit (GPIOA, GPIO_Pin_0))
        LED1_On();
    else
        LED1_Off();
}

void LED2_Turn() {
    if (GPIO_ReadOutputDataBit (GPIOA, GPIO_Pin_1))
        LED2_On();
    else
        LED2_Off();
}