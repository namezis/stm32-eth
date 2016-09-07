
#include "Platform.h"

namespace platform
{
    namespace stm32
    {
        void spiClockEnable()
        {
            __SPI2_CLK_ENABLE(); // TODO: Replace by current version
            __HAL_RCC_GPIOB_CLK_ENABLE();
        }
    }
}

