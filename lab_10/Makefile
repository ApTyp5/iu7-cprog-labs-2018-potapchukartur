CC := gcc
CFL := -Wall -Werror 
OBJ := listfunc.o


ifeq ($(mod),db)
	CFL += -O0 -g3
endif

app.exe: nothing.o

test.exe: mtests.o $(OBJ)
	$(CC) $(LFL) -o $@ $^


%.o: %.c
	$(CC) $(CFL) -c $<

clean:
	$(RM) -f *.o *.exe
	
