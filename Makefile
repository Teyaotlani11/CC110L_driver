
C_FILES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(C_FILES))

all: $(OBJECTS) 
	$(CC) -o ANAREN_RUN.out $(OBJECTS)

main.o: main.c	
	$(CC) -c $< -o $@

spi_wraper.o: spi_wraper.c spi_wraper.h
	$(CC) -c $< -o $@
	
.PHONY : clean
clean :
	-rm *.out $(OBJECTS)

