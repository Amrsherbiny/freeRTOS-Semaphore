/*
 * RTOS_2_SEMAPHORE.c
 *
 * Created: 1/19/2018 9:57:00 AM
 *  Author: Amr
 */ 

#include "FreeRTOS.h"
#include "STDMACROS.h"
#include "semphr.h"

uint16_t x = 0;
uint16_t y = 0;

SemaphoreHandle_t myMutex;

void T1(void *pv)
{
	DDRD |= (1<<7);
	while(1)
	{
		xSemaphoreTake(myMutex,1000);
		if(x != y)
		{
			PORTD ^= (1<<7);
		}
		xSemaphoreGive(myMutex);
		vTaskDelay(100);
	}	
}
void T2(void *pv)
{
	while(1)
	{
		xSemaphoreTake(myMutex,1000);
		x++;
		_delay_ms(200);
		y++;
		xSemaphoreGive(myMutex);
	}		
}

int main(void)
{
    myMutex = xSemaphoreCreateMutex();
	xTaskCreate(T1," ",100,NULL,2,NULL);
	xTaskCreate(T2," ",100,NULL,1,NULL);
	vTaskStartScheduler();
}