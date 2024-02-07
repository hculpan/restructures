CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = main.o
TARGET = main

all: $(TARGET)

run: $(TARGET)
	./main

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
