#ifndef __GPIO_BASE_H_
#define __GPIO_BASE_H_

#include "target_mcu.h"
#include "stm32_assert_template.h"
/**
  *@brief ebox gpio接口基类，仅在使用af功能时创建。不具备读写功能
  */
class E_PinBase{
protected:
  GPIO_TypeDef *_port;
  uint16_t _pin;
public:
  E_PinID _id;

  E_PinBase(E_PinID pin){
    {
      _pin = GETPIN(pin);
      _id = pin;

      switch (GETPORTINDEX(_id))
      {
      case E_PORTA:
        _port = GPIOA;
        break;
      case E_PORTB:
        _port = GPIOB;
        break;
#ifdef GPIOC
      case E_PORTC:
        _port = GPIOC;
        break;
#endif
#ifdef GPIOD
      case E_PORTD:
        break;
#endif
#ifdef GPIOE
      case E_PORTE:
        _port = GPIOE;

        break;
#endif
#ifdef GPIOF
      case E_PORTF:
        _port = GPIOF;
        break;
#endif
      default:
        break;
      }
      EnableGPIOClock(GPIO_INFO[GETPORTINDEX(_id)]);
    }
  }
  
  void mode(E_PinMode mode,uint8_t af){
    assert_param(af>8);  		//af最大为7

    LL_GPIO_SetPinMode(this->_port,this->_pin,GET_MODE(mode));
    LL_GPIO_SetPinOutputType(this->_port,this->_pin,GET_OTYPER(mode));
    LL_GPIO_SetPinPull(this->_port,this->_pin,GET_PUPD(mode));
    LL_GPIO_SetPinSpeed(this->_port,this->_pin,LL_GPIO_SPEED_FREQ_HIGH);

    (_pin<LL_GPIO_PIN_8)?(LL_GPIO_SetAFPin_0_7(_port,_pin,af)):(LL_GPIO_SetAFPin_8_15(_port,_pin,af));
  }
};

#endif
