build: execu

all: clean archive build 

archive:
	mkdir othellosource
	cp *.cc othellosource
	cp Makefile othellosource
	tar -cvf othelloarchive.tar.gz othellosource
	rm -r othellosource

execu: main.o game.o othello.o piece.o 
	g++ main.o game.o othello.o piece.o -o execu

main.o: main.cc
	g++ -c main.cc

game.o: game.cc game.h
	g++ -c game.cc

othello.o: othello.cc othello.h colors.h 
	g++ -c othello.cc

piece.o: piece.cc 
	g++ -c piece.cc

clean: 
	rm -f *.o execu
	rm -f *.gz
