SOURCES=calcvect.c vector.c iovector.c
OBJS=calcvect.o vector.o iovector.o
HEADERS=vector.h iovector.h
CC=gcc

p: $(OBJS)
	$(CC) $^ -o $@ -lm
calcvect.o: calcvect.c $(HEADERS)
vector.o: vector.h
iovector.o: iovector.h
proyecto.tar: $(SOURCES) $(HEADERS) makefile
	tar -cvf $@ $^
clean:
	rm *.o
