 /**
  ******************************************************************************
  * @file    bsp.cpp
  * @author  cat_Li
  * @version V1.0
  * @date    2018/05/06
  * @brief   硬件相关
  ******************************************************************************
  * @attention
  *
  * No part of this software may be used for any commercial activities by any form 
  * or means, without the prior written consent of shentq. This specification is 
  * preliminary and is subject to change at any time without notice. shentq assumes
  * no responsibility for any errors contained herein.
  * <h2><center>&copy; Copyright 2015 shentq. All Rights Reserved.</center></h2>
  ******************************************************************************
  */

#include "ebox.h"

void SystemClock_Config(void)
{
    /* Configuration will allow to reach a SYSCLK frequency set to 24MHz:
     Syst freq = ((HSI_VALUE * PLLMUL)/ PLLDIV)
    						 ((8MHz * 12)/ 2)                  = 48MHz             */
    LL_UTILS_PLLInitTypeDef sUTILS_PLLInitStruct = {LL_RCC_PLL_MUL_12 , LL_RCC_PREDIV_DIV_2};
    /* Variable to store AHB and APB buses clock configuration */
    /* Settings to have HCLK set to 48MHz and APB to 48 MHz */
    LL_UTILS_ClkInitTypeDef sUTILS_ClkInitStruct = {LL_RCC_SYSCLK_DIV_1, LL_RCC_APB1_DIV_1};

    /* Switch to PLL with HSI as clock source             */
    LL_PLL_ConfigSystemClock_HSI(&sUTILS_PLLInitStruct, &sUTILS_ClkInitStruct);
}




