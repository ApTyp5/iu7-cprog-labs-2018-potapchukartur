
CC := gcc
CFL := -Wall -Werror
OBJ := my_strrchr.o test.o





test.exe: $(OBJ)
	$(CC) -o $@ $^ 

%.o: %.c *.h
	$(CC) -c $< $(CFL)

clean:
	rm *.o *.exe .*~


