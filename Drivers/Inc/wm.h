/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Igor Spirin B020777
	*					 Nicholas Davies B225546 
	*          Yusuf Master	B223524
  * @version 99.1
  * @date    06/01/2015
  * @brief   Header files for function declarations
  ******************************************************************************
  */

#ifndef __WM_H
#define __WM_H

//********************************
class DOOR
{
	public:
		bool GetDoorState();

	private:
		bool Door_Status;
};

//********************************
class MOTOR
{
  public:
		void SetMotorClockwise();
		void SetMotorAntiClockWise();
		void SetMotorOn();
		void SetMotorOff();
};

//********************************
class BUZZ
{
	public:
		void SetBuzzerOn();
		void SetBuzzerOff();
};

//********************************
class SEVENSEG
{
	public:
		void SetSevenSegment(int Value);
};

//********************************
class BUTTONS
{
	public:
		void SetLatch();
		void ResetLatch();
		bool GetCancelButtonState();
		bool GetAcceptButtonState();
		int GetSelectState();
		
	private:
		bool AcceptButtonState;
		bool CancelButtonState;
		int ProgramNumber;	
};

//********************************
class TIMER
{
	public:
		void RunTimer(int Time);
		
	private:
		int Time; //TIME IN SECONDS	
};

#endif /* __MAIN_H */





