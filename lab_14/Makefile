CC := gcc
CFL := -Wall -Werror


build_com_mod_tests: mtests.o common_mtr.o
	$(CC) $(CFL) -o $@ $^

build_spa_mod_tests: mtest.o spared_mtr.o
	$(CC) $(CFL) -o $@ $^

%.o: %.c
	$(CC) $(CFL) -c $<

clean:
	$(RM) *.o *.exe

