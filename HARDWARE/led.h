#ifndef __LED_H
#define __LED_H

#include "sys.h"

#define  LEDR GPIO_Pin_15


void LED_Init(void);
void LED_ON(void);
void LED_OFF(void);


#endif




