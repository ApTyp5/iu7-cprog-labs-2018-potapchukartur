

OBJ := main.o help.o inout.o coding.o sort.o
FLAGS := -Wall -Werror -std=c99

demonstration: a.exe
	./a.exe in_1.txt out.txt
	cat in_1.txt
	cat out.txt
	cat out_1.txt
	
	./a.exe in_2.txt out.txt
	cat in_2.txt
	cat out.txt
	cat out_2.txt
	
	


a.exe: $(OBJ)
	gcc -o $@ $^


%.o: %.c *.h
	gcc -c $< $(FLAGS)


clean:
	rm *.o *.exe .* *~
