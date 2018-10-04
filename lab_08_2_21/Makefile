CC := gcc
FLAGS := -Wall -Werror -std=c99 -pedantic
OBJ := main.o inout.o
TOBJ := test.o inout.o
LFLAGS :=






app.exe: $(OBJ)
	gcc -o $@ $^ $(LFLAGS)

test.exe: $(TOBJ)
	gcc -o $@ $^ $(LFLAGS)



