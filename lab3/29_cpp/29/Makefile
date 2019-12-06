OBJECTS = lexer.o example.tab.o symbol.o init.o error.o main.o 
SOURCES = lexer.cpp example.tab.cpp symbol.cpp init.cpp error.cpp main.cpp
EXE = infix2postfix
CFLAGS += -Wall -g


$(EXE):	$(OBJECTS)
	gcc $(CFLAGS) -o $(EXE) $(OBJECTS)

main.o: 	main.cpp example.tab.hpp global.h	
	gcc $(CFLAGS) -c main.cpp

lexer.o: 	lexer.cpp global.h
	gcc $(CFLAGS) -c lexer.cpp


symbol.o: 	symbol.cpp global.h
	gcc $(CFLAGS) -c symbol.cpp

init.o: 	init.cpp global.h
	gcc $(CFLAGS) -c init.cpp

error.o: 	error.cpp global.h
	gcc $(CFLAGS) -c error.cpp

example.tab.o: example.tab.cpp global.h example.tab.hpp
	gcc $(CFLAGS) -c example.tab.cpp
	

clean: 
	rm -f $(EXE) $(OBJECTS) 29.tar.gz 29.zip *~

archives: clean
	cd ..; rm 29.tar 29.zip 29/29.tar 29/29.zip; tar -cvf 29.tar 29; gzip -9 29.tar; zip -r 29.zip 29; mv 29.zip 29/29.zip; mv 29.tar.gz 29/29.tar.gz


