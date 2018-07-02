 /**
  ******************************************************************************
  * @file    main.cpp
  * @author  cat_Li
  * @version V1.2
  * @date    2018/05/06
  * @brief   主程序入口
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
#include "bsp.h"

void setup()
{
	ebox_init();
	LED.mode(OUTPUT_PP_PU);
	usart.begin(115200);
}

int main(void)
{
    setup();
    while(1)
    {
			LED.toggle();
			delay_ms(1000);
		}
}




