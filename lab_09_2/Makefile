CC := gcc
OBJ := main.o fileworks.o mystring.o my_strrchr.o prepare.o
TOBJ := mod_tests.o fileworks.o mystring.o my_strrchr.o prepare.o
CFL := -Wall -Werror -std=c99 -pedantic







app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)

run_mod_tests: test.exe
	./test.exe

test.exe: $(TOBJ)
	$(CC) -o $@ $^ $(LFL)

%.o: %.c *.h
	$(CC) -c $< $(CFL)

clean:
	rm *.o *.exe .*~ *.txt


