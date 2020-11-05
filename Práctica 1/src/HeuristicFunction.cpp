/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     HeuristicFunction.cpp                              =
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
* @Last Modified time: 2020-11-05 14:17:38
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/HeuristicFunction.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
HeuristicFunction::HeuristicFunction (void) {
    set_Distance(MAXDISTANCE);
}

/**
 * @brief      Destroys the object.
 */
HeuristicFunction::~HeuristicFunction (void) {
}

/**
 * @brief      Gets the distance.
 *
 * @return     The distance.
 */
float HeuristicFunction::get_Distance (void) const {
    return distance_;
}

/**
 * @brief      Sets the distance.
 *
 * @param[in]  newDistance  The new distance
 */
void HeuristicFunction::set_Distance (float newDistance) {
    distance_ = newDistance;
}

/**
 * @brief      Calculates the distance.
 *
 * @param      car         The car
 * @param[in]  finishLine  The finish line
 *
 * @return     The distance.
 */
float HeuristicFunction::calculateDistance (Car& car, std::pair<unsigned, unsigned> finishLine) {
    return get_Distance();
}

