OBJECTS = lexer.o example.tab.o symbol.o init.o error.o main.o 
SOURCES = lexer.c example.tab.c symbol.c init.c error.c main.c
EXE = infix2postfix
CFLAGS += -Wall -g


$(EXE):	$(OBJECTS)
	gcc $(CFLAGS) -o $(EXE) $(OBJECTS)

main.o: 	main.c example.tab.h global.h	
	gcc $(CFLAGS) -c main.c

lexer.o: 	lexer.c global.h
	gcc $(CFLAGS) -c lexer.c

symbol.o: 	symbol.c global.h
	gcc $(CFLAGS) -c symbol.c

init.o: 	init.c global.h
	gcc $(CFLAGS) -c init.c

error.o: 	error.c global.h
	gcc $(CFLAGS) -c error.c

example.tab.o: example.tab.c global.h example.tab.h
	gcc $(CFLAGS) -c example.tab.c
	
example.tab.c example.tab.h: example.y
	bison -d example.y
clean: 
	rm -f $(EXE) $(OBJECTS) 29.tar.gz 29.zip *~

archives: clean
	cd ..; rm 29.tar 29.zip 29/29.tar 29/29.zip; tar -cvf 29.tar 29; gzip -9 29.tar; zip -r 29.zip 29; mv 29.zip 29/29.zip; mv 29.tar.gz 29/29.tar.gz


