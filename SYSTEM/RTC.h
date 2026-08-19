#ifndef __RTC_H
#define __RTC_H

extern int RTC_Time[];

void RTC_Init(void);
void RTC_SetTime(void);
void RTC_ReadTime(void);

#endif
