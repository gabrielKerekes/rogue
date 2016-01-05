test:
	make build;
	make run;

build:
	g++ main.cpp -o rogue.o -lncurses

run:
	./rogue.o