EXE = exe
SOURCES = main.cpp string.cpp
HEADER = string.h

.PHONY : clean

exe : $(SOURCES) $(HEADER)
	g++ $^ -o $@ 

clean:
	rm exe
