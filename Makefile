CC = g++

mysort: mysort.o
	$(CC) -o $@ $^

mysort.o: SimulateSort.cxx
	$(CC) -c -o $@ $^

myuniq: myuniq.o
	$(CC) -o $@ $^

myuniq.o: SimulateUniq.cxx
	$(CC) -c -o $@ $^

clean:
	rm *.o
