SOURCES=clase.c principal.c auxi.c
HEADERS=alumno.h clase.h auxi.h
CC= gcc
OBJS=clase.o principal.o auxi.o

p: $(OBJS)
	$(CC) $^ -o $@
principal.o: principal.c $(HEADERS)
clase.o: clase.h
auxi.o: auxi.h
proyecto.tar: $(SOURCES) $(HEADERS) makefile
	tar -cvf $@ $^
clean:
	rm *.o
