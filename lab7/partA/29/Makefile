OBJECTS = example.tab.o symbol.o init.o main.o lex.yy.o StackMachine.o
SOURCES = example.tab.cpp symbol.cpp  init.cpp  main.cpp  lex.yy.cpp StackMachine.cpp
EXE = infix2postfix
CFLAGS += -Wall -g


$(EXE):	$(OBJECTS)
	g++ $(CFLAGS) -o $(EXE) $(OBJECTS)

main.o: 	main.cpp  example.tab.h global.h	
	g++ $(CFLAGS) -c main.cpp 

symbol.o: 	symbol.cpp  global.h
	g++ $(CFLAGS) -c symbol.cpp 

init.o: 	init.cpp  global.h
	g++ $(CFLAGS) -c init.cpp 

lexer.o: 	lexer.cpp  global.h
	g++ $(CFLAGS) -c lexer.cpp 

error.o: 	error.cpp  global.h
	g++ $(CFLAGS) -c error.cpp 

example.tab.o: example.tab.cpp  global.h example.tab.hpp
	g++ $(CFLAGS) -c example.tab.cpp 

example.tab.cpp  example.tab.h: example.ypp
	bison -d example.ypp

lex.yy.cpp : example.l
	flex example.l
	mv lex.yy.c lex.yy.cpp
clean: 
	rm -f $(EXE) $(OBJECTS) 29.tar.gz 29.zip *~

archives: clean
	cd ..; rm 29.tar 29.zip 29/29.tar 29/29.zip; tar -cvf 29.tar 29; gzip -9 29.tar; zip -r 29.zip 29; mv 29.zip 29/29.zip; mv 29.tar.gz 29/29.tar.gz


