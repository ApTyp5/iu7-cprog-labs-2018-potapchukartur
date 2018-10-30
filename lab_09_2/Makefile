CC := gcc
OBJ := main.o fileworks.o mystring.o my_strrchr.o
TOBJ := test.o fileworks.o mystring.o my_strrchr.o
CFL := -Wall -Werror -std=c99 -pedantic







app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)

test.exe: $(TOBJ)
	$(CC) -o $@ $^ $(LFL)

%.o: %.c *.h
	$(CC) -c $< $(CFL)

clean:
	rm *.o *.exe .*~

