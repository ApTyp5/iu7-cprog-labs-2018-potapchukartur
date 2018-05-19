CC = gcc

COMPFLAGS = -Wall -Werror -pedantic -std=c99 

OFILES = inout.o crypto.o fill.o main.o

app.exe: $(OFILES)
	$(CC) -o $@ $^ 
	
%.o: %.c *.h
	$(CC) -c $< $(COMPFLAGS)



clean:
	rm *.o *.c

