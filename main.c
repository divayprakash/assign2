#include <avr/io.h>
#include <util/delay.h>
 
#define DELAY_MS 300
 
int main ()
{
	DDRB = 0xFF;
 	// PORTB, output
 	while(1) 
 	{
 		PORTB = 0x20;
  		//Pin 0, high
    	_delay_ms(DELAY_MS); 
  		//delay
    	PORTB = 0x00;
    	// Pin 0, low
  		_delay_ms(DELAY_MS);
 	 	//delay
  	}
  	return 0;
}