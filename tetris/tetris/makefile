GDB = -g

all: ../tetris.a

../tetris.a: tetris.o tetris_I.o tetris_L.o tetris_L_M.o\
			tetris_T.o tetris_X.o tetris_Z.o tetris_Z_M.o
	ar crv ../tetris.a *.o

tetris.o: tetris.cpp tetris.h
	g++ -c tetris.cpp $(GDB)

tetris_I.o: tetris_I.cpp tetris.h
	g++ -c tetris_I.cpp $(GDB)

tetris_L.o: tetris_L.cpp tetris.h
	g++ -c tetris_L.cpp $(GDB)

tetris_L_M.o: tetris_L_M.cpp tetris.h
	g++ -c tetris_L_M.cpp $(GDB)

tetris_T.o: tetris_T.cpp tetris.h
	g++ -c tetris_T.cpp $(GDB)

tetris_X.o: tetris_X.cpp tetris.h
	g++ -c tetris_X.cpp $(GDB)

tetris_Z.o: tetris_Z.cpp tetris.h
	g++ -c tetris_Z.cpp $(GDB)

tetris_Z_M.o: tetris_Z_M.cpp tetris.h
	g++ -c tetris_Z_M.cpp $(GDB)

.PHONY: clean
clean:
	-rm -f *.o
