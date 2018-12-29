CC := gcc
CLF := -Wall -Werror
OBJ := main.o mess.o stat.o


ifeq ($(mod),db)
	CFL += -O0 -g3
endif






app.exe: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFL) -c $< 

clean:
	$(RM) *.exe *.o

