/****************************************************************************
* Title                 :   SWC1   
* Filename              :   SWC1_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   16/01/2021
* Version               :   1.0.0
* Compiler              :   ARM Compiler Version 6
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None
*
*****************************************************************************/
/****************************************************************************
* Doxygen C Template 
*
*****************************************************************************/
/*************** INTERFACE CHANGE LIST **************************************
*
*    Date    Version   Author          Description 
*  16/01/21   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  SWC1_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef SWC1_INTERFACE_H_
#define SWC1_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void SWC1_voidInitalizePeripherals(void);
void Task1_Blinky_Red(void    * Copy_voidPointer);
void Task2_Blinky_Yellow(void * Copy_voidPointer);

#endif /*File_H_*/

/*** End of File **************************************************************/
