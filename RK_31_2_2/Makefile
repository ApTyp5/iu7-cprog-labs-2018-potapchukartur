CC := gcc
CFL := -Wall -Werror

OBJ := mtr.o fileworks.o list.o main.o list.o

ifeq ($(mod),db)
	CFL += -O0 -g3
endif

ifeq ($(mod), db)
	CFL += -O3 -g0 -DNDEBUG
endif


run: build

build: $(OBJ)
	$(CC) -o rk1.exe $^

%.o: %.c
	$(CC) $(CFL) -c $<

clean:
	$(RM) *o *.exe


