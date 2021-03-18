/****************************************************************************
* Title                 :   Debouncing   
* Filename              :   Debouncing_private.h
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
/** @file  Debouncing_private.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef Debouncing_PRIVATE_H_
#define Debouncing_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef enum
{
   IDLE_STATE,
   PROCESS_EVENT_STATE,
   CHECK_DEVICE_STATE,
   NUMBER_OF_STATES
 }DebouncingStates;
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define DEVICE_IS_ON                 1
#define DEVICE_IS_OFF                0
#define CLEAR_FLAG                   0
#define EVENT_OCCURRED               1
#define INITIALIZED_WITH_ZERO        0
#define INITIALIZED_WITH_ONE         1
#define DEVICE_OPEN                  0
#define DEVICE_CLOSED                1
#define DEVICE_INITIAL_STATE         DEVICE_OPEN
/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
static void HDebouncing_CallbackInExti(void      * Copy_PtrTovoid);
static void HDebouncing_CallbackInTimer(void     * Copy_PtrTovoid);

static void HDebouncing_voidIdleState(void         * Copy_PtrTovoid);
static void HDebouncing_voidProcessEventState(void * Copy_PtrTovoid);
static void HDebouncing_voidCheckDeviceState(void  * Copy_PtrTovoid);

//static u8   HDebouncing_u8GetStatus(DebouncingDevice_t * Copy_PtrToClass);
#endif
/*** End of File **************************************************************/
