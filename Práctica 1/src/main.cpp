/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     main.cpp                                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
    =                           Yeixon Morales Gonzalez                            =
    =            Fecha:         08/10/2020                                         =
    =            Subject:       Inteligencia Artificial                            =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =                           alu0101022239@ull.edu.es                           =
    =                           alu0101133324@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Adrian Epifanio
* 		   Luciano Sekulic 
* 		   Yeixon Morales 
* @Date:   2020-10-08 11:04:26
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-30 08:50:57
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/game.hpp"
#include "../include/Colorize.hpp"

/*------------------------------------------------*/

#include <iostream>

int main (void) {
	srand(time(NULL));	// For generating random numbers
	Game newGame("../inputs/input.txt");
	//newGame.generateRandomObstacles(150);
	newGame.get_Map().printMap(std::cout);
}	