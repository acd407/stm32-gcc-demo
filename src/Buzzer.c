#include "Buzzer.h"

void Buzzer_Init() {
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = {.GPIO_Mode = GPIO_Mode_Out_PP,
                                           .GPIO_Pin = GPIO_Pin_6,
                                           .GPIO_Speed = GPIO_Speed_50MHz};
    GPIO_Init (GPIOA, &GPIO_InitStructure);
    GPIO_SetBits (GPIOA, GPIO_Pin_6);
}

void Buzzer_On() { GPIO_ResetBits (GPIOA, GPIO_Pin_6); }
void Buzzer_Off() { GPIO_SetBits (GPIOA, GPIO_Pin_6); }

void Buzzer_Turn() {
    if (GPIO_ReadOutputDataBit (GPIOA, GPIO_Pin_6))
        Buzzer_On();
    else
        Buzzer_Off();
}
