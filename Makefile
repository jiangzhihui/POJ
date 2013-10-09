all:compile
	./a.out < input 
compile:
	g++ -Wall -g 2431.cc
