/******************************************************************************
程 序 名： bsp.h　
编 写 人： cat_li
编写时间： 2018年05月06日
相关平台： nucleo-f072rb
修改日志：　　
	NO.1-  初始版本
******************************************************************************/

#ifndef __BSP_SPARK_H_
#define __BSP_SPARK_H_

#include "ebox.h"

#define CPU_SERIES			"STM32F0XX_"
#define CMSIS_VERSION   __STM32F0_DEVICE_VERSION

E_GPIO LED(PA_5);
E_UART usart(USART2,UART2_TX,UART2_RX);

#endif
