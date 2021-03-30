/*******************************************************************************
* Title                 :   Debouncing 
* Filename              :   Debouncing_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   17/03/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  17/03/21   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file Debouncing_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STACK_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "Debouncing_interface.h"
#include "Debouncing_config.h"
#include "Debouncing_private.h"
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
static u8 Static_u8InitializedFlag;
static u8 Static_u8DeviceCuurentState;
static u8 Static_u8InterruptFlag;
static u8 Static_u8TimerFlag;
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
u8 HDebouncing_u8Constructor(DebouncingDevice_t   * Copy_PtrToClass, EXTI_InterruptId_t Copy_u8InterruptId)
{
   u8 Local_u8Interrupt[1];
   EXTI_voidPtrToFunction Local_Functions[1];
   void *                 Local_Parameters[1];
   Copy_PtrToClass->InterruptId        = Copy_u8InterruptId;
   Copy_PtrToClass->DeviceCurrentState = DEVICE_INITIAL_STATE;
   Copy_PtrToClass->DeviceOldState     = Copy_PtrToClass->DeviceCurrentState;
   Copy_PtrToClass->StateVariable      = IDLE_STATE;
   Static_u8DeviceCuurentState         = INITIALIZED_WITH_ZERO;
   Static_u8InitializedFlag            = INITIALIZED_WITH_ZERO;
   Static_u8InterruptFlag              = INITIALIZED_WITH_ZERO;
   Static_u8TimerFlag                  = INITIALIZED_WITH_ZERO;
   Local_u8Interrupt[0]                = Copy_PtrToClass->InterruptId;
   Local_Functions[0]                  = &HDebouncing_CallbackInExti;
   Local_Parameters[0]                 = (void*)Copy_PtrToClass;
   STACK_voidInitializeStack(&(Copy_PtrToClass->DebouncingStack));
   if(!STACK_u8IsStackFull(&(Copy_PtrToClass->DebouncingStack)))
   {
      STACK_u8PushEntryElement(&HDebouncing_voidIdleState,&(Copy_PtrToClass->DebouncingStack));
   }
   if(!STACK_u8IsStackFull(&(Copy_PtrToClass->DebouncingStack)))
   {
      STACK_u8PushEntryElement(&HDebouncing_voidProcessEventState,&(Copy_PtrToClass->DebouncingStack));
   }
   if(!STACK_u8IsStackFull(&(Copy_PtrToClass->DebouncingStack)))
   {
      STACK_u8PushEntryElement(&HDebouncing_voidCheckDeviceState,&(Copy_PtrToClass->DebouncingStack));
   }
   MEXTI_u8InitISRWithFunction(1, Local_u8Interrupt, Local_Functions, Local_Parameters);
   Static_u8InitializedFlag = INITIALIZED_WITH_ONE;
   return E_OK;
}

u8 HDebouncing_u8Deconstructor(DebouncingDevice_t   * Copy_PtrToClass)
{
   Copy_PtrToClass->InterruptId        = INITIALIZED_WITH_ZERO;
   Copy_PtrToClass->DeviceCurrentState = DEVICE_INITIAL_STATE;
   Copy_PtrToClass->DeviceOldState     = Copy_PtrToClass->DeviceCurrentState;
   Copy_PtrToClass->StateVariable      = IDLE_STATE;
   Static_u8DeviceCuurentState         = INITIALIZED_WITH_ZERO;
   Static_u8InitializedFlag            = INITIALIZED_WITH_ZERO;
   Static_u8InterruptFlag              = INITIALIZED_WITH_ZERO;
   Static_u8TimerFlag                  = INITIALIZED_WITH_ZERO;
   STACK_voidClearStack(&(Copy_PtrToClass->DebouncingStack));
   return E_OK;
}

u8 HDebouncing_u8MainFunction(DebouncingDevice_t  * Copy_PtrToClass, u8 * Copy_PtrToDeviceStatus)
{
   u8 Local_u8FunctionState   = E_NOK;
   if(Static_u8InitializedFlag)
   {
      StackEntry_t Local_CallBackFunction;
      Local_CallBackFunction  = Copy_PtrToClass->DebouncingStack.StackEntry[Copy_PtrToClass->StateVariable];
      Local_CallBackFunction((void *)Copy_PtrToClass);
      *Copy_PtrToDeviceStatus = Static_u8DeviceCuurentState;
      Local_u8FunctionState   = E_OK;
   }
   else
   {
      Local_u8FunctionState   = E_NOK;
   }
   return Local_u8FunctionState;
}

// Callback Functions
static void HDebouncing_CallbackInExti(void  * Copy_PtrTovoid)
{
   DebouncingDevice_t * Local_PtrToClass   = (DebouncingDevice_t*)(Copy_PtrTovoid);
   if(Local_PtrToClass->DeviceCurrentState == DEVICE_OPEN)
   {
      Local_PtrToClass->DeviceCurrentState = DEVICE_CLOSED;
   }
   else if(Local_PtrToClass->DeviceCurrentState == DEVICE_CLOSED)
   {
      Local_PtrToClass->DeviceCurrentState = DEVICE_OPEN;
   }
   Static_u8InterruptFlag = EVENT_OCCURRED;
}

static void HDebouncing_CallbackInTimer(void * Copy_PtrTovoid)
{
   Static_u8TimerFlag = EVENT_OCCURRED;
}

// Functions That Describe States
static void HDebouncing_voidIdleState(void * Copy_PtrTovoid)
{
   DebouncingDevice_t * Local_PtrToClass = (DebouncingDevice_t*)(Copy_PtrTovoid);
   Static_u8DeviceCuurentState           = DEVICE_IS_OFF;
   if(Static_u8InterruptFlag == EVENT_OCCURRED)
   {
      Static_u8InterruptFlag             = CLEAR_FLAG;
      Local_PtrToClass->StateVariable    = PROCESS_EVENT_STATE;
   }
}

static void HDebouncing_voidProcessEventState(void * Copy_PtrTovoid)
{
   DebouncingDevice_t * Local_PtrToClass = (DebouncingDevice_t*)(Copy_PtrTovoid);
   MSTK_voidSetIntervalSingle_ms(WAITING_TIME, &HDebouncing_CallbackInTimer, NULL);
   Local_PtrToClass->StateVariable       = CHECK_DEVICE_STATE;
}

static void HDebouncing_voidCheckDeviceState(void * Copy_PtrTovoid)
{
   DebouncingDevice_t * Local_PtrToClass = (DebouncingDevice_t*)(Copy_PtrTovoid);
   if(Static_u8TimerFlag == EVENT_OCCURRED)
   {
      Static_u8TimerFlag = CLEAR_FLAG;
      if(Local_PtrToClass->DeviceOldState != Local_PtrToClass->DeviceCurrentState)
      {
         Local_PtrToClass->DeviceOldState = Local_PtrToClass->DeviceCurrentState;
         Static_u8DeviceCuurentState      = DEVICE_IS_ON;
         Local_PtrToClass->StateVariable  = IDLE_STATE;
      }
   }
   
}
/*************** END OF FUNCTIONS ***************************************************************************/
