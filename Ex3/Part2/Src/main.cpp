#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int Array[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};


int main()
{
    int temp;
    DDRC = 0xFF;
    DDRD = 0xFF;
    while (1){
        for(temp = 0; temp < 10000; temp++){
        PORTC = 0x07;
        PORTD = Array[(temp / 1) % 10];
        _delay_ms(1);
        PORTC = 0x0B;
        PORTD = Array[(temp / 10) % 10];
        _delay_ms(1);
        PORTC = 0x0D;
        PORTD = Array[(temp / 100) % 10];
        _delay_ms(1);
        PORTC = 0x0E;
        PORTD = Array[(temp / 1000) % 10];
        _delay_ms(1);    
    }        
    }
    return 0;
    }