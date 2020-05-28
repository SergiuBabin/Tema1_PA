build:	
	g++ -std=c++11 -o bani src/bani.cpp
	g++ -std=c++11 -o gard src/gard.cpp
	g++ -std=c++11 -o bomboane src/bomboane.cpp
	g++ -std=c++11 -o sala src/sala.cpp
run-p1:	
	./bani
run-p2: 
	./gard
run-p3: 
	./bomboane
run-p4: 
	./sala
clean:	
	rm bani gard bomboane sala
