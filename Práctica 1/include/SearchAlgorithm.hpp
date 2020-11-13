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
#include "node.hpp"

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
        std::vector<Node> tree_;
        unsigned solutionPosition_;                             // The position of the solution in vector
        Map map_;

    public:
        // Builder & Destroyer
        SearchAlgorithm (void);
        virtual ~SearchAlgorithm (void);

        // Getters & Setters
        std::vector<Node> get_Tree (void) const;
        unsigned get_SolutionPosition (void) const;
        Map get_Map (void) const;

        void set_Tree (std::vector<Node> newTree);
        void set_SolutionPosition (unsigned newSolutionPosition);
        void set_Map (Map map);

        // Functions
        virtual bool runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine);
        void expandLeaf (Car car, HeuristicFunction* heuristic, bool isAStar, unsigned node, std::pair<unsigned, unsigned>& finishLine);
        int lowestDistance (void);
};

