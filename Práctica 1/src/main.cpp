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
* @Last Modified time: 2020-10-30 09:37:09
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
	std::ofstream os("../outputs/output.txt");
	std::ofstream os2("../inputs/savedMap.txt");
	newGame.get_Map().saveMap(os);
    newGame.saveData(os2);
}	