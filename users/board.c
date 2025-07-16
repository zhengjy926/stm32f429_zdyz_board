/**
  ******************************************************************************
  * @copyright   : Copyright To Hangzhou Dinova EP Technology Co.,Ltd
  * @file        : board.c
  * @author      : ZJY
  * @version     : V1.0
  * @date        : 2025-01-27
  * @brief       : Board support package implementation
  * @attention   : None
  ******************************************************************************
  * @history     :
  *         V1.0 : 1.Enhanced board initialization
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "board.h"
#include "stm32_gpio.h"
#include "stm32_usart.h"
#include "stm32_clk.h"

#include "led_gpio.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Exported variables  -------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/**
 * @brief  Board initialization function
 * @param  None
 * @retval 0 on success, negative on error
 */
int board_init(void)
{
    int ret = 0;
    
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();
    SystemClock_Config();   /* Configure the system clock */
    
    /* Initialize all configured peripherals */
    stm32_gpio_init();
    
    ret = hw_usart_init();
    if (ret != 0) {
        while(1);
    }
    
    
    
    return 0;
}

/**
  * @brief  Initializes the Global MSP
  * @retval None
  */
void HAL_MspInit(void)
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();
#if USING_RTOS
    HAL_NVIC_SetPriority(PendSV_IRQn, 15, 0);
#endif
}

/* Private functions ---------------------------------------------------------*/

