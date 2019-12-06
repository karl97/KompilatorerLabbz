# Makefile för debug-övningsuppgiften
# Skriv bara "make" för att kompilera programmet metamatic!

OFILES = metamatic.o a.o abc.o abscissa.o absurdum.o ack.o

CPPFLAGS += -g

metamatic: $(OFILES)
	g++ -g $(OFILES) -o metamatic

clean:
	$(RM) $(OFILES) metamatic debug-exercise.tar.gz debug-exercise.zip *~

archives: clean
	cd ..; rm debug-exercise.tar debug-exercise.zip debug-exercise/debug-exercise.tar debug-exercise/debug-exercise.zip; tar -cvf debug-exercise.tar debug-exercise; gzip -9 debug-exercise.tar; zip -r debug-exercise.zip debug-exercise; mv debug-exercise.zip debug-exercise/debug-exercise.zip; mv debug-exercise.tar.gz debug-exercise/debug-exercise.tar.gz
