
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"
#include "api_keypad_driver.h"


int main(void)
{
  HAL_Init();

  enable_gpio_clock(GPIO_CLOCK_C);
  enable_gpio_clock(GPIO_CLOCK_A);
  enable_gpio_clock(GPIO_CLOCK_B);
  configure_gpio_pin(GPIO_PORT_A,0,0x0001);
  configure_gpio_pin(GPIO_PORT_C,13,0x0001);

  api_gpio_config_for_keypad();

  uint8_t pressedKey;

  while(1){

	  pressedKey= api_scan_keypad();
	  if(pressedKey%2 == 0 ){
			  write_gpio_pin(GPIO_PORT_C,13,0);
		  }
		  else{
			  write_gpio_pin(GPIO_PORT_C,13,1);
		  }
		  delay_ms(1000);

	  }
  }



//To do

explore include folder and open api_keypad_driver.h

declare two functions

void api_gpio_config_for_keypad();
//configure the gpio pins of row to output mode and write 0 to all those row pins
//configure the gpio pins of column to input mode

uint8_t api_scan_keypad();


