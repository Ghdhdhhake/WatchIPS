#include "stm32f10x.h"
#include "menu.h"
#include "RTC.h"
#include "encoder.h"
#include "led.h"
#include "lcd.h"
#include "lcd_init.h"

static uint8_t WatchHome_Selection;
static int WatchHome_LastSecond = -1;

static void WatchHome_DrawHeader(void);
static void WatchHome_DrawDateTime(void);
static void WatchHome_DrawButtons(void);
static void WatchHome_ShowPressed(void);

void Peripheral_Init(void)
{
    RTC_Init();
    Encoder_Init();
    LED_Init();
}

void WatchHome_Init(void)
{
    WatchHome_Selection = 0;
    WatchHome_LastSecond = -1;
    LCD_Fill(0, 0, LCD_W, LCD_H, BLACK);
    WatchHome_DrawHeader();
    WatchHome_DrawDateTime();
    WatchHome_DrawButtons();
}

void WatchHome_Update(void)
{
    Encoder_Event event;

    event = Encoder_Scan();
    if (event == ENCODER_LEFT)
    {
        WatchHome_Selection = 0;
        WatchHome_DrawButtons();
    }
    else if (event == ENCODER_RIGHT)
    {
        WatchHome_Selection = 1;
        WatchHome_DrawButtons();
    }
    else if (event == ENCODER_PRESS)
    {
        WatchHome_ShowPressed();
    }

    RTC_ReadTime();
    if (RTC_Time[5] != WatchHome_LastSecond)
    {
        WatchHome_DrawDateTime();
    }
}

static void WatchHome_DrawHeader(void)
{
    LCD_ShowString(84, 18, (const u8 *)"WATCH IPS",
                   CYAN, BLACK, 16, 0);
    LCD_DrawLine(24, 42, 216, 42, GRAYBLUE);
}

static void WatchHome_DrawDateTime(void)
{
    RTC_ReadTime();

    LCD_ShowIntNum(56, 66, (u16)RTC_Time[3], 2, WHITE, BLACK, 32);
    LCD_ShowChar(88, 66, ':', WHITE, BLACK, 32, 0);
    LCD_ShowIntNum(104, 66, (u16)RTC_Time[4], 2, WHITE, BLACK, 32);
    LCD_ShowChar(136, 66, ':', WHITE, BLACK, 32, 0);
    LCD_ShowIntNum(152, 66, (u16)RTC_Time[5], 2, WHITE, BLACK, 32);

    LCD_ShowIntNum(80, 112, (u16)RTC_Time[0], 4, LIGHTBLUE, BLACK, 16);
    LCD_ShowChar(112, 112, '-', LIGHTBLUE, BLACK, 16, 0);
    LCD_ShowIntNum(120, 112, (u16)RTC_Time[1], 2, LIGHTBLUE, BLACK, 16);
    LCD_ShowChar(136, 112, '-', LIGHTBLUE, BLACK, 16, 0);
    LCD_ShowIntNum(144, 112, (u16)RTC_Time[2], 2, LIGHTBLUE, BLACK, 16);

    WatchHome_LastSecond = RTC_Time[5];
}

static void WatchHome_DrawButtons(void)
{
    u16 menu_color;
    u16 set_color;

    menu_color = (WatchHome_Selection == 0) ? DARKBLUE : GRAY;
    set_color = (WatchHome_Selection == 1) ? DARKBLUE : GRAY;

    LCD_Fill(20, 184, 110, 224, menu_color);
    LCD_Fill(130, 184, 220, 224, set_color);
    LCD_DrawRectangle(20, 184, 110, 224, WHITE);
    LCD_DrawRectangle(130, 184, 220, 224, WHITE);
    LCD_ShowString(45, 196, (const u8 *)"MENU",
                   WHITE, menu_color, 16, 0);
    LCD_ShowString(163, 196, (const u8 *)"SET",
                   WHITE, set_color, 16, 0);
}

static void WatchHome_ShowPressed(void)
{
    LCD_Fill(48, 146, 192, 166, BLACK);
    if (WatchHome_Selection == 0)
    {
        LCD_ShowString(72, 148, (const u8 *)"MENU PRESSED",
                       YELLOW, BLACK, 16, 0);
    }
    else
    {
        LCD_ShowString(76, 148, (const u8 *)"SET PRESSED",
                       YELLOW, BLACK, 16, 0);
    }
}
