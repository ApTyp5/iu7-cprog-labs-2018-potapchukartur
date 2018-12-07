CC := gcc
FLAGS := -Wall -Werror 
TES_OBJ := test.o fileworks.o filt.o sort.o
LIB_OBJ := fileworks.o filt.o sort.o process.o
EXE := app.exe


ifeq ($(mod),db)
	DBFLAGS += -g3 -O0
endif

ifeq ($(mod),rel)
	FLAGS += -DNDEBUG
endif

ifeq ($(build),dyn)
	FLAGS += -fpic
endif


liblab_07.a: $(LIB_OBJ)
	ar rc $@ $^

liblab_07.so: $(LIB_OBJ)
	$(CC) -shared -o $@ $^

	



build_with_dyn_load_lib: dyn_load_main.o loading_lib.o
	make liblab_07.so
	$(CC) -o $(EXE) $^ -ldl

build_with_dyn_link_lib: main.o liblab_07.so
	$(CC) -o $(EXE) $< -L. -llab_07 -Wl,-rpath,. 

build_with_stat_lib: main.o liblab_07.a
	$(CC) -o $(EXE) $< -L. -llab_07 





run_mod_tests: test.exe
	./test.exe

run_func_tests: build_with_stat_lib
	./run_func_tests	
	rm out
	
test.exe: $(TES_OBJ)
	$(CC) -o $@ $^

main.o: main.c
	$(CC) -c $< -Wall -Werror $(DBFLAGS)

dyn_load_main.o: dyn_load_main.c
	$(CC) -c $< -Wall -Werror $(DBFLAGS)

%.o: %.c
	$(CC) -c $< $(FLAGS) $(DBFLAGS)

clean:
	$(RM) *.exe *.o .*~ *.so *.a
