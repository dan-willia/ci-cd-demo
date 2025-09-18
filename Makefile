CXX = g++
CXXFLAGS	= -std=c++17 -Wall -Werror -Wpedantic

all: test

clean:
	rm test

test: test.cpp functions_to_implement.o
	$(CXX) $(CXXFLAGS) test.cpp -o test

functions_to_implement.o: functions_to_implement.cpp
	$(CXX) $(CXXFLAGS) -c functions_to_implement.cpp
