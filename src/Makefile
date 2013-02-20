CC=g++
CFLAGS=-g 

all: main.cpp files.cpp files.h process_io.h process_io.cpp img_proc.cpp img_proc.h
	$(CC) -c files.cpp -o files.o
	$(CC) -c process_io.cpp -o process_io.o
	$(CC) `pkg-config --cflags opencv` -c img_proc.cpp -o img_proc.o
	$(CC) $(CFLAGS) `pkg-config --cflags opencv` files.o process_io.o img_proc.o main.cpp `pkg-config --libs opencv` -o bir
clean:
	rm bir *.o *~
