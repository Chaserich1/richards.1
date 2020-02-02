CC = gcc
CFLAGS = -I. -g
TARGET = bt
OBJS = main.o GetCurrentDirectory.o directoryCheck.o CommandOptions.o


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
