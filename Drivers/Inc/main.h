/**
  ******************************************************************************
  * @file    main.h
  * @author  Igor Spirin B020777
	*					 Nicholas Davies B225546 
	*          Yusuf Master	B223524
  * @version 99.1
  * @date    06/01/2015
  * @brief   Contains various pointer definitions and maps ports to names.
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3_discovery.h"

// Port base addresses
#define GPIO_C_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000800
#define GPIO_D_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000C00
#define GPIO_E_BASE_ADDR  0x40000000 + 0x08000000 + 0x00001000

// Port register addresses
#define GPIO_C_MODE  (GPIO_C_BASE_ADDR)
#define GPIO_C_SPEED (GPIO_C_BASE_ADDR + 0x08)
#define GPIO_C_PULL  (GPIO_C_BASE_ADDR + 0x0C)
#define GPIO_C_IDR   (GPIO_C_BASE_ADDR + 0x10)
#define GPIO_C_ODR   (GPIO_C_BASE_ADDR + 0x14)

#define GPIO_D_MODE  (GPIO_D_BASE_ADDR)
#define GPIO_D_SPEED (GPIO_D_BASE_ADDR + 0x08)
#define GPIO_D_PULL  (GPIO_D_BASE_ADDR + 0x0C)
#define GPIO_D_IDR   (GPIO_D_BASE_ADDR + 0x10)
#define GPIO_D_ODR   (GPIO_D_BASE_ADDR + 0x14)

#define GPIO_E_MODE  (GPIO_E_BASE_ADDR)
#define GPIO_E_SPEED (GPIO_E_BASE_ADDR + 0x08)
#define GPIO_E_PULL  (GPIO_E_BASE_ADDR + 0x0C)
#define GPIO_E_IDR   (GPIO_E_BASE_ADDR + 0x10)
#define GPIO_E_ODR   (GPIO_E_BASE_ADDR + 0x14)

// Defining ports
#define BUZZER  0x0040  // BUZZER PC6
#define S7A  0x0100  //SEVEN SEGMENT PD8 
#define S7C  0x0400  // SEVEN SEGMENT PD10
#define S7B  0x0800   // SEVEN SEGMENT PD11
#define MOTORC  0x1000  // MOTOR CONTROL PD12
#define S7D 0x2000  // SEVEN SEGMENT PD13
#define RESET  0x4000  // SWITCH RESET PD14
#define MOTORD 0x8000  // MOTOR DIRECTION PD15

#define PROG1  0x0100  // PROGRAM ONE PE8
#define DOORE  0x0800  //DOOR PE9 
#define	PROG3  0x0400 // PROGRAM THREE PE10
#define PROG2  0x0200   // PR0GRAM TWO PE11
#define ACCEPT  0x1000  // ACCEPT PE12
#define CANCEL 0x2000  // CANCEL PE13
#define MOTORS 0x8000  // MOTOR SPEED PE15

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
