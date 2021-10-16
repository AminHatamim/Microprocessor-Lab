#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA |= 0xff;		/* LED port direction is output */
	PORTA = 0xff;
	
	char array[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};	
   
    while(1)
    {
		for(int i=0;i<10;i++)
		{
			PORTA = array[i]; /* LED port */
			_delay_ms(1000); /* wait 1 second */ 
		}
    }
}