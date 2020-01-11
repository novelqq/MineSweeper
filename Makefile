MineSweeper: main.cpp
	g++ main.cpp game.cpp -o MineSweeper -lglut -lGLU -lGL -lstdc++

clean:
	rm -f *.o MineSweeper