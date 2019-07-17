## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags
CPPFLAGS = -Wall -g -DLINUX
LFLAGS = -lglut -L/usr/lib -L/usr/X11R6/lib -lXi -lXmu -lGL -lGLU -lm

TARGETS = $(PROGFILES:.cpp=)

PROGFILES = \
        assn1.cpp \
        rain.cpp \
        controller.cpp \
        $(NULL)

targets default: $(TARGETS)

$(PROGFILES:.cpp=): assn1.o rain.o controller.o
	$(CC) -o assn1 assn1.o rain.o controller.o ${LFLAGS}

depend :
	makedepend ${PROGFILES}
	
clean :
	rm *.o
	rm assn1
# DO NOT DELETE
