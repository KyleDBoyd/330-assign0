app: main.o file.o tax.o cmd.o
		g++ -std=gnu++11 -o app main.o file.o tax.o cmd.o 
main.o: main.cpp file.h 
		g++ -std=gnu++11 -c main.cpp
file.o: file.cpp file.h 
		g++ -std=gnu++11 -c file.cpp 
tax.o: tax.cpp tax.h 
		g++ -std=gnu++11 -c tax.cpp 
cmd.o: cmd.cpp cmd.h 
		g++ -std=gnu++11 -c cmd.cpp 
clean:
		rm *.o app
