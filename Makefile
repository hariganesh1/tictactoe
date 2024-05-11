# Makefile, update for use with SFML later

CXX ?= g++

CXXFLAGS ?= --std=c++17 -fsanitize=address -fsanitize=undefined

tictactoe-std.exe: tictactoe-std.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

main-std.exe: tictactoe-std.cpp main-std.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	rm -rvf *.out *.exe *.dSYM *.stackdump