#include <alcd.h>
#include <mega32.h>
#include <stdio.h>
#include <delay.h>

int temp = 0;
char St[16];


uint16_t adcread(uint8_t ch)
{
    ADMUX = (0 << REFS1) | (1 << REFS0) | (0 << ADLAR) | ch;

    _delay_us(10);
    ADCSRA |= (1 << ADSC);

	while ((ADCSRA & (1 << ADIF)) == 0)
		;
	ADCSRA |= (1 << ADIF);

	return ADCW;
}


void main(void)
{
    ADMUX = (1 << REFS1) | (1 << REFS0) | (1 << ADLAR);
    SFIOR = (0 << ADTS2) | (0 << ADTS1) | (0 << ADTS0);
    ADCSRA = (1 << ADEN) | (0 << ADSC) | (0 << ADATE) | (0 << ADIF) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    lcd_init(16);


    while (true)
    {


        lcd_clear();
        adc=adc_read(0);
		temp=(int)(adc*500.0/1024);  
        sprintf(St, "the temperature is=%d  C", temp);
        lcd_gotoxy(0, 0);
        lcd_puts(temp);
        delay_ms(100);
    }
}