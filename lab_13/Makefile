CC := gcc
CLF := -Wall -Werror








app.exe: main.o
	$(CC) -o $@ $^

test.exe: main.o
	$(CC) -o $@ $^

ftest: main.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFL) -c $< 

clean:
	$(RM) *.exe *.o

