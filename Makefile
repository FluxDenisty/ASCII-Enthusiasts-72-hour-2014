run: Game
	./Game

Game: main.cc
	g++ $^ -o $@
