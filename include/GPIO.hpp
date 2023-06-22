extern "C" {
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
}

template <GPIO_TypeDef* GPIOx, uint16_t Pin,
          GPIOSpeed_TypeDef Speed = GPIO_Speed_50MHz,
          GPIOMode_TypeDef Mode = GPIO_Mode_Out_PP>
class GPIO {
  public:
    GPIO() {
        GPIO_InitTypeDef GPIO_Structure = {Pin, Speed, Mode};
        RCC_APB2PeriphClockCmd (
            1 << ((uint32_t (GPIOx) - APB2PERIPH_BASE) / 0x400), ENABLE);
        GPIO_Init (GPIOx, &GPIO_Structure);
    }
    bool read() {
        return static_cast<bool> (GPIO_ReadInputDataBit (GPIOx, Pin));
    }
    void write (bool status) {
        GPIO_WriteBit (GPIOx, Pin, static_cast<BitAction> (status));
    }
    void turn() { write (! read()); }
    void deinit() { GPIO_DeInit (GPIOx); }
};
