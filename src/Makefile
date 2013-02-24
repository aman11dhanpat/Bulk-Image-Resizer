CXX=g++
CXXFLAGS=-g 
OPENCVFLAGS=`pkg-config --cflags opencv`
OPENCVLDFLAGS=`pkg-config --libs opencv`
LD=ld

all: main.cpp files.cpp files.h process_io.h process_io.cpp img_proc.cpp img_proc.h
	$(CXX) $(CXXFLAGS) -c files.cpp -o files.o
	$(CXX) $(CXXFLAGS) -c process_io.cpp -o process_io.o
	$(CXX) $(CXXFLAGS) $(OPENCVFLAGS) -c img_proc.cpp -o img_proc.o
	$(CXX) $(CXXFLAGS) $(OPENCVFLAGS) files.o process_io.o img_proc.o main.cpp $(OPENCVLDFLAGS) -o bir
clean:
	rm bir *.o *~
