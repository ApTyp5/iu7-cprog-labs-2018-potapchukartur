CC := gcc
CFL := -Wall -Werror 
OBJ := listfunc.o


app.exe: nothing.o

test.exe: mtests.o $(OBJ)
	$(CC) $(LFL) -o $@ $^


%.o: %.c
	$(CC) $(CFL) -c $<

clean:
	$(RM) -f *.o *.exe
	
