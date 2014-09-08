app: main.o file.o
		g++ -o app main.o file.o
main.o: main.cpp file.h 
		g++ -c main.cpp
file.o: file.cpp file.h 
		g++ -c file.cpp 
clean:
		rm *.o app