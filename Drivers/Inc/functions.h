/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Igor Spirin B020777
	*					 Nicholas Davies B225546 
	*          Yusuf Master	B223524
  * @version 99.1
  * @date    06/01/2015
  * @brief   Header file for function code
  ******************************************************************************
  */
	
	
#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "wm.h"
#include "main.h"

// This is needed to make C++ and C work together
extern "C" 
{  
  #include "board_startup.h"   
}

// Pointers to port registers
uint32_t *GPIO_C_Mode_Addr  = (uint32_t *) GPIO_C_MODE;
uint32_t *GPIO_C_Speed_Addr = (uint32_t *) GPIO_C_SPEED;
uint32_t *GPIO_C_Pull_Addr  = (uint32_t *) GPIO_C_PULL;
uint16_t *GPIO_C_Idr_Addr   = (uint16_t *) GPIO_C_IDR;
uint16_t *GPIO_C_Odr_Addr   = (uint16_t *) GPIO_C_ODR;

uint32_t *GPIO_D_Mode_Addr  = (uint32_t *) GPIO_D_MODE;
uint32_t *GPIO_D_Speed_Addr = (uint32_t *) GPIO_D_SPEED;
uint32_t *GPIO_D_Pull_Addr  = (uint32_t *) GPIO_D_PULL;
uint16_t *GPIO_D_Idr_Addr   = (uint16_t *) GPIO_D_IDR;
uint16_t *GPIO_D_Odr_Addr   = (uint16_t *) GPIO_D_ODR;

uint32_t *GPIO_E_Mode_Addr  = (uint32_t *) GPIO_E_MODE;
uint32_t *GPIO_E_Speed_Addr = (uint32_t *) GPIO_E_SPEED;
uint32_t *GPIO_E_Pull_Addr  = (uint32_t *) GPIO_E_PULL;
uint16_t *GPIO_E_Idr_Addr   = (uint16_t *) GPIO_E_IDR;
uint16_t *GPIO_E_Odr_Addr   = (uint16_t *) GPIO_E_ODR;

// Port C - set to output
uint32_t GPIO_C_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_C_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_C_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// Port D - set to output
uint32_t GPIO_D_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_D_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_D_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// Port E - set to input
uint32_t GPIO_E_Mode = 0x00000000;  // 0b00000000000000000000000000000000  00 = input, 01 = output
uint32_t GPIO_E_Pull = 0x55555555;    // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

//Functions 

//******************************** DOOR *********************************
bool DOOR::GetDoorState()
{
	bool Door_Status = (*GPIO_E_Idr_Addr) & DOORE;
	return Door_Status;
}

//******************************** MOTOR ********************************
void MOTOR::SetMotorClockwise()
{
	*GPIO_D_Odr_Addr &= ~(uint16_t) MOTORD; 
}
	
void MOTOR::SetMotorAntiClockWise()
{
	*GPIO_D_Odr_Addr |= (uint16_t) MOTORD;
}

void MOTOR::SetMotorOn()
{
	*GPIO_D_Odr_Addr |= (uint16_t) MOTORC;
}

void MOTOR::SetMotorOff()
{
	*GPIO_D_Odr_Addr &= ~(uint16_t) MOTORC;
}

//******************************** BUZZER *******************************
void BUZZ::SetBuzzerOn()
{
	*GPIO_C_Odr_Addr |= (uint16_t) BUZZER; 
}
void BUZZ::SetBuzzerOff()
{
	*GPIO_C_Odr_Addr &= ~(uint16_t) BUZZER; 
}

//******************************** SEVEN SEGMENT ************************
void SEVENSEG::SetSevenSegment(int Value)
{
	*GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00; //Output '0000'

	if (Value <= 0 || Value > 9) // Blank for any values outside of the range
	{
		Value =15;
	}

	if (Value >= 8)
	{
		*GPIO_D_Odr_Addr |= (uint16_t) S7D;   // Turn on bit D MSB
		Value = Value -8;
	}
	if (Value >= 4)
	{
		*GPIO_D_Odr_Addr |= (uint16_t) S7C;   // Turn on bit C	
		Value = Value -4;
	}
	if (Value >= 2)
	{
		*GPIO_D_Odr_Addr |= (uint16_t) S7B;   // Turn on bit B
		Value = Value -2;
	}
	if (Value == 1)
	{
		*GPIO_D_Odr_Addr |= (uint16_t) S7A;   // Turn on bit A LSB
	}	
}

//******************************** BUTTON *******************************
bool BUTTONS::GetAcceptButtonState()
{
	AcceptButtonState = (*GPIO_E_Idr_Addr) & ACCEPT ;  // PE12 accept switch 
	return AcceptButtonState;
}
bool BUTTONS::GetCancelButtonState()
{
	CancelButtonState = (*GPIO_E_Idr_Addr) & CANCEL ;  // PE12 accept switch
	return CancelButtonState;
}
int BUTTONS::GetSelectState()
{
	bool Button1 = (*GPIO_E_Idr_Addr) & PROG1 ;  // PE8  programme select 1 (rightmost)
	
	bool Button2 = (*GPIO_E_Idr_Addr) & PROG2 ;  // PE9  programme select 2 (middle)
	
  bool Button3 = (*GPIO_E_Idr_Addr) & PROG3 ;  // PE10 programme select 3 (leftmost)
	
	int ProgramNumber = 1;	
	if (Button1)
		ProgramNumber=ProgramNumber+1;
	if (Button2)
		ProgramNumber=ProgramNumber+2;
	if (Button3)
		ProgramNumber=ProgramNumber+4;
	return (ProgramNumber);
}
void BUTTONS::SetLatch()
{
	*GPIO_D_Odr_Addr |= (uint16_t) RESET;  
}
void BUTTONS::ResetLatch()
{
	*GPIO_D_Odr_Addr &= ~(uint16_t) RESET;  
}

//******************************** TIMER ********************************
void TIMER::RunTimer(int Time) 
{
	HAL_Delay(1000*Time);
}

#endif /* __FUNCTIONS */
