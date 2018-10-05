CC := gcc
FLAGS := -Wall -Werror -std=c99 -pedantic
OBJ := main.o inout.o
TOBJ := test.o inout.o


ifeq ($(mod),db)
	LFLAGS := -g3 -O0
endif





app.exe: $(OBJ)
	gcc -o $@ $^ $(LFLAGS)

test.exe: $(TOBJ)
	gcc -o $@ $^ $(LFLAGS)

%.o : %.c *.h
	gcc -c $< $(FLAGS)

clean:
	rm *.o *.exe .*~ *.test



