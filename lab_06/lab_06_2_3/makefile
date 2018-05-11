CC = gcc
LINK_COMMAND = -o
COMPILE_COMMAND = -c
FLAGS = -Wall -Werror -pedantic -std=c99
PROJECT_OBJECT_FILES = format-functions.o major-work-function.o open-close-functions.o read-write-functions.o
TEST_OBJECT_FILES = ./format_tests.o ./major_work_tests.o ./open_close_tests.o ./read_write_tests.o ./run_tests.o 


app.exe: $(PROJECT_OBJECT_FILES) main.o
	$(CC) $(LINK_COMMAND) $@ $^ 

%.o: %.c *.h
	$(CC) $(COMPILE_COMMAND) $< $(FLAGS)
    
tests.exe: $(TEST_OBJECT_FILES) $(PROJECT_OBJECT_FILES)
	$(CC) $(LINK_COMMAND) $@ $^

clean:
	rm *.o *.exe *.txt
    
run_tests: tests.exe
	./tests
	rm *.o *.exe *.txt
