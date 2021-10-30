#define F_CPU 1000000UL 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned int step = 0;
unsigned int noverflow = 0;

void step_setter()
{
    switch (step)
    {
    case 1:
        PORTA = 0x09;
        break;
    case 2:
        PORTA = 0x0c;
        break;
    case 3:
        PORTA = 0x06;
        break;
    case 4:
        PORTA = 0x03;
        step = 0;
        break;
    default:
        PORTA = 0X00;
        break;
    }
}



ISR(TIMER0_OVF_vect){


    step++;
    if (step > 3)
        step = 0;
    step_setter();
    // TCNT0 = 217;


}



int main()
{

    TCCR0 |= (1 << CS02)|(1 << CS00);
    TCNT0 = 0;

    DDRC &= ~(0x04);
    DDRA = 0x0F;

    PORTA = 0x00;
    PORTC |= 0x04;

    TIMSK = 1 << TOIE0; // Enabling Timer0
    TCCR0 =0b00000101; // Clk/8 Prescaler

    sei();

    while (true)
    {

if((PINC & 0x04) == 0){

            TCCR0 = 0x05;
            // TCNT0 = 217;
            TIMSK = 0x01;


}

    }
        return 0;
}