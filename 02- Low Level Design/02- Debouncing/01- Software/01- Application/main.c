/*******************************************************************************
* Title                 :   main  
* Filename              :   main.c
* Author                :   Mohamed Hafez
* Origin Date           :   04/08/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  04/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file main.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/		
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdlib.h>
#include "STACK_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "Debouncing_interface.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
int main()
{
	EXTI_Lines_t lines[1] = {LINE0};
	AFIO_ExtiPin ports[1] = {LINE_PIN_B};	
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , IOPA_PERIPHERAL);
	MRCC_voidEnableClock(RCC_APB2 , IOPB_PERIPHERAL);
	MGPIO_voidSetPinMode(PINA0,GPIO_OUTPUT_2M_PULL_UP_DN);
	MSTK_voidInit();
	MAFIO_u8SetExtiConfiguration(1,lines,ports);
	MEXTI_u8Init(1, lines, RISING);
	MEXTI_u8EnableEXTI(1, lines);
	MNVIC_u8SetPriority(EXTI0, 0b00, 0b00);
	MNVIC_u8EnableInt(EXTI0);
	DebouncingDevice_t Local_Switch;
	u8 Local_u8witchStatus = 0;
	HDebouncing_u8Constructor(&Local_Switch, EXTI0_ID);
  while(1)
  {
	  HDebouncing_u8MainFunction(&Local_Switch, &Local_u8witchStatus);
	  if(Local_u8witchStatus)
	  {
		  MGPIO_voidSetPinValue(PINA0,HIGH);
	  }
  }

}




/*************** END OF FUNCTIONS ***************************************************************************/
