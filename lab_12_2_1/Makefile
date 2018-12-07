
CC := gcc
CFL := -Wall -Werror
OBJ := var1_functions.o darriu7.o

TEXE += cycle_shift.test.exe 
TEXE += square_filt.test.exe

LFL := -lm

ifeq ($(mod),db)
	CFL += -O0 -g3
endif

ifeq ($(build),dyn)
	CFL += -fpic
endif

run_tests: build_tests
	@echo "--> CYCLE SHIFT TEST <--"
	./cycle_shift.test.exe
	@echo "\n--> SQUARE FILT TEST <--"
	./square_filt.test.exe

libvar1.so: $(OBJ)
	$(CC) -shared -o $@ $^ 

build_tests: $(TEXE)

%.test.exe: %.test.o $(OBJ)
	$(CC) -o $@ $^ $(LFL)

app.exe: $(OBJ)
	$(CC) -o $@ $^ $(LFL)

%.o: %.c 
	$(CC) -c $< $(CFL)

clean:
	$(RM) *.o *.exe .*~ *.so

