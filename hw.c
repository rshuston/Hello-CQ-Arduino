#include <avr/io.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>



void setB5ToInput(void)
{
    DDRB &= ~(1 << DDB5);
}



void setB5ToOutput(void)
{
    DDRB |= (1 << DDB5);
}



void clearB5Pin(void)
{
    PORTB &= ~(1 << PORTB5);
}



void setB5Pin(void)
{
    PORTB |= (1 << PORTB5);
}



void wait_ms(float time_ms)
{
    _delay_ms((double) time_ms);
}
