
CC := gcc
CFL := -Wall -Werror
OBJ := main.c




app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)

%.o: %.c *.h
	$(CC) -c $< $(CFL)

clean:
	rm *.o *.exe .*~


