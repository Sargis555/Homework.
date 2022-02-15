EXE = exe
SOURCES = tree.cpp main.cpp
INC_PATH = /

.PHONY : clean

$(EXE) : $(SOURCES)
	g++ $^ -o $@ -I $(INC_PATH)

clean :
	rm $(EXE)

