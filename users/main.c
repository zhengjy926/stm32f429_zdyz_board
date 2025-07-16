/**
  ******************************************************************************
  * @file        : main.c
  * @author      : ZJY
  * @version     : V1.0
  * @data        : 20xx-xx-xx
  * @brief       : 
  * @attattention: None
  ******************************************************************************
  * @history     :
  *         V1.0 : 1.xxx
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "board.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/**
 * @brief  main function
 * @param  None
 * @retval None
 */
int main(void)
{
#if USING_RTOS
    __set_PRIMASK(1);
#endif // USING_RTOS
    
    /* 初始化系统 */
    board_init();
    
    /* 检查HAL版本 */
    if (HAL_GetHalVersion() != STM32_HAL_SW_VERSION) {
//        LOG_D("HAL version mismatch: expected 0x%08X, got 0x%08X\r\n", 
//              STM32_HAL_SW_VERSION, HAL_GetHalVersion());
        while (1);
    }
    
    while(1)
    {
        
    }
}

