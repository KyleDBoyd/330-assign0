app: main.o file.o tax.o
		g++ -o app main.o file.o tax.o
main.o: main.cpp file.h 
		g++ -c main.cpp
file.o: file.cpp file.h 
		g++ -c file.cpp 
tax.o: tax.cpp tax.h 
		g++ -c tax.cpp 
clean:
		rm *.o app