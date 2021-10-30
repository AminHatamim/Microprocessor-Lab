#define F_CPU 1000000UL 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char tot_overflow; 


interrupt [TIMER0_OVF_vect] void timer0_ovf_isr(void)
{
    tot_overflow++;
}


int main()
{

    TCCR0 |= (1 << CS00);
    TCNT0 = 0;

    DDRC = 0;
    DDRA = 0xFF;

    PORTA = 0x00;

    TIMSK = 1 << TOIE0; // Enabling Timer0
    TCCR0 |= 1 << CS01; // Clk/8 Prescaler

    sei();

    while (true)
    {
    }
}