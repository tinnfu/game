GDB = -g

all: main

main: main.o map.o tetris.a tetris_ui.a keyboard_clock.o
	g++ -o main main.o map.o tetris.a tetris_ui.a keyboard_clock.o

main.o: main.cpp
	g++ -c main.cpp $(GDB)

map.o: map/map.*
	g++ -c map/map.cpp $(GDB)

tetris.a: tetris/tetris*
	@(cd tetris; make)

tetris_ui.a: tetris_ui/tetris_ui*
	@(cd tetris_ui; make)

keyboard_clock.o: keyboard_clock/keyboard_clock.*
	g++ -c keyboard_clock/*.cpp -g

.PHONY: clean

clean:
	-rm -f main *.o *.a
	@(cd tetris; make clean)
	@(cd tetris_ui; make clean)
