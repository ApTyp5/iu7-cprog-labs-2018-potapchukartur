CC := gcc
FLAGS := -Wall -Werror
OBJ := fileworks.o


a.exe: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c *.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.exe *.o .*~
