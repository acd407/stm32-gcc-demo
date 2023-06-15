#include "Delay.hpp"
extern "C" {
#include "stm32f10x.h"
}
class Key {
    GPIO_TypeDef *GPIOx;
    GPIO_InitTypeDef GPIO_Structure;

  public:
    Key() = delete;
    ~Key();
    Key (GPIO_TypeDef *RCC_APB2Periph_GPIOx, uint16_t Pin,
         GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode);
    uint8_t read();
};
