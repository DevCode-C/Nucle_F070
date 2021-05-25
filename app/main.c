#include "stm32f0xx.h"
#include <stdint.h>
#include "app_bsp.h"
// #include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_conf.h"
#include "stm32f070xb.h"
#include "stm32f0xx_hal.h"

/**------------------------------------------------------------------------------------------------
Brief.- Punto de entrada del programa
-------------------------------------------------------------------------------------------------*/
uint32_t tickTimer0;
uint32_t tickTimer1;
uint32_t tickTimer2;
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

    __HAL_RCC_GPIOC_CLK_ENABLE();
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pin   = GPIO_PIN_0 |GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4;
    HAL_GPIO_Init(GPIOC,&GPIO_InitStruct);

    GPIO_InitStruct.Mode  = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pin   = GPIO_PIN_13;
    HAL_GPIO_Init(GPIOC,&GPIO_InitStruct);

    GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pin   = GPIO_PIN_0 | GPIO_PIN_1;
    HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
    
    HAL_NVIC_SetPriority(EXTI4_15_IRQn,1,0);
    HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

    HAL_NVIC_SetPriority(EXTI0_1_IRQn,1,0);
    HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);
    
    tickTimer0 = HAL_GetTick();
    tickTimer1 = HAL_GetTick();
    tickTimer2 = HAL_GetTick();
    for( ; ; )
    {
        if((HAL_GetTick()-tickTimer0)>=100)
        {
            tickTimer0 = HAL_GetTick();
            HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_0);
        }
        if ((HAL_GetTick() - tickTimer1)>=300)
        {
            tickTimer1 = HAL_GetTick();
            HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_2);
        }
        if ((HAL_GetTick() - tickTimer2)>=500)
        {
            tickTimer2 = HAL_GetTick();
            HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_4);
        }
    }

    return 0u;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_PIN)
{
    if (GPIO_PIN == GPIO_PIN_0)
    {
        HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_1);
    }
    else if (GPIO_PIN == GPIO_PIN_1)
    {
        HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_3);
    }
    else if (GPIO_PIN == GPIO_PIN_13)
    {
        HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
    }
    
    
    
}
