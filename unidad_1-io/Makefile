MCU = atmega328p
F_CPU = 16000000UL
PROGRAMMER = usbasp
PORT = usb
BAUD = 115200

SRC_DIR = $(CARPETA)
LIB_DIR = lib
BIN_DIR = bin

SRC = $(FILE).c 

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS = -Wall -Os -F_CPU=$(F_CPU) -mmcu=$(MCU) -I$(LIB_DIR)
LDFLAGS = -mmcu=$(MCU)
AVRDUDE_FLAGS = -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -b $(BAUD)

TARGET = $(BIN_DIR)/$(FILE)

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex - $< $@

clean:
	rm -f $(BIN_DIR)/*

subir: $(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(TARGET).hex:i


#make CARPETA=ejemplo FILE=example-1_3_1
#make CARPETA=ejercicio FILE=exercise-1_3_1