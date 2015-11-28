CC = g++
OBJ = SimulateSort.o

simulatesort: $(OBJ)
	g++ -o $@ $^

%.o: %.cxx
	g++ -c -o $@ $^

clean:
	rm simulatesort *.o
