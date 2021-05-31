
#include "mcc_generated_files/mcc.h"
#include "math.h"
#include <stdio.h>

//double sinImp (double);
int floatToInt(double);
void setOutput(int);

double a,b,c,x,value;
double countwart(double,double,double,double);
 /*
  * 00 Nic
  * 01 sin
  * 10 tan
  * 11 funkcja
 */
//Rejestry
/*
 * wynik sin 0x20 ?
 * wynik tan 0x30 ?
 * sin_tan 0x40
 * fun: a 0x50
 * fun: b 0x60
 * fun: c 0x70
 * fun: x 0xA0  
 * wynik fun: 0xB0 ?
 */
//int *wyn_sin = 0x20;
//int *wyn_tan = 0x30;
float *sin_tan = 0x40;
float *a_fun = 0x50;
float *b_fun = 0x60;
float *c_fun = 0x70;
float *x_fun = 0xA0;
//int *fun_fun = 0xB0;
void main(void)
{
    SYSTEM_Initialize();
    ANSELC = 0;
    TRISC = 0;
    TRISA = 0;
    TRISB = 0b11000000;
    while(1)
    {  
        int testowa;
       short int option = 0b00000011 & PORTB >> 6; 
       switch(option)
        {
            case 0b00:
                break;
            case 0b01:
                setOutput(testowa = floatToInt(sin(*sin_tan)));
                break;
            case 0b10:
                setOutput(testowa = floatToInt(tan(*sin_tan)));
                break;
            case 0b11:
                setOutput(testowa = floatToInt(countwart(*a_fun, *b_fun, *c_fun, *x_fun)));
                break;
            
        }
    }
       
}

double countwart(double a,double b,double c,double x){
    return a*x*x + b*x + c;
}
int floatToInt(double a)
{
    return a*100;
}
void setOutput(int a)
{ 
    short int is_neg = 0;;
    if(a<0)
    {
        a = -a;
        is_neg = 1;
    }
    PORTC = (0b11111111 & a);
    PORTB = (0b00110000) & (a >> 4); 
    PORTA = ((0b00110000) & (a >> 6)) | ((0b00000011) & (a >> 12)) | (is_neg==1?0b00000100:0b00000000);
}
