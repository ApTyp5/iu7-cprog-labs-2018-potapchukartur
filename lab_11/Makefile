CC = gcc
OBJ  = my_snprintf.o
CFL = -Wall -Werror -std=c99 -pedantic


ifeq ($(mod),db)
	CFL += -O0 -g3
endif

app.exe: $(OBJ)


test.exe: $(OBJ) test.o
	$(CC) $(LFL) -o $@ $^

%.o: %.c 
	$(CC) $(CFL) -c $< 

clean:
	$(RM) *.o *.exe
