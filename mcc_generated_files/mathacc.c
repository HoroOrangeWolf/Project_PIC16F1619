/**
  MATHACC Generated Driver  File

  @Company
    Microchip Technology Inc.

  @File Name
    mathacc.c

  @Summary
    This is the generated driver implementation for the MATHACC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for MATHACC.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "mathacc.h"

/**
  Section: MATHACC APIs
*/

void MATHACC_Initialize(void)
{
    PID1CON = 0x80;
    PIR5bits.PID1DIF = 0;
    PIR5bits.PID1EIF = 0;
    PIE5bits.PID1DIE = 1;
    PIE5bits.PID1EIE = 1;
}

void MATHACC_LoadZ1(uint32_t value) {
    PID1Z1L = (0x000000FF & value);
    PID1Z1H = ((0x0000FF00 & value) >> 8);
    PID1Z1U = ((0x00010000 & value) >> 16);
}

void MATHACC_LoadZ2(uint32_t value) {
    PID1Z2L = (0x000000FF & value);
    PID1Z2H = ((0x0000FF00 & value) >> 8);
    PID1Z2U = ((0x00010000 & value) >> 16);
}

uint32_t MATHACC_Z1Get(void) {
    uint32_t value = 0;

    value = (uint32_t) PID1Z1L & 0x000000FF;
    value = (value | ((uint32_t) PID1Z1H << 8)) & 0x0000FFFF;
    value = (value | ((uint32_t) PID1Z1U << 16)) & 0x0001FFFF;

    return value;
}

uint32_t MATHACC_Z2Get(void) {
    uint32_t value = 0;

    value = (uint32_t) PID1Z2L & 0x000000FF;
    value = (value | ((uint32_t) PID1Z2H << 8)) & 0x0000FFFF;
    value = (value | ((uint32_t) PID1Z2U << 16)) & 0x0001FFFF;

    return value;
}

void MATHACC_AdditionAndMultiplication(uint16_t a, uint16_t b, uint16_t c)
{
    PID1K1H  = (uint8_t) ((c & 0xFF00) >> 8);
    PID1K1L  = (uint8_t)  (c & 0x00FF);
    PID1SETH = (uint8_t) ((b & 0xFF00) >> 8);
    PID1SETL = (uint8_t)  (b & 0x00FF);
    PID1INH  = (uint8_t) ((a & 0xFF00) >> 8);
    PID1INL  = (uint8_t)  (a & 0x00FF);   // starts module operation
}

void MATHACC_Addition(uint16_t a, uint16_t b)
{
    PID1K1H  = 0;
    PID1K1L  = 1;
    PID1SETH = (uint8_t) ((b & 0xFF00) >> 8);
    PID1SETL = (uint8_t)  (b & 0x00FF);
    PID1INH  = (uint8_t) ((a & 0xFF00) >> 8);
    PID1INL  = (uint8_t)  (a & 0x00FF);   // starts module operation
}
void MATHACC_Multiplication(uint16_t b, uint16_t c)
{
    PID1K1H  = (uint8_t) ((c & 0xFF00) >> 8);
    PID1K1L  = (uint8_t)  (c & 0x00FF);
    PID1SETH = (uint8_t) ((b & 0xFF00) >> 8);
    PID1SETL = (uint8_t)  (b & 0x00FF);
    PID1INH  = 0;
    PID1INL  = 0;    // starts module operation
}
                        

MATHACCResult MATHACC_ResultGet(void)
{
    MATHACCResult data;

    data.byteLL = PID1OUTLL;
    data.byteLH = PID1OUTLH;
    data.byteHL = PID1OUTHL;
    data.byteHH = PID1OUTHH;
    data.byteU  = PID1OUTU;

    return data;
}

void MATHACC_ClearResult(void)
{
    PID1OUTLL = 0;
    PID1OUTLH = 0;
    PID1OUTHL = 0;
    PID1OUTHH = 0;
    PID1OUTU  = 0;
}

void MATHACC_Error_ISR( void )
{
    PIR5bits.PID1EIF = 0;
    
    // user code here for error handling
}

void MATHACC_PID_ISR( void )
{
    PIR5bits.PID1DIF = 0;
    
    // user code here    
}
// end of file
     
        

        
