#include "stm32f10x.h"
#include "encoder.h"

#define ENCODER_CLK_PIN     GPIO_Pin_3
#define ENCODER_DT_PIN      GPIO_Pin_4
#define ENCODER_SW_PIN      GPIO_Pin_5
#define ENCODER_GPIO_PORT   GPIOB

#define ENCODER_CLK_READ() \ GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)
#define ENCODER_DT_READ() \ GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define ENCODER_SW_READ() \ GPIO_ReadInputDateBit(GPIOB, GPIO_Pin_5)

typedef enum
{
    ENCODER_NONE = 0,
    ENCODER_LEFT,
    ENCODER_RIGHT,
    ENCODER_PRESS,
}Encoder_Event;

void Encoder_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GOIO_InitStructure.GPIO_Pin = 
        ENCODER_CLK_PIN | 
        ENCODER_DT_PIN  | 
        ENCODER_SW_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHZ;


    GPIO_Init(ENCODER_GPIO_PORT, GPIO_InitStructure);

}

Encoder_Event Encoder_Scan(void)
{
    static uint8_t last_clk = 1;
    static uint8_t last_sw = 1;
    uint8_t clk;
    uint8_t dt;
    uint8_t sw;

    Encoder_Event event = ENCODER_NONE;
    /*check clk down band*/
    if((last_clk == 1) && (clk == 0))
    {
        if(dt == 0)
        {
            event = ENCODER_LEFT;  
        }
        else{
            event = ENCODER_RIGHT;
        }
    }

    /*Check key down band*/
    if((last_sw ==1) && (sw == 0))
    {
        event = ENCODER_PRESS;
    }

    last_clk = clk;
    last_sw = sw;

    
    return event;
}