OBJECTS = dfa.o
SOURCES = dfa.c
CC = gcc
CFLAGS += -Wall -Wextra -std=c11 -O3
EXE = statemachine


$(EXE):	$(OBJECTS)
	gcc $(CFLAGS) -o $(EXE) $(OBJECTS)

dfa.o: 	dfa.c 
	gcc $(CFLAGS) -c dfa.c

clean: 
	rm -f $(EXE) $(OBJECTS) *~

archives: clean
