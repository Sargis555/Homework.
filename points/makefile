EXE = exe
SOURCES = src/*
INC_PATH = inc/

.PHONY : clean

$(EXE) : $(SOURCES)#main.cpp point.cpp line.cpp point.h
	g++ $^ -o $@ -I $(INC_PATH)

clean:
	rm $(EXE)
