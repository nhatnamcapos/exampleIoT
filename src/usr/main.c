#include "main.h"
#include "configureSystemF4.h"
#include "cmsis_os.h"
int main(void)
{
	HAL_Init();
	/* Configure the system clock to 168 MHz */
	System_Clock_Config();
	/* Infinite loop */
	return 0;
}


