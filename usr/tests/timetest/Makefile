ETAOS=$(shell pwd)/../../..
SIMULAVR=/usr/bin/simulavr
AVRDUDE=/usr/bin/avrdude
OBJCOPY=/usr/bin/avr-objcopy
RD=0x21
WR=0x20
EX=0x22

MCU=atmega328p
PROGRAMMER=arduino
BAUD=115200
PORT=/dev/ttyACM0

MAKEFLAGS += -rR --no-print-directory

all:
	@$(MAKE) -C $(ETAOS) A=$(PWD) ARCH=avr CROSS_COMPILE=avr- app

clean:
	@$(MAKE) -C $(ETAOS) A=$(PWD) ARCH=avr CROSS_COMPILE=avr- clean

test: all
	@$(SIMULAVR) -d atmega328 -f test-app.img -W $(WR),- -R $(RD),- -e $(EX)

hex: all
	@$(OBJCOPY) -R .eeprom -O ihex test-app.img test-app.hex 

upload:
	@$(AVRDUDE) -q -V -p $(MCU) -c $(PROGRAMMER) -b $(BAUD) -P $(PORT) \
		-C /etc/avrdude.conf -U flash:w:test-app.hex:i

