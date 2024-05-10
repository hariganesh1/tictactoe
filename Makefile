# Makefile
# Update for use with SFML later

CXX ?= g++

CXXFLAGS ?= --std=c++17 -fsanitize=address -fsanitize=undefined

tictactoe.exe: tictactoe.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
main.exe: tictactoe.cpp main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
clean: 
	rm -rvf *.out *.exe *.dSYM *.stackdump