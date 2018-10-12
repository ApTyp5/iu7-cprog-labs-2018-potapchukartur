CC := gcc
OBJ := main.o inout.o action.o prompt.o aplog.o Ghauss.o
TOBJ := test.o inout.o action.o prompt.o aplog.o Ghauss.o
CFLAGS := -Wall -Werror -std=c99 -pedantic


ifeq ($(mod),db)
	LFLAGS:=-O0 -g3
endif

ifeq ($(mod),rel)
	CFLAGS := $(CFLAGS) -DNDEBUG
endif



test: app.exe
	./app.exe o in_21 out
	cat log
	cat in_21
	cat out
	rm log

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


