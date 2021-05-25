#include "stm32f0xx.h"
#include <stdint.h>
#include "app_bsp.h"
#include "stm32f0xx_hal_conf.h"
#include "stm32f070xb.h"


/**------------------------------------------------------------------------------------------------
Brief.- Punto de entrada del programa
-------------------------------------------------------------------------------------------------*/
int main( void )
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    HAL_Init( );

    __HAL_RCC_GPIOA_CLK_ENABLE( );

    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pin   = GPIO_PIN_5;
    HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );
    
    HAL_NVIC_SetPriority(WWDG_IRQn,1,0);
    HAL_NVIC_EnableIRQ(WWDG_IRQn);

    for( ; ; )
    {
        
        HAL_NVIC_SetPendingIRQ(WWDG_IRQn);
        HAL_Delay( 200u );
    }

    return 0u;
}

void WWDG_IRQHandler(void)
{
    HAL_GPIO_TogglePin( GPIOA, GPIO_PIN_5 );
}

