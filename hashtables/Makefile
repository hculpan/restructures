CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = main.o simplelinkedlist.o wordcount.o hashtable.o
TARGET = main

all: $(TARGET)

run: $(TARGET)
	./main

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
