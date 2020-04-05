COMPIL = g++
EXEC = jeu
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(COMPIL) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(COMPIL) -o $@ $^

.PHONY :

clean : .PHONY
