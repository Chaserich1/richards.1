all: GetCurrentDirectory.c
	gcc -g -Wall -o GetCurrentDirectory GetCurrentDirectory.c
clean:
	$(RM) GetCurrentDirectory
