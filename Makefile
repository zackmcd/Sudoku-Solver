solver.out : main.o solver.o
	g++ -Wall -o solver.out main.o solver.o

main.o : main.cpp solver.h
	g++ -Wall -g -c main.cpp

solver.o : solver.cpp solver.h
	g++ -Wall -g -c solver.cpp

clean :
	rm -f solver.out main.o solver.o
