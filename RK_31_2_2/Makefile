CC := gcc
CFL := -Wall -Werror

OBJ := mtr.o fileworks.o list.o main.o list.o

ifeq ($(mod),db)
	CFL += -O0 -g3 -DNDEBUG
endif

run: build

build: $(OBJ)
	$(CC) -o rk1.exe $^

%.o: %.c *.h
	$(CC) $(CFL) -c $<

clean:
	rm *o *.exe


