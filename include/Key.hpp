#include "Delay.hpp"
#include "GPIO.hpp"
extern "C" {
#include "stm32f10x.h"
}
template <GPIO_TypeDef* GPIOx, uint16_t Pin,
          GPIOSpeed_TypeDef Speed = GPIO_Speed_50MHz,
          GPIOMode_TypeDef Mode = GPIO_Mode_Out_PP>
class Key : public GPIO<GPIOx, Pin, Speed, Mode> {
  public:
    Key() { GPIO<GPIOx, Pin, Speed, Mode>(); }
    bool read() {
        if (GPIO_ReadInputDataBit (GPIOx, Pin) == 1) {
            Delay::ms (20);
            if (GPIO_ReadInputDataBit (GPIOx, Pin) == 1)
                return 1;
        }
        return 0;
    }
};
