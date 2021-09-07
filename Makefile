CC = g++
CFLAGS = -Wall -Werror -pedantic
EXE = NBody
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
DEPS = CelestialBody.h Universe.h
OBJS = CelestialBody.o NBody.o Universe.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBS)
%.o : %.cpp $(DEPS)
	$(CC) -c  -o $@ $<
clean:
	rm $(EXE) $(OBJS) output.txt
