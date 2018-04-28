CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -Wextra -pedantic -Wfloat-equal
BIN=prog

SRC=$(wildcard *.c*)
OBJ=$(SRC:%.c*=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)
