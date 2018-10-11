CC := gcc
OBJ := main.o inout.o action.o prompt.o aplog.o Ghauss.o
TOBJ := test.o
CFLAGS := -Wall -Werror -std=c99 -pedantic
LFLAGS := 



test: app.exe
	./app.exe o in_21 out
	cat log
	cat in_21
	cat out
	rm log

app.exe: $(OBJ)
	gcc -o $@ $^ $(LFLAGS)
	

test.exe: $(TOBJ)
	gcc -o $@ $^ $(LFLAGS)

%.o: %.c *.h
	gcc -c $< $(CFLAGS)

clean:
	rm *.o *.exe .*~ 


