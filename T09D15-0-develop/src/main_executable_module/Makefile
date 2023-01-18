
all: Quest_3 build_with_static build_with_dynamic
Quest_3: main_executable_module.o data_process.o data_io.o data_stat.o decision.o
	gcc main_executable_module.o data_process.o data_io.o data_stat.o decision.o -o ../../build/Quest_3 

build_with_static: main_executable_module.o data_process.o data_io.o data_stat.a decision.o
	gcc main_executable_module.o data_process.o data_io.o data_stat.a decision.o -o ../../build/Quest_5 

build_with_dynamic: main_executable_module.o data_process.so data_io.o data_stat.a decision.o
	gcc main_executable_module.o data_process.so data_io.o data_stat.a decision.o -o ../../build/Quest_6
	cp ../../build/Quest_6 Quest_6 
	
main_executable_module.o: main_executable_module.c
	gcc -Wall -Werror -Wextra -c main_executable_module.c -o main_executable_module.o
data_process.so : data_process.o data_stat.o
	gcc -c  ../data_module/data_process.c -o data_process.o
	gcc -c ../data_libs/data_stat.c -o data_stat.o
	gcc -shared  -fPIC -o data_process.so data_process.o data_stat.o
	
data_process.o : ../data_module/data_process.c
	gcc -Wall -Werror -Wextra -c ../data_module/data_process.c -o data_process.o
data_io.o : ../data_libs/data_io.c
	gcc -Wall -Werror -Wextra -c ../data_libs/data_io.c -o data_io.o
data_stat.a : data_stat.a
	gcc -c ../data_libs/data_stat.c -o data_stat.o
	ar rc data_stat.a data_stat.o
data_stat.o : ../data_libs/data_stat.c
	gcc -Wall -Werror -Wextra -c ../data_libs/data_stat.c -o data_stat.o
decision.o : ../yet_another_decision_module/decision.c
	gcc -Wall -Werror -Wextra -c ../yet_another_decision_module/decision.c -o decision.o
clean :
	rm -rf *.o ../../build/Quest_3 ../../build/Quest_5 ../../build/Quest_6
rebuild: clean Quest_3 build_with_static build_with_dynamic


 
