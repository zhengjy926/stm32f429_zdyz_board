/**
  ******************************************************************************
  * @copyright   : Copyright To Hangzhou Dinova EP Technology Co.,Ltd
  * @file        : board.h
  * @author      : ZJY
  * @version     : V1.0
  * @date        : 2025-05-30
  * @brief       : Board support package header file
  * @attention   : None
  ******************************************************************************
  * @history     :
  *         V1.0 : 1.Enhanced board configuration
  ******************************************************************************
  */
#ifndef __BOARD_H__
#define __BOARD_H__

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#ifdef STM32F429xx
    #include "stm32f4xx_hal.h"
#elif STM32G474xx
    #include "stm32g4xx_hal.h"
#endif

#include "sys_config.h"

/* Exported define -----------------------------------------------------------*/
/**
  * @brief STM32 HAL Driver version number
  */
#define STM32_HAL_SW_VERSION            (0x01080400U)

#if defined(HAL_SPI_MODULE_ENABLED)
    #define BSP_USING_SPI4
    
    #define BSP_USING_SPI5
    #define BSP_SPI5_RX_USING_DMA
    #define BSP_SPI5_TX_USING_DMA
    #define SPI5_GPIO_PORT              GPIOF
    #define SPI5_SCK_PIN                GPIO_PIN_7
    #define SPI5_MISO_PIN               GPIO_PIN_8
    #define SPI5_MOSI_PIN               GPIO_PIN_9
#endif // HAL_SPI_MODULE_ENABLED
/* Exported typedef ----------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported variable prototypes ----------------------------------------------*/
/* Exported function prototypes ----------------------------------------------*/
int board_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BOARD_H__ */

