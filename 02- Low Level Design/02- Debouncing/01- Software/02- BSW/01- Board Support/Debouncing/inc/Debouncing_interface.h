/****************************************************************************
* Title                 :   Debouncing   
* Filename              :   Debouncing_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   17/03/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
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
*  17/03/21   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  Debouncing_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef Debouncing_INTERFACE_H_
#define Debouncing_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define E_NOK            0
#define E_OK             1
/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct _debouncingDevice
{
   EXTI_InterruptId_t InterruptId;
   u8                 DeviceCurrentState;
   u8                 DeviceOldState;
   u8                 StateVariable;
   Stack_t            DebouncingStack;
}DebouncingDevice_t;
/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
u8 HDebouncing_u8Constructor(DebouncingDevice_t   * Copy_PtrToClass, EXTI_InterruptId_t Copy_u8InterruptId);
u8 HDebouncing_u8Deconstructor(DebouncingDevice_t * Copy_PtrToClass);
u8 HDebouncing_u8MainFunction(DebouncingDevice_t  * Copy_PtrToClass, u8 * Copy_PtrToDeviceStatus);

#endif /*File_H_*/

/*** End of File **************************************************************/
