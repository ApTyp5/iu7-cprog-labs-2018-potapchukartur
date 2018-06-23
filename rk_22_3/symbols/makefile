

OBJ := main.o help.o inout.o coding.o
FLAGS := 

demonstration: a.exe
	./a.exe in_1.txt out.txt
	./a.exe in_2.txt out.txt
	./a.exe in_3.txt out.txt

a.exe: $(OBJ)
	gcc -o $@ $^


%.o: %.c *.h
	gcc -c $< $(FLAGS)


clean:
	rm *.o *.exe .* *~
