
F := -Wall -Werror

run_mod_tests: test.exe
	./test.exe


test.exe:
	gcc -o $@ my_strrchr.c test.c $(F)


clean:
	rm *.exe *.o
