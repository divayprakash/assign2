#include <avr/io.h>
#include <util/delay.h>
	// included libraries

#define DELAY_MS 1000
	// global constant

int main ()
{
	DDRB |= 0xFF;
 	// set data direction register for output on PORTB
 	while(1) 
 	{
 		PORTB ^= 0x20;
  		// set Pin 5 of PORTB at high
    	_delay_ms(DELAY_MS); 
  		// delay
  	}
  	return 0;
}