
CC := gcc
CFL := -Wall -Werror
OBJ := main.o mystring.o fileworks.o aplog.o




app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)

%.o: %.c *.h
	$(CC) -c $< $(CFL)

clean:
	rm *.o *.exe .*~

