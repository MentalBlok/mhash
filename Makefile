
CC=/usr/bin/g++

CFLAGS= -O2
WFLAGS= -Wunused-variable

all: obj xmain.exe

OBJECTS = main.o Mhash.o

OBJS = $(addprefix obj/, $(OBJECTS))

xmain.exe: $(OBJS)
	${CC} ${CFLAGS} $(LDFLAGS) $(WFLAGS) $(OBJS) -o xmain

obj: 
	-mkdir obj

obj/main.o: main.cpp
	${CC} -c ${CFLAGS} main.cpp -o $@

obj/Mhash.o: Mhash.cpp switch.cpp
	${CC} -c ${CFLAGS} Mhash.cpp -o $@

test: xmain.exe 
	./xmain.exe

clean:
	-rm -f *.exe *.stackdump $(OBJS)

diff:
	-rcsdiff *.cpp Makefile

ci:
	-ci -l *.cpp Makefile

