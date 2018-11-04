
CC := gcc
CFL := -Wall -Werror -std=c99 -pedantic
OBJ := main.o action.o matrix.o
TOBJ := mod_tests.o matrix.o eq.o 
DOBJ := doubdiff.o matrix.o eq.o

ifeq ($(mod),deb)
	CFL += -g3 -O0
endif

ifeq ($(mod),rel)
	CFL += -g0 -O3
endif



# RUNS
run_neg_ftests: app.exe
	./neg_func_tests.sh 2>/dev/null

run_pos_ftests: app.exe doubdiff.exe
	./pos_func_tests.sh

run_mtests: test.exe
	./test.exe
	rm ex.test


# EXECUTABLE
func_tests.exe: app.exe $(FTOBJ)
	$(CC) -o $@ $(FTOBJ) 

app.exe: $(OBJ)
	$(CC) -o $@ $^ 

doubdiff.exe: $(DOBJ)
	$(CC) -o $@ $^ 

test.exe: $(TOBJ)
	$(CC) -o $@ $^ 


# FRAME
%.o: %.c *.h
	$(CC) -c $< $(CFL)


# CLEAN
clean:
	rm *.o *.exe .*~ 
