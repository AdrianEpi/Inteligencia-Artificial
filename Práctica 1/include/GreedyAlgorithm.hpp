/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     GreedyAlgorithm.hpp                                =
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
#include "SearchAlgorithm.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/



/*------------------------------------------------*/

/**
 * @brief      This class describes a search algorithm using a greedy design.
 */
class GreedyAlgorithm : public SearchAlgorithm {

    public:
        // Builder & Destroyer
        GreedyAlgorithm (void);
        virtual ~GreedyAlgorithm (void);

        // Function
        bool runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine);
};