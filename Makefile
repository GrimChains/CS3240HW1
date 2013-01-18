all: data

data: main.o DataPoint.o
    g++ main.o DataPoint.o

main.o: main.cpp
    g++ -c main.cpp

DataPoint.o: DataPoint.h
    g++ -c DataPoint.h

clean:
    rm -rf *.o a.out
