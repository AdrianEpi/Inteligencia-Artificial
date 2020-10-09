/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     main.cpp                                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         08/10/2020                                         =
    =            Subject:       Inteligencia Artificial                            =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Adrian Epifanio
* @Date:   2020-10-08 11:04:26
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-09 16:48:38
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/sensor.hpp"
#include "../include/map.hpp"
#include "../include/car.hpp"

/*------------------------------------------------*/

#include <iostream>

int main (void) {
	// Test create a sensor
	Sensor test;
	// Testing maps sizes
	Map a;
	a.initialize(2, 3);
	a.printMap(std::cout);
	Map b;
	b.initialize(7, 9);
	a.set_Map(b.get_Map());
	a.addObstacle(5,5);
	a.addObstacle(3,5);
	a.addObstacle(1,4);
	a.printMap(std::cout);
	// Test create a car
	Car newCar;
}