#include "main.h"

void config(void);
void led1(void);
void led2(void);
void led3(void);
void led4(void);
#define STACK_SIZE_MIN	128	/* usStackDepth	- the stack size DEFINED IN WORDS.*/
int main(void)
{
	HAL_Init();
	/* Configure the system clock to 168 MHz */
	System_Clock_Config();
	/* Infinite loop */
	config();

	xTaskCreate( led1, (const signed char*)"Read BH1750", 
		STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( led2, (const signed char*)"Read SHT15", 
		STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	// xTaskCreate( led3, (const signed char*)"Read pH mater", 
	// 	STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	// xTaskCreate( led4, (const signed char*)"LCD", 
	// 	STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );

	vTaskStartScheduler();

	return 0;
}

void config(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
 __GPIOD_CLK_ENABLE();
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void led1(void)
{
	ResetDevice();
    SetBacklight(0xff);
 	vTaskDelay( 200 / portTICK_RATE_MS );
    ClearDevice(0,0,800,480,White);
    GUI();
  while (1)
  {
  }
}
void led2(void)
{
	while(1)
	{
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); 
	 vTaskDelay( 200 / portTICK_RATE_MS );
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); 
	 vTaskDelay( 200 / portTICK_RATE_MS );
	}
}
void led3(void)
{
	while(1)
	{
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	 vTaskDelay( 200 / portTICK_RATE_MS );
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); 
	 vTaskDelay( 200 / portTICK_RATE_MS );
	}
}
void led4(void)
{
	while(1)
	{
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);	
	 vTaskDelay( 200 / portTICK_RATE_MS );
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET); 
	 vTaskDelay( 200 / portTICK_RATE_MS );
	}
}