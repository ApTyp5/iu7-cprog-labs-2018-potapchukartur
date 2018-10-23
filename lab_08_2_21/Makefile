
CC := gcc
CFL := -Wall -Werror -std=c99 -pedantic
OBJ := main.o action.o aplog.o matrix.o
TOBJ := test.o


test.exe: $(TOBJ)
	$(CC) -o $@ $^ $(LFL)

app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)

%.o: %.c *.h
	$(CC) -c $< $(CFL)


clean:
	rm *.o *.exe .*~ aplog
