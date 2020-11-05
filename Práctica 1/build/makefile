# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o sensor.o map.o car.o game.o Chrono.o Colorize.o HeuristicFunction.o EuclideanDistance.o ManhattanDistance.o
# Flags de compilacion
CFLAGS = -c -std=c++17

game: $(OBJECTS)
	g++  $(OBJECTS) -o game
	mv *.o ../objects
	mv game ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

sensor.o: ../src/sensor.cpp ../include/sensor.hpp
	g++ $(CFLAGS) ../src/sensor.cpp

map.o: ../src/map.cpp ../include/map.hpp
	g++ $(CFLAGS) ../src/map.cpp

car.o: ../src/car.cpp ../include/car.hpp
	g++ $(CFLAGS) ../src/car.cpp

game.o: ../src/game.cpp ../include/game.hpp
	g++ $(CFLAGS) ../src/game.cpp

Chrono.o: ../src/Chrono.cpp ../include/Chrono.hpp
	g++ $(CFLAGS) ../src/Chrono.cpp

Colorize.o: ../src/Colorize.cpp ../include/Colorize.hpp
	g++ $(CFLAGS) ../src/Colorize.cpp

HeuristicFunction.o: ../src/HeuristicFunction.cpp ../include/HeuristicFunction.hpp
	g++ $(CFLAGS) ../src/HeuristicFunction.cpp

EuclideanDistance.o: ../src/EuclideanDistance.cpp ../include/EuclideanDistance.hpp
	g++ $(CFLAGS) ../src/EuclideanDistance.cpp

ManhattanDistance.o: ../src/ManhattanDistance.cpp ../include/ManhattanDistance.hpp
	g++ $(CFLAGS) ../src/ManhattanDistance.cpp



.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*


run:
	../bin/game



git:
	git add ../.
	git commit -m "Upload $(TIME)"
	git push
