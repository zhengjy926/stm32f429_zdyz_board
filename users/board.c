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

#include <stdio.h>
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
DEFINE_GPIO_LED(red_led, "PB.0", 1, LED_OFF, LED_FULL);
DEFINE_GPIO_LED(green_led, "PB.1", 1, LED_OFF, LED_FULL);

/* Exported variables  -------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static int gpio_led_static_init(void)
{
    int ret;
    
    /* 初始化GPIO LED子系统 */
    ret = gpio_led_init();
    if (ret != 0) {
        printf("Failed to initialize GPIO LED subsystem: %d\n", ret);
        return ret;
    }
    
    /* 注册LED */
    ret = gpio_led_register(&red_led);
    if (ret != 0) {
        printf("Failed to register red LED: %d\n", ret);
        return ret;
    }
    ret = gpio_led_register(&green_led);
    if (ret != 0) {
        printf("Failed to register green LED: %d\n", ret);
        return ret;
    }
    
    return 0;
}

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
    
    ret = gpio_led_static_init();
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

