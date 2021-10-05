gcc_options = -std=c++17 -Wall --pedantic-errors
l_b = -llapacke -lblas

program : main.o printmat.o power.o function.o
	g++ -o $@ $^ $(l_b)

main.o : main.cpp
	g++ -c $< $(l_b)

printmat.o : printmat.cpp
	g++ -c $< $(l_b)

power.o : power.cpp
	g++ -c $< $(l-b)

function.o : function.cpp
	g++ -c $< $(l-b)


run : program
	./program

clean:
	rm -f ./program

.PHONY : run clean
