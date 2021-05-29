
#include "stm32f0xx.h"
#include <stdint.h>
#include "app_bsp.h"
#include "stm32f0xx_hal_conf.h"
#include "stm32f070xb.h"


/**------------------------------------------------------------------------------------------------
Brief.- Punto de entrada del programa
-------------------------------------------------------------------------------------------------*/
void NMI_Handler( void )
{

}

/**------------------------------------------------------------------------------------------------
Brief.- Punto de entrada del programa
-------------------------------------------------------------------------------------------------*/
void HardFault_Handler( void )
{
    assert_param( 0u );
}

/**------------------------------------------------------------------------------------------------
Brief.- Punto de entrada del programa
-------------------------------------------------------------------------------------------------*/
void SVC_Handler( void )
{

}

/**------------------------------------------------------------------------------------------------
Brief.- Punto de entrada del programa
-------------------------------------------------------------------------------------------------*/
void PendSV_Handler( void )
{

}

/**------------------------------------------------------------------------------------------------
Brief.- Punto de entrada del programa
-------------------------------------------------------------------------------------------------*/
void SysTick_Handler( void )
{
    HAL_IncTick( );
}

void EXTI4_15_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}

void EXTI0_1_IRQHandler(void)
{
    // EXTI_HandleTypeDef pendingBit;
    // pendingBit.Line = 0;
    // uint32_t pending = EXTI->PR;
    
    // if (HAL_EXTI_GetPending(&pendingBit,GPIO_MODE_IT_RISING))
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0))
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
    }
    // if (HAL_EXTI_GetPending(&pendingBit,GPIO_MODE_IT_RISING))
    else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1))
    {
       HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
    }
    
}