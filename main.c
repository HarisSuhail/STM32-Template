#include "stm32f10x_conf.h"
#include "stm32f10x.h"
#include <system_stm32f10x.h>



void delay()
{
  for(unsigned int loopIndex = 0; loopIndex < 65000u; loopIndex++)
  {
    for(unsigned int loopIndex2 = 0; loopIndex2 < 10u; loopIndex2++)
    {
    //Do Nothing
    }
  }
}

int main()
{
  //Enable GPIOA Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  //Set up configuration for LED pin which is at PA4
  GPIO_InitTypeDef LD2PinGpioTypeDef;
  LD2PinGpioTypeDef.GPIO_Pin = (1u<<5);
  LD2PinGpioTypeDef.GPIO_Speed = GPIO_Speed_2MHz;
  LD2PinGpioTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;
  
  // Initialize PA4
  GPIO_Init(GPIOA, &LD2PinGpioTypeDef);
  
  
  
  while(1)
  {
    GPIO_WriteBit(GPIOA, (1u<<5), Bit_SET);
    delay();
    GPIO_WriteBit(GPIOA, (1u<<5), Bit_RESET);
    delay();
  }
  
}
