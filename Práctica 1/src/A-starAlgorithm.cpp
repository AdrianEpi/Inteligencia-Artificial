/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     A-starAlgorithm.cpp                                =
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
* @Last Modified time: 2020-11-14 08:55:14
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/A-starAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
AStarAlgorithm::AStarAlgorithm (void) {
    set_SolutionPosition(0);
}

/**
 * @brief      Destroys the object.
 */
AStarAlgorithm::~AStarAlgorithm (void) {
}

/**
 * @brief      Executes an A* algorithm to find the solution to the problem.
 *
 * @param[in]  map         The map
 * @param[in]  car         The car
 * @param      heuristic   The heuristic function
 * @param      finishLine  The finish line
 *
 * @return     True if there's solution, false otherwise
 */
bool AStarAlgorithm::runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine) {
    // Generate the root of the tree 
    set_Map(map);
    std::pair<unsigned, unsigned> start;
    start.first = car.get_CoordinateX();
    start.second = car.get_CoordinateY();
    Node root(start, heuristic -> calculateDistance(start, finishLine), 0, 0);
    tree_.push_back(root);
    bool finished = false;
    // Look if the finish line rounded by obstacles
    if ((map_.get_Map()[finishLine.first + 1][finishLine.second] == 1) && (map_.get_Map()[finishLine.first - 1][finishLine.second] == 1) && (map_.get_Map()[finishLine.first][finishLine.second + 1] == 1) && (map_.get_Map()[finishLine.first][finishLine.second - 1] == 1)) {
        return false;
    }
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
            expandLeaf(car, heuristic, true, nodeToExpand, finishLine);
        }
    }
    return false;
}
