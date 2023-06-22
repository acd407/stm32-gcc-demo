#include "GPIO.hpp"
// 能改成模板类吗？
class Hiatus : public GPIO {
  protected:
    GPIO_TypeDef *GPIOx;
    GPIO_InitTypeDef GPIO_Structure;

  public:
    Hiatus() = delete;
    ~Hiatus();
    Hiatus (GPIO_TypeDef *RCC_APB2Periph_GPIOx, uint16_t Pin);
    Hiatus (GPIO_TypeDef *RCC_APB2Periph_GPIOx, uint16_t Pin,
            GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode);
    bool read();
    void write (bool status);
    void turn();
    void deinit();
};
