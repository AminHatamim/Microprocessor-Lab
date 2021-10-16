#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int Array[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };


int main()
{
    int temp;
    DDRC = 0xFF;
    DDRD = 0xFF;
    while (1){
        for(temp = 0; temp < 10000; temp++){
        PORTC = 0xF7;
        PORTD = Array[(temp / 1) % 10];
        _delay_ms(1);
        PORTC = 0xFB;
        PORTD = Array[(temp / 10) % 10];
        _delay_ms(1);
        PORTC = 0xFD;
        PORTD = Array[(temp / 100) % 10];
        _delay_ms(1);
        PORTC = 0xFE;
        PORTD = Array[(temp / 1000) % 10];
        _delay_ms(1);    
    }        
    }
    return 0;
    }