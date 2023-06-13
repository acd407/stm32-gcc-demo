#include "key.hpp"

Key::Key (GPIO_TypeDef *_GPIOx, uint16_t Pin, GPIOSpeed_TypeDef Speed,
          GPIOMode_TypeDef Mode)
    : GPIOx (_GPIOx) {
    GPIO_Structure = {Pin, Speed, Mode};
    RCC_APB2PeriphClockCmd (1 << ((uint32_t (GPIOx) - APB2PERIPH_BASE) / 0x400),
                            ENABLE);
    
    GPIO_Init (GPIOx, &GPIO_Structure);
}
Key::~Key() {
    GPIOx = nullptr;
    GPIO_Structure.GPIO_Pin = 0;
}
uint8_t Key::read() {
    if (GPIO_ReadInputDataBit (GPIOx, GPIO_Structure.GPIO_Pin) == 1) {
        Delay_ms (20);
        if (GPIO_ReadInputDataBit (GPIOx, GPIO_Structure.GPIO_Pin) == 1)
            return 1;
    }
    return 0;
}
