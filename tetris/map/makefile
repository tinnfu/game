GDB = -g

all: map.o
map.o: map.*
	g++ -c map.cpp $(GDB)

.PHONY: clean
clean:
	-rm -f map.o
