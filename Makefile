CC=g++
EXEC=output

GAME_FOLDER=./Game
LINES_FOLDER=./Lines

FLAGS="-std=c++11"
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(EXEC): main.o game.o lines.o
	$(CC) main.o game.o lines.o $(FLAGS) $(SFML_FLAGS) -g -o $(EXEC) 

main.o: main.cpp
	$(CC) $(FLAGS) -c -g main.cpp

game.o: $(GAME_FOLDER)/game.cpp
	$(CC) $(FLAGS) -c -g $(GAME_FOLDER)/game.cpp

lines.o: $(LINES_FOLDER)/lines.cpp
	$(CC) $(FLAGS) -c -g $(LINES_FOLDER)/lines.cpp

clean:
	rm *.o $(EXEC)