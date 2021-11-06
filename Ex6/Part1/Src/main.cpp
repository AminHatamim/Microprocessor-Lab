#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"
#include <stdio.h>
#include <string.h>
#define degree 0xdf


void adcInit(){										
	ADCSRA = (1 << ADEN) | (0 << ADSC) | (1 << ADATE) | (0 << ADIF) | (0 << ADIE) | (1 << ADPS2) | (0 << ADPS1) | (0 << ADPS0);
	SFIOR = (0 << ADTS2) | (0 << ADTS1) | (0 << ADTS0);
}

int adcSet(char ch){
	ADMUX = (0 << REFS1) | (1 << REFS0) | (0 << ADLAR) ;

	_delay_ms(10);
	ADCSRA |= (1 << ADSC);

	while ((ADCSRA & (1 << ADIF)) == 0);
	ADCSRA |= (1 << ADIF);
	return ADCW;
}

int main(){
	
	LCD_Init();
	adcInit();
	char Buffer[16];
    float temp;
	DDRA=0b00000000;

	while(true){
		//LCD_Clear();
	   LCD_String_xy(0,0,"Temperature: ");
	   temp = (adcSet(0)*(4.88));
	   temp = (temp/10.00);
	   if (PINA1==0)
	   {
		   temp=(temp*1.8)+32;
	   }
	   
	   sprintf(Buffer,"%d%c  ", (int)temp, degree);
	   LCD_String_xy(1,0,Buffer);
	   	
	}
	return 0;
}