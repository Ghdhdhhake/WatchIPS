/*
 * WatchIPS main program
 *
 * LCD:
 *   PA0 SCLK, PA1 MOSI, PA2 RES
 *   PA3 DC,   PA4 CS,   PA5 BLK
 *
 * Rotary encoder:
 *   PB3 CLK, PB4 DT, PB5 SW
 */
#include "delay.h"
#include "lcd_init.h"
#include "menu.h"

int main(void)
{
    delay_init();
    LCD_Init();
    Peripheral_Init();
    WatchHome_Init();

    while (1)
    {
        WatchHome_Update();
    }
}
