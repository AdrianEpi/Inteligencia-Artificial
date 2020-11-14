/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     EuclideanDistance.cpp                              =
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
* @Last Modified time: 2020-11-14 09:40:33
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/EuclideanDistance.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
EuclideanDistance::EuclideanDistance (void) {
}

/**
 * @brief      Destroys the object.
 */
EuclideanDistance::~EuclideanDistance (void) {
}

/**
 * @brief      Calculates the distance using the euclidean distance.
 *
 * @param      startLine   The start line
 * @param[in]  finishLine  The finish line
 *
 * @return     The distance.
 */
float EuclideanDistance::calculateDistance (std::pair<unsigned, unsigned>& startLine, std::pair<unsigned, unsigned>& finishLine) {
    int differenceX = startLine.first - finishLine.first;
    int differenceY = startLine.second - finishLine.second;
    float result = sqrt(pow(differenceX, 2) + pow(differenceY, 2));
    return result;
}
