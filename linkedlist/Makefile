CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = album.o main.o readdata.o utils.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
