CC := gcc
OBJ := weather.o
EXE := app





build: main.o $(OBJ)
	$(CC) $(CFL) -o $(EXE) $^

run:
	app -i <input_file>

clean:
	$(RM) *.exe *.o app


