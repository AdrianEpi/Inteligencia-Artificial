/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     SearchAlgorithm.hpp                                =
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
#include "map.hpp"
#include "EuclideanDistance.hpp"
#include "ManhattanDistance.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <vector>

/*------------------------------------------------*/

/**
 * @brief      This class describes a search algorithm.
 */
class SearchAlgorithm {

    protected:
        // Attributes
        std::vector<std::pair<Map, float>> tree_;   // Vector with the map and the evaluation function in that moment
        std::pair<Map, float> solution_;            // The solution of the algorithm

    public:
        // Builder & Destroyer
        SearchAlgorithm (void);
        virtual ~SearchAlgorithm (void);

        // Getters & Setters
        std::vector<std::pair<Map, float>> get_Tree (void) const;
        std::pair<Map, float> get_Solution (void) const;

        void set_Tree (std::vector<std::pair<Map, float>> newTree);
        void set_Solution (std::pair<Map, float> newSolution);

        // Functions
        virtual void runAlgorithm (Map map, Car car, HeuristicFunction& heuristic, std::pair<unsigned, unsigned>& finishLine);
        bool expandLeaf (Map map, Car car, HeuristicFunction& heuristic, std::pair<unsigned, unsigned>& finishLine);
};