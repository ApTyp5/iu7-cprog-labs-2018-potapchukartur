CC := gcc
OBJ := weather.o
EXE := app
CFL += -Wall -Werror

ifeq ($(mod),db)
	CFL += -O0 -g3
endif




build: main.o $(OBJ)
	$(CC) -o $(EXE) $^

run: build
	./$(EXE) -i STC.csv

%.o: %.c
	$(CC) $(CFL) -c $<

clean:
	$(RM) *.exe *.o app


