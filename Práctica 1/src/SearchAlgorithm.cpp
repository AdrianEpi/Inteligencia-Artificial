/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     SearchAlgorithm.cpp                                =
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
* @Last Modified time: 2020-11-05 22:11:32
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/SearchAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
SearchAlgorithm::SearchAlgorithm (void) {
}

/**
 * @brief      Destroys the object.
 */
SearchAlgorithm::~SearchAlgorithm (void) {
}

/**
 * @brief      Gets the tree.
 *
 * @return     The tree.
 */
std::vector<std::pair<Map, float>> SearchAlgorithm::get_Tree (void) const {
	return tree_;
}

/**
 * @brief      Gets the solution.
 *
 * @return     The solution.
 */
std::pair<Map, float> SearchAlgorithm::get_Solution (void) const {
	return solution_;
}

/**
 * @brief      Sets the tree.
 *
 * @param[in]  newTree  The new tree
 */
void SearchAlgorithm::set_Tree (std::vector<std::pair<Map, float>> newTree) {
	tree_ = newTree;
}

/**
 * @brief      Sets the solution.
 *
 * @param[in]  newSolution  The new solution
 */
void SearchAlgorithm::set_Solution (std::pair<Map, float> newSolution) {
	solution_ = newSolution;
}

/**
 * @brief      Runs the search algorithm
 *
 * @param[in]  map        The map
 * @param[in]  car        The car
 * @param      heuristic  The heuristic
 */
void SearchAlgorithm::runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine) {
}

/**
 * @brief      Expands the leaf.
 *
 * @param[in]  map   The map
 * @param[in]  car   The car
 *
 * @return     True if it can be expanded, false otherwise
 */
bool SearchAlgorithm::expandLeaf (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine) {
	bool expanded = false;
	Car newCar;
	if ((map.get_Map()[car.get_CoordinateX()][car.get_CoordinateY() + 1] == 0) && ((car.get_CoordinateY() + 1) != map.get_Rows())) {
		expanded = true;
		std::pair<Map, float> leaf;
		leaf.first = map;
		leaf.first.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		leaf.first.changeBox(car.get_CoordinateX(), car.get_CoordinateY() + 1, 5);
		newCar.set_CoordinateX(car.get_CoordinateX());
		newCar.set_CoordinateY(car.get_CoordinateY() + 1);
		std::pair<unsigned, unsigned> carPosition;
		carPosition.first = car.get_CoordinateX();
		carPosition.second = car.get_CoordinateY() + 1;
		leaf.first.set_CarPosition(carPosition);
		leaf.second = heuristic -> calculateDistance(newCar, finishLine);
		tree_.push_back(leaf);
	}
	/*if ((map.get_Map()[car.get_CoordinateX()][car.get_CoordinateY() - 1] == 0) && ((car.get_CoordinateY() + 1) != 0)) {
		expanded = true;
		std::pair<Map, float> leaf;
		leaf.first = map;
		leaf.first.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		leaf.first.changeBox(car.get_CoordinateX(), car.get_CoordinateY() - 1, 5);
		newCar.set_CoordinateX(car.get_CoordinateX());
		newCar.set_CoordinateY(car.get_CoordinateY() - 1);
		std::pair<unsigned, unsigned> carPosition;
		carPosition.first = car.get_CoordinateX();
		carPosition.second = car.get_CoordinateY() - 1;
		leaf.first.set_CarPosition(carPosition);
		leaf.second = heuristic -> calculateDistance(newCar, finishLine);
		tree_.push_back(leaf);
	}
	if ((map.get_Map()[car.get_CoordinateX() + 1][car.get_CoordinateY()] == 0) && ((car.get_CoordinateX() + 1) != map.get_Columns())) {
		expanded = true;
		std::pair<Map, float> leaf;
		leaf.first = map;
		leaf.first.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		leaf.first.changeBox(car.get_CoordinateX() + 1, car.get_CoordinateY(), 5);
		newCar.set_CoordinateX(car.get_CoordinateX() + 1);
		newCar.set_CoordinateY(car.get_CoordinateY());
		std::pair<unsigned, unsigned> carPosition;
		carPosition.first = car.get_CoordinateX() + 1;
		carPosition.second = car.get_CoordinateY();
		leaf.first.set_CarPosition(carPosition);
		leaf.second = heuristic -> calculateDistance(newCar, finishLine);
		tree_.push_back(leaf);
	}
	if ((map.get_Map()[car.get_CoordinateX() - 1][car.get_CoordinateY()] == 0) && ((car.get_CoordinateX() + 1) != 0)) {
		expanded = true;
		std::pair<Map, float> leaf;
		leaf.first = map;
		leaf.first.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		leaf.first.changeBox(car.get_CoordinateX() - 1, car.get_CoordinateY(), 5);
		newCar.set_CoordinateX(car.get_CoordinateX() - 1);
		newCar.set_CoordinateY(car.get_CoordinateY());
		std::pair<unsigned, unsigned> carPosition;
		carPosition.first = car.get_CoordinateX() - 1;
		carPosition.second = car.get_CoordinateY();
		leaf.first.set_CarPosition(carPosition);
		leaf.second = heuristic -> calculateDistance(newCar, finishLine);
		tree_.push_back(leaf);
	}*/
	return expanded;
}

/**
 * @brief      Finds the node with lowest distance to finishLine f(n).
 *
 * @return     The position in the vector of the node.
 */
int SearchAlgorithm::lowestDistance (void) {
	int pos = 0;
	float distance = MAXDISTANCE;
	for (int i = 0; i < tree_.size(); i++) {
		if (tree_[i].second < distance) {
			distance = tree_[i].second;
			pos = i;
		}
	}
	return pos;
}
