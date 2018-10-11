CC=g++
CCFLAGS=-c -Wall -Wextra -MD -Iinclude
PROG=out
RUN=./out
LDFLAGS=
LDLIBS=

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

all: $(SRC) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LDLIBS)

.cpp.o:
	$(CC) $(CCFLAGS) $< -o $@

clean: 
	rm -f $(PROG) $(OBJ) $(DEP)

-include $(DEPFILES)

valgrind:
	valgrind --leak-check=full $(RUN)

cppcheck:
	cppcheck --quiet --error-exitcode=1 .

