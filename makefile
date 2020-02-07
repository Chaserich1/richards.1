CC = gcc
CFLAGS = -I. -g
TARGET = bt
OBJS = main.o SearchFileSystem.o DirectoryCheck.o CommandOptions.o Queue.o


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
