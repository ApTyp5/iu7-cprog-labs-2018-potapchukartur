
CC := gcc
CFL := -Wall -Werror -std=c99 -pedantic
OBJ := main.o action.o matrix.o
TOBJ := mod_tests.o matrix.o
FTOBJ := func_tests.o matrix.o


ifeq ($(mod),j)
	CFL += -DJOURNAL
endif

func_tests: func_tests.exe
	./$<

func_tests.exe: app.exe $(FTOBJ)
	$(CC) -o $@ $(FTOBJ) $(LFL)

app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)

mod_tests: test.exe
	./test.exe

test.exe: $(TOBJ)
	$(CC) -o $@ $^ $(LFL)


%.o: %.c *.h
	$(CC) -c $< $(CFL)


clean:
	rm *.o *.exe .*~ 
