
CC := gcc
CFL := -Wall -Werror -std=c99 -pedantic
OBJ := main.o action.o aplog.o matrix.o
TOBJ := test.o
FTOBJ := func_tests.o matrix.o aplog.o

func_tests.exe: app.exe $(FTOBJ)
	gcc -o $@ $(FTOBJ)

app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)
	pwd

test.exe: $(TOBJ)
	$(CC) -o $@ $^ $(LFL)


%.o: %.c *.h
	$(CC) -c $< $(CFL)


clean:
	rm *.o *.exe .*~ aplog
