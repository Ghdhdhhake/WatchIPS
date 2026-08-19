#include "stm32f10x.h"
#include "led.h"


void LED_Init(void)
{
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能B端口时钟
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //初始化GPIOA
 	GPIO_SetBits(GPIOB, LEDR);
}

void LED_ON(void)
{
	GPIO_ResetBits(GPIOB, LEDR);
}

void LED_OFF(void)
{
	GPIO_SetBits(GPIOB, LEDR);
}


