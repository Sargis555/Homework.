
EXE:=exe
$(EXE) : main.cpp list.tpp list.hpp
	g++ -std=c++11 -g -ggdb $<  -Wall -pedantic -o $@

clean:
	rm $(EXE)
