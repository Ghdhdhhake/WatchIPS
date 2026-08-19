//  功能描述   :WatchIPS(STM32F103系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND   电源地
//              VCC   3.3v电源
//              SCL   PA0（SCLK）
//              SDA   PA1（MOSI）
//              RES   PA2
//              DC    PA3
//              CS    PA4
//              BLK   PA5
//              ----------------------------------------------------------------
// 日    期   : 2026-8-19
// 作    者   : Javi
//******************************************************************************/
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include "Timer.h"
#include "encoder.h"
#include "menu.h"

int main(void)
{
	delay_init();
	LED_Init();//LED初始化
	LCD_Init();//LCD初始化
	while(1)
	{
		LCD_ShowChinese(0,0,"中电子",RED,WHITE,32,0);
		LCD_ShowString(0,40,"LCD_W:",RED,WHITE,16,0);
		LCD_ShowIntNum(48,40,LCD_W,3,RED,WHITE,16);
		LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
		LCD_ShowIntNum(128,40,LCD_H,3,RED,WHITE,16);
		LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
		LCD_ShowString(0,70,"Increaseing Nun:",RED,WHITE,16,0);
		LCD_ShowFloatNum1(128,70,t,4,RED,WHITE,16);
	
	}
}

