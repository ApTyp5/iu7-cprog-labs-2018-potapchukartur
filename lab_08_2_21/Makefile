CC := gcc
OBJ := main.o inout.o action.o prompt.o
TOBJ := test.o
CFLAGS := -Wall -Werror -std=c99 -pedantic
LFLAGS :=




app.exe: $(OBJ)
	gcc -o $@ $^ $(LFLAGS)
	

test.exe: $(TOBJ)
	gcc -o $@ $^ $(LFLAGS)

%.o: %.c *.h
	gcc -c $< $(CFLAGS)

clean:
	rm *.o *.exe .*~ 


