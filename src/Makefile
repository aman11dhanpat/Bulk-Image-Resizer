CC=g++
CFLAGS=-g

all: main.cpp files.cpp files.h process_io.h process_io.cpp
	$(CC) $(CFLAGS) -c files.cpp -o files.o
	$(CC) $(CFLAGS) -c process_io.cpp -o process_io.o
	$(CC) $(CFLAGS) files.o process_io.o main.cpp -o bir
clean:
	rm bir *.o *~
