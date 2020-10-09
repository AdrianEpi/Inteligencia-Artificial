# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o sensor.o map.o car.o
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
