#Makefile for Zoo Tycoon
CC = g++ -std=c++11 -g
exe_file = zoo_tycoon
$(exe_file): Prog.o Amounts.o Zoo.o Animal.o Black_Bear.o Sea_Lion.o Tiger.o
	$(CC) Prog.o Zoo.o Amounts.o Animal.o Black_Bear.o Sea_Lion.o Tiger.o -o $(exe_file)

%.o: %.cpp
	$(CC) -c $<
clean:
	rm -f *.out *.o $(exe_file)
