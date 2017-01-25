GDB = -g

all: ../tetris_ui.a

../tetris_ui.a: tetris_ui.o tetris_ui_I.o tetris_ui_L.o tetris_ui_L_M.o\
			tetris_ui_T.o tetris_ui_X.o tetris_ui_Z.o tetris_ui_Z_M.o
	ar crv ../tetris_ui.a *.o

tetris_ui.o: tetris_ui.cpp tetris_ui.h
	g++ -c tetris_ui.cpp $(GDB)

tetris_ui_I.o: tetris_ui_I.cpp tetris_ui.h
	g++ -c tetris_ui_I.cpp $(GDB)

tetris_ui_L.o: tetris_ui_L.cpp tetris_ui.h
	g++ -c tetris_ui_L.cpp $(GDB)

tetris_ui_L_M.o: tetris_ui_L_M.cpp tetris_ui.h
	g++ -c tetris_ui_L_M.cpp $(GDB)

tetris_ui_T.o: tetris_ui_T.cpp tetris_ui.h
	g++ -c tetris_ui_T.cpp $(GDB)

tetris_ui_X.o: tetris_ui_X.cpp tetris_ui.h
	g++ -c tetris_ui_X.cpp $(GDB)

tetris_ui_Z.o: tetris_ui_Z.cpp tetris_ui.h
	g++ -c tetris_ui_Z.cpp $(GDB)

tetris_ui_Z_M.o: tetris_ui_Z_M.cpp tetris_ui.h
	g++ -c tetris_ui_Z_M.cpp $(GDB)

.PHONY: clean
clean:
	-rm -f *.o
