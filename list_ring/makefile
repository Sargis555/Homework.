EXE = exe
SOURCES = src/*
INC_PATH = inc/

.PHONY : clean

$(EXE) : $(SOURCES)
	g++ $^ -o $@ -I $(INC_PATH)

clean :
	rm $(EXE)
