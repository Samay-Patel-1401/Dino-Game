all :
	g++ -pthread main.cpp display.cpp additional.cpp
	./a.out
	rm a.out
	clear