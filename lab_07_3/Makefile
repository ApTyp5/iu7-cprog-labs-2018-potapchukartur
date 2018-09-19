CC := gcc
FLAGS := -Wall -Werror
REL_OBJ := main.o fileworks.o filt.o inout.o sort.o
TES_OBJ := test.o fileworks.o filt.o inout.o sort.o
SORT_CMP_OBJ := sort_cmp.o sort.o




a.exe: $(REL_OBJ)
	$(CC) -o $@ $^

mod_tests: tests.exe
	./run_tests.exe
	rm *.exe *.o .*~ test.txt

func_tests: a.exe
	./run_func_tests	
	rm out

sort_cmp: sort_cmp.exe
	./$<

sort_cmp.exe: $(SORT_CMP_OBJ)
	$(CC) -o $@ $^
	
	
tests.exe: $(TES_OBJ)
	$(CC) -o $@ $^

%.o: %.c *.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.exe *.o .*~
