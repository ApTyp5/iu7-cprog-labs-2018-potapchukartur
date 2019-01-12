CC := gcc
CFL := -Wall -Werror
EXE := test.exe

ifeq ($(m),db)
	CFL += -g3
endif


build_com_mod_tests: mtests.o common_mtr.o
	$(CC) $(CFL) -o $(EXE) $^

build_spa_mod_tests: mtests.o spared_mtr.o
	$(CC) $(CFL) -o $(EXE) $^

%.o: %.c
	$(CC) $(CFL) -c $<

clean:
	$(RM) *.o *.exe

