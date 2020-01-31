CC = gcc
CFLAGS = -I. -g
TARGET = dt
OBJS = main.o GetCurrentDirectory.o directoryCheck.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
