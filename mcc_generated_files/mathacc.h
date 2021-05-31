/**
  MATHACC Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    mathacc.h

  @Summary
    This is the generated header file for the MATHACC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs driver for MATHACC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1619
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef MATHACC_H
#define MATHACC_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

/**
 Section: Data Type Definitions
*/

/**
  MATHACC result structure

  @Summary
    Define result structure for math acc results

  @Description
    This structure is to collect results  for MATHACC mode operation and
    add & multiply operations of MATHACC module. The mentioned module
    have 36 bits result which is mapped into the structure.

 */
typedef struct
{
    uint8_t byteLL;
    uint8_t byteLH;
    uint8_t byteHL;
    uint8_t byteHH;
    uint8_t byteU;
} MATHACCResult;

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Interface Routines
*/
        
/**
  @Summary
    Initializes the MATHACC module

  @Description
    This routine initializes the MATHACC module

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
    MATHACCResult result;

    MATHACC_Initialize();

    MATHACC_AdditionAndMultiplication(0xff00,0xffff,0x00ff); // starts MATHACC module operation
    // have some other application code running here..

    // completion of MATHACC module operation triggers the module interrupt, now
    // read the result.
    result = MATHACC_ResultGet();

    MATHACC MAC_Addition(0xff00,0xffff);    // starts MATHACC module operation
    // have some other application code running here..

    // completion of MATHACC module operation triggers the module interrupt, now
    // read the result.
    result = MATHACC_ResultGet();

    MATHACC_Multiplication(0xffff,0x00ff);  // starts MATHACC module operation
    // have some other application code running here..

    // completion of MATHACC module operation triggers the module interrupt, now
    // read the result.
    result = MATHACC_ResultGet();

    </code>
*/
uint32_t MATHACC_Z2Get(void);
uint32_t MATHACC_Z1Get(void);
void MATHACC_LoadZ1(uint32_t value);
void MATHACC_LoadZ2(uint32_t value);
void MATHACC_Initialize(void);

/**
  @Summary
    Initiates addition and multiplication operation on given input arguments

  @Description
    This function triggers the module to perform addition and multiplication
    operation on given input arguments, based on the formaula, (a+b).c

  @Preconditions
    MATHACC_Initialize() API should be called before calling this API.

  @Param
    a - 16bit value for addition
    b - 16bit value for addition
    c - 16bit value for multiplication

  @Returns
    None

  @Example
    <code>
    Refer MATHACC_Initialize() example
    </code>
*/
void MATHACC_AdditionAndMultiplication(uint16_t a, uint16_t b, uint16_t c);

/**
  @Summary
    Initiates addition operation on given input arguments

  @Description
    This function triggers the module to perform addition operation on
    given input arguments.

  @Preconditions
    MATHACC_Initialize() API should be called before calling this API.

  @Param
    a - 16bit value for addition
    b - 16bit value for addition

  @Returns
    None

  @Example
    <code>
    Refer MATHACC_Initialize() example
    </code>
*/
void MATHACC_Addition(uint16_t a, uint16_t b);

/**
  @Summary
    Initiates multiplication operation on given input arguments

  @Description
    This function triggers the module to perform multiplication operation on
    given input arguments.

  @Preconditions
    MATHACC_Initialize() API should be called before calling this API.

  @Param
    b - 16bit value for multiplication
    c - 16bit value for multiplication

  @Returns
    None

  @Example
    <code>
    Refer MATHACC_Initialize() example
    </code>
*/
void MATHACC_Multiplication(uint16_t b, uint16_t c);

/**
  @Summary
    Read the result

  @Description
    Read the result available in PIDOUT registers.

  @Preconditions
    None

  @Param
    None

  @Returns
    Return the result of type 'MATHACCResult'

  @Example
    <code>
    MATHACCResult result = MATHACC_ResultGet();
    </code>
*/
MATHACCResult MATHACC_ResultGet(void);

/**
  @Summary
    Clear the result

  @Description
    Clear the result by clearing PIDOUT registers.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Example
    <code>
    MATHACC_ClearResult();
    </code>
*/
void MATHACC_ClearResult(void);

/**
  @Summary
    Math Accelerator module error interrupt routine

  @Description
    This function will be invoked on error overflow during module operation
*/
void MATHACC_Error_ISR( void );

/**
  @Summary
    Math Accelerator module interrupt routine

  @Description
    This function will be invoked on completion of module operation
*/
void MATHACC_PID_ISR( void );
#ifdef __cplusplus  // Provide C++ Compatibility

}
#endif

#endif /*_MATHACC_H*/

