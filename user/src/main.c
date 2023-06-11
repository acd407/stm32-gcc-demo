#include "buzzer.h"
#include "delay.h"
#include "key.h"
#include "led.h"
#include "lightsensor.h"
#include "stm32f10x.h"

int main() {
    Buzzer_Init();
    LED_Init();
    Key_Init();
    LightSensor_Init();
    while (1) {
        if (Key1_Read())
            LED1_Turn();
        if (Key2_Read())
            LED2_Turn();
        if (! LightSensor_Read())
            Buzzer_On();
        else
            Buzzer_Off();
    }
}
