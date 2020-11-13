/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     ManhattanDistance.hpp                              =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 
#include "HeuristicFunction.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cmath>

/*------------------------------------------------*/

/**
 * @brief      This class describes the manhattan distance.
 */
class ManhattanDistance : public HeuristicFunction {

    public:
        // Builder & Destroyer
        ManhattanDistance (void);
        virtual ~ManhattanDistance (void);

        // Function
        float calculateDistance (std::pair<unsigned, unsigned>& startLine, std::pair<unsigned, unsigned>& finishLine);
};