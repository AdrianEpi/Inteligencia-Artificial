/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     EuclideanDistance.cpp                              =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
    =                           Yeixon Morales Gonzalez                            =
    =            Fecha:         05/11/2020                                         =
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
* @Last Modified time: 2020-11-05 14:20:27
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
 * @param      car         The car
 * @param[in]  finishLine  The finish line
 *
 * @return     The distance.
 */
float EuclideanDistance::calculateDistance (Car& car, std::pair<unsigned, unsigned> finishLine) {
    return (sqrt(pow((finishLine.first - car.get_CoordinateX()), 2) + pow((finishLine.second - car.get_CoordinateY()), 2)));
}
