app: main.o file.o tax.o cmd.o
		g++ -o app main.o file.o tax.o cmd.o
main.o: main.cpp file.h 
		g++ -c main.cpp
file.o: file.cpp file.h 
		g++ -c file.cpp 
tax.o: tax.cpp tax.h 
		g++ -c tax.cpp 
cmd.o: cmd.cpp cmd.h 
		g++ -c cmd.cpp 
clean:
		rm *.o app