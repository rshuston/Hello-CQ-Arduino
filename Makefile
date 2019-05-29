CC = avr-gcc
CFLAGS = -Wall -Os -mmcu=atmega328p -DF_CPU=16000000UL

LD = avr-gcc
LDFLAGS = $(CFLAGS)

SRC = main.c hw.c morse.c
OBJS = $(SRC:.c=.o)

HEX = hello-cq.hex

ELF = $(HEX:.hex=.elf)

TTY = /dev/tty.usbmodem14201

default: $(HEX)

force:

help: force
	@echo "default: $(HEX)"
	@echo "$(HEX): make the application HEX image"
	@echo "$(ELF): make the application ELF image"
	@echo "tty: see if the device is connected"
	@echo "prog: program the application HEX image to the target"
	@echo "clean: delete all object files and debug files"
	@echo "clobber: delete all object files, debug files, and application image files"

$(HEX): $(ELF)
	avr-objcopy -j .text -j .data -O ihex $< $@

$(ELF): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

tty: $(TTY)
	@echo "device is connected as $(TTY)"

prog: $(HEX)
	avrdude -v -p m328p -c arduino -P /dev/tty.usbmodem14201 -b 115200 -D -U flash:w:$(HEX):i

clean: force
	rm -f $(OBJS) $(OBJS:.o=.d)

clobber: clean
	rm -f $(HEX) $(ELF)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@ -MMD

-include $(wildcard *.d)
