#define F_CPU 1000000UL 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned int step = 0;

void step_setter()
{
    switch (step)
    {
    case 1:
        PORTA = 0b0100;
        break;
    case 2:
        PORTA = 0b1101;
        break;
    case 3:
        PORTA = 0b1011;
        break;
    case 4:
        PORTA = 0b0010;
        step = 0;
        break;
    default:
        PORTA = 0b0000;
        break;
    }
}


int main()
{

    TCCR0 |= (1 << CS02)|(1 << CS00);
    TCNT0 = 0;

    DDRC = 0x03;
    DDRA = 0x0F;

    PORTA = 0x00;

    TIMSK = 1 << TOIE0; // Enabling Timer0
    TCCR0 =0b00000101; // Clk/8 Prescaler

    sei();

    while (true)
    {

                if(PINC==3){
            if (TCNT0 >= 5){
                PORTA =0b0101; 
                TCNT0 = 0;
            }
            if (TCNT0 >= 5){
                PORTA = 0b0110;
                TCNT0 = 0; 
            }
            if (TCNT0 >= 5){
                PORTA = 0b1010;
                TCNT0 = 0;
            }
            if (TCNT0 >= 5){
                PORTA = 0b1001;
                TCNT0 = 0;
            }
        }        

    }
        return 0;
}