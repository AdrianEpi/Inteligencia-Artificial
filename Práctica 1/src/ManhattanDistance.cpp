/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     ManhattanDistance.cpp                              =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
    =                           Yeixon Morales Gonzalez                            =
    =            Date:          05/11/2020                                         =
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
* @Date:   2020-11-05 15:50:33
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-14 08:58:21
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/ManhattanDistance.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
ManhattanDistance::ManhattanDistance (void) {
}

/**
 * @brief      Destroys the object.
 */
ManhattanDistance::~ManhattanDistance (void) {
}

/**
 * @brief      Calculates the distance using the manhattan distance.
 *
 * @param      startLine   The start line
 * @param[in]  finishLine  The finish line
 *
 * @return     The distance.
 */
float ManhattanDistance::calculateDistance (std::pair<unsigned, unsigned>& startLine, std::pair<unsigned, unsigned>& finishLine) {
    return (abs(finishLine.first - startLine.first) + abs(finishLine.second - startLine.second));
}