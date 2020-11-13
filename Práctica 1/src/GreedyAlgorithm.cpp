/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     GreedyAlgorithm.cpp                                =
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
* @Last Modified time: 2020-11-13 18:32:40
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/GreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
GreedyAlgorithm::GreedyAlgorithm (void) {
    set_SolutionPosition(0);
}

/**
 * @brief      Destroys the object.
 */
GreedyAlgorithm::~GreedyAlgorithm (void) {
}

/**
 * @brief      Executes a greedy algorithm to find the solution to the problem.
 *
 * @param[in]  map         The map
 * @param[in]  car         The car
 * @param      heuristic   The heuristic
 * @param      finishLine  The finish line
 *
 * @return     True if there's solution, false otherwise
 */
bool GreedyAlgorithm::runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine) {
    // Generate the root of the tree 
    set_Map(map);
    std::pair<unsigned, unsigned> start;
    start.first = car.get_CoordinateX();
    start.second = car.get_CoordinateY();
    Node root(start, heuristic -> calculateDistance(start, finishLine), 0, 0);
    tree_.push_back(root);
    bool finished = false;
    while (!finished) {
        
        int nodeToExpand = lowestDistance();  
        car.set_CoordinateX(tree_[nodeToExpand].get_CarPosition().first);
        car.set_CoordinateY(tree_[nodeToExpand].get_CarPosition().second);

        if ((car.get_CoordinateX() == finishLine.first) && (car.get_CoordinateY() == finishLine.second)) {
            solutionPosition_ = nodeToExpand;
            return true;
        }
        else if (tree_[nodeToExpand].get_Visited()) {
            break;
        }
        else {
            expandLeaf(car, heuristic, false, nodeToExpand, finishLine);
        }
    }
    if (finished == false) {
        return false;
    }
}
