ifdef OPT
  CCFLAGS = -O2
else
  CCFLAGS = -g
endif

CC=g++
SOURCES=main.cpp TypeDesc.cpp Symbol.cpp Env.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

%.o: %.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f sat *.o
