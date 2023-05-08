CXX=g++
CXXFLAGS=-g -ggdb -O2 -Wall

TARGET=main
OBJS=main.o \
	programacaoDinamica.o

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

main.o: programacaoDinamica.h
programacaoDinamica.o: programacaoDinamica.h 

$(TARGET): $(OBJS)
		   $(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
