all: main Practica2

main: main.cpp
	g++ -c main.cpp src/Graph.cpp src/Menu.cpp src/GenGraph.cpp src/MinLenghtProblem.cpp src/TSPProblem.cpp src/Test_MLP.cpp src/Test_TSP.cpp -std=c++11 

Practica2: 
	g++ *.o -o Practica2 -lncurses
clean:
	rm -f *.o Practica2
	
