/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     HeuristicFunction.hpp                              =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 
#include "car.hpp"
#define MAXDISTANCE 999999999

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cassert>
#include <iostream>

/*------------------------------------------------*/

/**
 * @brief      This class describes an heuristic function.
 */
class HeuristicFunction {
    
    private:
        // Attributes
        float distance_;    // The heuristic distance

    public:
        // Builder & Destroyer
        HeuristicFunction (void);
        virtual ~HeuristicFunction (void);

        // Getter & Setter
        float get_Distance (void) const;

        void set_Distance (float newDistance);

        // Functions
        virtual float calculateDistance (std::pair<unsigned, unsigned>& startLine, std::pair<unsigned, unsigned>& finishLine);
};