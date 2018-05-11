CC = gcc
LINK_COMMAND = -o
COMPILE_COMMAND = -c
FLAGS = -Wall -Werror -pedantic -std=c99
INITIAL_OBJECT_FILES = main.o format-functions.o major-work-function.o open-close-functions.o read-write-functions.o


app.exe: $(INITIAL_OBJECT_FILES)
	$(CC) $(LINK_COMMAND) $@ $^ 

%.o: %.c *.h
	$(CC) $(COMPILE_COMMAND) $< $(FLAGS)
clean:
	rm *.o *.exe
