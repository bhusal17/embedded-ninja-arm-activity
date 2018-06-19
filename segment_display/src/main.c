
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"
#include "api_7segment_driver.h"

uint8_t ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

//uint8_t newch[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

int main(void)
{

 // int number = 0;
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
  enable_gpio_clock(GPIO_CLOCK_B);


//Configuring the pins connected to 7-segment as output pins
 api_gpio_config_for_7segment();
 
 while(1){
	  for(uint8_t i=0; i<9; i++){
		  api_7segment_out(ch[i]);
		  delay_ms(500);
	  }
  }

}





