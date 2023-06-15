extern "C" {
#include "stm32f10x.h"
}

class Delay {
  public:
    /**
    * @brief  微秒级延时
    * @param  xus 延时时长，范围：0~233015
    * @return 无
    */
    static void us (uint32_t xus);
    /**
    * @brief  毫秒级延时
    * @param  xms 延时时长，范围：0~4294967295
    * @return 无
    */
    static void ms (uint32_t xms);
    /**
    * @brief  秒级延时
    * @param  xs 延时时长，范围：0~4294967295
    * @return 无
    */
    static void s(uint32_t xs);
};