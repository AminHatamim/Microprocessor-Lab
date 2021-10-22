#include <mega16.h>
#include <alcd.h>
#include <io.h>

void main(void)
{
while (1)
    {
    lcd_init(20);   
    
    lcd_puts("Hello World");
    }
}
