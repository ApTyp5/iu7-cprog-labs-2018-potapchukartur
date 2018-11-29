CC := gcc
CFL := -Wall -Werror 
OBJ := listfunc.o


ifeq ($(mod),db)
	CFL += -O0 -g3
endif

ifeq ($(testing),valgrind)
	TFL += valgrind --leak-check=full 
endif

ifeq ($(testing),drmem)
	TFL += drmem
endif   

app.exe: nothing.o
	$(CC) -o $@ $^

run_mtests: test.exe
	$(TFL) ./$<

test.exe: test.o $(OBJ)
	$(CC) $(LFL) -o $@ $^


%.o: %.c
	$(CC) $(CFL) -c $<

clean:
	$(RM) *.o *.exe
	
