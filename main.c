#include <avr/io.h>
#include <util/delay.h>
	// included libraries

#define DELAY_MS 300
	// global constant

int main ()
{
	DDRB = 0xFF;
 	// set data direction register for output on PORTB
 	while(1) 
 	{
 		PORTB = 0x20;
  		// set Pin 0 of PORTB at high
    	_delay_ms(DELAY_MS); 
  		// delay
    	PORTB = 0x00;
    	// ser Pin 0 of PORTB at low
  		_delay_ms(DELAY_MS);
 	 	//delay
  	}
  	return 0;
}