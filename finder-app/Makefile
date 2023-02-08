SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)
CFLAGS = -Wall

ifdef CROSS_COMPILE
	CC := $(CROSS_COMPILE)
endif

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

clean:
	-rm -f *.o $(TARGET) *.elf *.map
