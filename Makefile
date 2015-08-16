CC=avr-gcc
MCU=-mmcu=atmega328p
CPU_SPEED=-DF_CPU=16000000UL
CFLAGS=-Wall -Os $(MCU) $(CPU_SPEED)
CONVERTER=avr-objcopy
SRC=main
UPLOADER=avrdude -F -V -c
BOARD=arduino
PORT=/dev/ttyUSB0
BAUD_RATE=57600

all : compile program clean

compile : $(SRC).hex

$(SRC).hex : $(SRC).elf
	$(CONVERTER) -O ihex -R .eeprom $< $@

$(SRC).elf : $(SRC).s
	$(CC) $(CFLAGS) -s -o $@ $<	

$(SRC).s : $(SRC).c
	$(CC) $(CFLAGS) -S -o $@ $<	

program : $(SRC).hex
	$(UPLOADER) $(BOARD) -p ATmega328P -P $(PORT) -b $(BAUD_RATE) -U flash:w:$<

.PHONY : clean
clean :
	rm -f *.s
	rm -f *.elf
	rm -f *.hex
