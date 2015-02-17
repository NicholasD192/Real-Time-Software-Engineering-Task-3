/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Igor Spirin B020777
	*					 Nicholas Davies B225546 
	*          Yusuf Master	B223524
  * @version 99.1
  * @date    06/01/2015
  * @brief   Code for the washing machine driver test
  ******************************************************************************
  */

#include "functions.h"
#include "main.h"
#include "wm.h"

// All the washing machine test code is in here
int main(void)
{
  // STM32F3 Discovery Board initialization
  board_startup();

  // Configure port C
  *GPIO_C_Mode_Addr =  (uint32_t) GPIO_C_Mode;
  *GPIO_C_Speed_Addr = (uint32_t) GPIO_C_Speed;
  *GPIO_C_Pull_Addr =  (uint32_t) GPIO_C_Pull;

  // Configure port D
  *GPIO_D_Mode_Addr =  (uint32_t) GPIO_D_Mode;
  *GPIO_D_Speed_Addr = (uint32_t) GPIO_D_Speed;
  *GPIO_D_Pull_Addr =  (uint32_t) GPIO_D_Pull;

  // Configure port E
  *GPIO_E_Mode_Addr =  (uint32_t) GPIO_E_Mode;
  *GPIO_E_Pull_Addr =  (uint32_t) GPIO_E_Pull;

  // Hold a bit value returned from a port
	MOTOR Motor;
	DOOR Door;
	TIMER timer;
	SEVENSEG sevensegment;
	BUZZ buzzer;
	BUTTONS button;
	
	// Setup initial latch
	button.SetLatch();
	
	// Run test code 
	while(1)
	{
		//Checks if accept button has been pressed
		if (button.GetAcceptButtonState()) 
		{		
			buzzer.SetBuzzerOff();
			sevensegment.SetSevenSegment(button.GetSelectState());
			timer.RunTimer(2);
			button.ResetLatch();	
		  button.SetLatch();			
		}
		else if (button.GetCancelButtonState()) 
		{
		  buzzer.SetBuzzerOn();
		  timer.RunTimer(2);
		  buzzer.SetBuzzerOff();	
		  button.ResetLatch();
			sevensegment.SetSevenSegment(0);
		  button.SetLatch();			
		}	
		if (Door.GetDoorState())
		{
			Motor.SetMotorAntiClockWise();
			Motor.SetMotorOn();
			timer.RunTimer(2);
			Motor.SetMotorClockwise();
			timer.RunTimer(2);
		}
		else
		{
			Motor.SetMotorOff();
		}
	}
}

