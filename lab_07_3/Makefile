CC := gcc
FLAGS := -Wall -Werror -std=c99 -pedantic 
REL_OBJ := main.o fileworks.o filt.o sort.o
TES_OBJ := test.o fileworks.o filt.o sort.o
SORT_CMP_OBJ := sort_cmp.o sort.o





app.exe: $(REL_OBJ)
	$(CC) -o $@ $^ 

mod_tests: test.exe
	./test.exe

func_tests: app.exe
	./run_func_tests	
	rm out

sort_cmp: sort_cmp.exe
	./$<

sort_cmp.exe: $(SORT_CMP_OBJ)
	$(CC) -o $@ $^
	
	
test.exe: $(TES_OBJ)
	$(CC) -o $@ $^

%.o: %.c *.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.exe *.o .*~
