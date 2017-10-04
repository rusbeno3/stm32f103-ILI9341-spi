#include "delay.h"

volatile u32 tick = 0;

void SysTick_Handler(void)
{
  tick++;
}

inline void delay(uint32_t time, uint32_t load)
{
  tick = 0;
  SysTick_Config(load);
  do
  {
    while (!(SysTick->CTRL && SysTick_CTRL_COUNTFLAG_Msk));
  }
  while (tick < time);
  SysTick->CTRL = 0;
}

inline void delay_ms(uint32_t time) 
{
  delay(time, SystemCoreClock / 1000);
}

inline void delay_us(uint32_t time) 
{
  delay(time, SystemCoreClock / 1000000);
}
