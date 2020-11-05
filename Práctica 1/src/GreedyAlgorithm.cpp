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
* @Last Modified time: 2020-11-05 22:33:52
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/GreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
GreedyAlgorithm::GreedyAlgorithm (void) {
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
 */
void GreedyAlgorithm::runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine) {
    // Generate the root of the tree 
    std::pair<Map, float> root;
    root.first = map;
    root.second = heuristic -> calculateDistance(car, finishLine);
    tree_.push_back(root);
    bool finished = false;    
    while (!finished) {
        std::cout << std::endl << "entra" << std::endl;
        int nodeToExpand = lowestDistance();
        std::cout << std::endl << "LLEGA 1" << std::endl;
        if (tree_[nodeToExpand].second == MAXDISTANCE) {
            break;
        }
        map = tree_[nodeToExpand].first;
        std::cout << std::endl << "LLEGA2" << std::endl;
        car.set_CoordinateX(map.get_CarPosition().first);
        car.set_CoordinateY(map.get_CarPosition().second);
        std::cout << std::endl << "LLEGA3" << std::endl;
        if ((car.get_CoordinateX() == finishLine.first) && (car.get_CoordinateY() == finishLine.second)) {
            std::cout << std::endl << "CON SOLUCION" << std::endl;
            solution_ = tree_[nodeToExpand];
            finished = true;
        }
        else {
            std::cout << std::endl << "LLEGA4" << std::endl;
            expandLeaf(map, car, heuristic, finishLine);
            std::cout << std::endl << "LLEGA5" << std::endl;
            tree_[nodeToExpand].second = MAXDISTANCE; 
            std::cout << std::endl << "LLEGA6" << std::endl;
        }
        std::cout << std::endl << "LLEGA" << std::endl;
    }
    if (finished == false) {
        std::cout << std::endl << "SINSOLUTION" << std::endl;
        solution_.second = MAXDISTANCE;
    }
}
