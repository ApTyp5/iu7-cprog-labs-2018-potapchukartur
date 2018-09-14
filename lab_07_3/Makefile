CC := gcc
FLAGS := -Wall -Werror
REL_OBJ := main.o fileworks.o filt.o inout.o sort.o
TES_OBJ := test.o fileworks.o filt.o inout.o sort.o




a.exe: $(REL_OBJ)
	$(CC) -o $@ $^

run_tests: run_tests.exe
	./run_tests.exe
	rm *.exe *.o .*~ test.txt
	
run_tests.exe: $(TES_OBJ)
	$(CC) -o $@ $^

%.o: %.c *.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.exe *.o .*~
