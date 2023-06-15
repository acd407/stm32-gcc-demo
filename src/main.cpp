#include "Key.hpp"
extern "C" {
#include "OLED.h"
#include "stm32f10x.h"
}

char *str[] {const_cast<char *> ("pressed! "),
             const_cast<char *> ("released!")};

bool status;
void OLED_turn() {
    static uint32_t count = 0;
    if (status)
        count++;
    status = ! status;
    OLED_ShowString (1, 1, str[! status]);
    OLED_ShowNum (2, 1, count, 5);
}
extern "C" int main() {
    Key key {GPIOA, GPIO_Pin_15, GPIO_Speed_50MHz, GPIO_Mode_IPU};
    OLED_Init();
    status = key.read();
    OLED_ShowString (1, 1, str[! status]);
    OLED_ShowNum (2, 1, 0, 5);
    while (1) {
        bool ret = key.read();
        if (ret != status)
            OLED_turn();
    }
}
