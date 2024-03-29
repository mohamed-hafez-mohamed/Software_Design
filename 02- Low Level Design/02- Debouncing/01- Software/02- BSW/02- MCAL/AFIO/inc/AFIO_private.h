/****************************************************************************
* Title                 :   AFIO   
* Filename              :   AFIO_private.h
* Author                :   Mohamed Hafez
* Origin Date           :   20/08/2020
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
*  20/08/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  AFIO_private.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct AFIO_private
{
     volatile u32 EVCR;
     volatile u32 MAPR;
     volatile u32 EXTICR[4];
     volatile u32 MAPR2;
}AFIO_t;


/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define  AFIO ((volatile AFIO_t *)0x40010000)

#endif
/*** End of File **************************************************************/
