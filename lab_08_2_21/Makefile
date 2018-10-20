CC := gcc
OBJ := main.o inout.o action.o prompt.o Ghauss.o
TOBJ := test.o inout.o action.o prompt.o Ghauss.o
CFLAGS := -Wall -Werror -std=c99 -pedantic
mod=rel


ifeq ($(mod),db)
	LFLAGS:=-O0 -g3
endif

ifeq ($(mod),rel)
	CFLAGS := $(CFLAGS) -DNDEBUG
endif



mod_tests: test.exe
	./test.exe

func_test: app.exe
	./func_test

app.exe: $(OBJ)
	gcc -o $@ $^ $(LFLAGS)

test.exe: $(TOBJ)
	gcc -o $@ $^ $(LFLAGS)

%.o: %.c *.h
	gcc -c $< $(CFLAGS)

clean:
	rm *.o *.exe .*~ 


