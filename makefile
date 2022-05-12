CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

test-1-board: test/test-1-board.cpp board.o test/catch/catch.o
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

main: board.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc test/test-1-board