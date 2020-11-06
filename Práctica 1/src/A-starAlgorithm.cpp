/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     A-starAlgorithm.cpp                                =
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
* @Last Modified time: 2020-11-06 17:22:58
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/A-starAlgorithm.hpp"

/*------------------------------------------------*/
/**
 * @brief      Constructs a new instance.
 */
AStarAlgorithm::AStarAlgorithm (void) {
    std::pair<unsigned, bool> rootParent;
    rootParent.first = 0;
    rootParent.second = false;
    parentBranch_.push_back(rootParent);
    accumulatedDistance_.push_back(0);
}

/**
 * @brief      Destroys the object.
 */
AStarAlgorithm::~AStarAlgorithm (void) {
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
bool AStarAlgorithm::runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine) {
    // Generate the root of the tree 
    std::pair<Map, float> root;
    root.first = map;
    root.second = heuristic -> calculateDistance(car, finishLine);
    tree_.push_back(root);
    bool finished = false;    
    while (!finished) {
        int nodeToExpand = lowestDistance();        
        map = tree_[nodeToExpand].first;
        car.set_CoordinateX(tree_[nodeToExpand].first.get_CarPosition().first);
        car.set_CoordinateY(tree_[nodeToExpand].first.get_CarPosition().second);
        if ((car.get_CoordinateX() == finishLine.first) && (car.get_CoordinateY() == finishLine.second)) {
            if (tree_[solutionPosition_].second <= tree_[nodeToExpand].second) {
                break;
            }
            solutionPosition_ = nodeToExpand;
            parentBranch_[nodeToExpand].second = true;

        }
        else if (nodeToExpand == 0 && parentBranch_[nodeToExpand].second == true) {
            break;
        }
        else {
            expandLeaf(tree_[nodeToExpand].first, car, heuristic, finishLine, nodeToExpand, true);
            parentBranch_[nodeToExpand].second = true; 
            tree_[nodeToExpand].first.printMap(std::cout);
        }
    }
    if (finished == false) {
        return false;
    }
    return true;
}
