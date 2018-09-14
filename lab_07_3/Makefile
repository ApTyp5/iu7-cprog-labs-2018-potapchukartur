CC := gcc
FLAGS := -Wall -Werror
REL_OBJ := main.o fileworks.o filt.o inout.o sort.o
TES_OBJ := test.o fileworks.o filt.o inout.o sort.o




a.exe: $(REL_OBJ)
	$(CC) -o $@ $^

mod_tests: run_tests.exe
	./run_tests.exe
	rm *.exe *.o .*~ test.txt

func_tests: a.exe
	./run_func_tests	
	rm out
	
run_tests.exe: $(TES_OBJ)
	$(CC) -o $@ $^

%.o: %.c *.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.exe *.o .*~
