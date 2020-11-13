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
* @Last Modified time: 2020-11-13 23:47:31
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
std::vector<Node> SearchAlgorithm::get_Tree (void) const {
	return tree_;
}

/**
 * @brief      Gets the map.
 *
 * @return     The map.
 */
Map SearchAlgorithm::get_Map (void) const {
	return map_;
}

/**
 * @brief      Gets the solution position.
 *
 * @return     The solution position.
 */
unsigned SearchAlgorithm::get_SolutionPosition (void) const {
	return solutionPosition_;
}

/**
 * @brief      Gets the closed list.
 *
 * @return     The closed list.
 */
std::vector<unsigned> SearchAlgorithm::get_ClosedList (void) const {
	return closedList_;
}

/**
 * @brief      Sets the tree.
 *
 * @param[in]  newTree  The new tree
 */
void SearchAlgorithm::set_Tree (std::vector<Node> newTree) {
	tree_ = newTree;
}

/**
 * @brief      Sets the solution position.
 *
 * @param[in]  newPos  The new position
 */
void SearchAlgorithm::set_SolutionPosition (unsigned newPos) {
	solutionPosition_ = newPos;
}

/**
 * @brief      Sets the map.
 *
 * @param[in]  newMap  The new map
 */
void SearchAlgorithm::set_Map (Map newMap) {
	map_ = newMap;
}

/**
 * @brief      Sets the closed list.
 *
 * @param[in]  newClosedList  The new closed list
 */
void SearchAlgorithm::set_ClosedList (std::vector<unsigned> newClosedList) {
	closedList_ = newClosedList;
}

/**
 * @brief      Runs the search algorithm
 *
 * @param[in]  map        The map
 * @param[in]  car        The car
 * @param      heuristic  The heuristic
 *
 * @return     True if there's solution, false otherwise
 */
bool SearchAlgorithm::runAlgorithm (Map map, Car car, HeuristicFunction* heuristic, std::pair<unsigned, unsigned>& finishLine) {
}

/**
 * @brief      Expands the leaf.
 *
 * @param[in]  car        The car
 * @param      heuristic  The heuristic
 * @param[in]  isAStar    Indicates if a star
 * @param[in]  node       The node 
 *
 */
void SearchAlgorithm::expandLeaf (Car car, HeuristicFunction* heuristic, bool isAStar, unsigned node, std::pair<unsigned, unsigned>& finishLine) {
	Car newCar;
	car.updateSensor(map_.get_Map()[car.get_CoordinateX()][car.get_CoordinateY() - 1], map_.get_Map()[car.get_CoordinateX()][car.get_CoordinateY() + 1], map_.get_Map()[car.get_CoordinateX() + 1][car.get_CoordinateY()], map_.get_Map()[car.get_CoordinateX() - 1][car.get_CoordinateY()]);
	std::pair<unsigned, unsigned> carPosition;
	if (((car.get_Sensor().get_South() == 0) || (car.get_Sensor().get_South() == 4)) && ((car.get_CoordinateY() + 1) != map_.get_Rows())) {
		carPosition.first = car.get_CoordinateX();
		carPosition.second = car.get_CoordinateY() + 1;
		map_.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		float distance = heuristic -> calculateDistance(carPosition, finishLine);
		if (isAStar) {
			distance += tree_[node].get_AccumulatedDistance();
		}
		Node newNode (carPosition, distance, node, tree_[node].get_AccumulatedDistance() + 1);
		tree_.push_back(newNode);
	}
	if (((car.get_Sensor().get_North() == 0) || (car.get_Sensor().get_North() == 4)) && ((car.get_CoordinateY() + 1) != 0)) {
		carPosition.first = car.get_CoordinateX();
		carPosition.second = car.get_CoordinateY() - 1;
		map_.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		float distance = heuristic -> calculateDistance(carPosition, finishLine);
		if (isAStar) {
			distance += tree_[node].get_AccumulatedDistance();
		}
		Node newNode (carPosition, distance, node, tree_[node].get_AccumulatedDistance() + 1);
		tree_.push_back(newNode);
	}
	if (((car.get_Sensor().get_East() == 0) || (car.get_Sensor().get_East() == 4)) && ((car.get_CoordinateX() + 1) != map_.get_Columns())) {
		carPosition.first = car.get_CoordinateX() + 1;
		carPosition.second = car.get_CoordinateY();
		map_.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		float distance = heuristic -> calculateDistance(carPosition, finishLine);
		if (isAStar) {
			distance += tree_[node].get_AccumulatedDistance();
		}
		Node newNode (carPosition, distance, node, tree_[node].get_AccumulatedDistance() + 1);
		tree_.push_back(newNode);
	}
	if (((car.get_Sensor().get_West() == 0) || (car.get_Sensor().get_West() == 4)) && ((car.get_CoordinateX() + 1) != 0)) {
		carPosition.first = car.get_CoordinateX() - 1;
		carPosition.second = car.get_CoordinateY();
		map_.changeBox(car.get_CoordinateX(), car.get_CoordinateY(), 2);
		float distance = heuristic -> calculateDistance(carPosition, finishLine);
		if (isAStar) {
			distance += tree_[node].get_AccumulatedDistance();
		}
		Node newNode (carPosition, distance, node, tree_[node].get_AccumulatedDistance() + 1);
		tree_.push_back(newNode);
	}
	tree_[node].set_Visited(true);
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
		if (tree_[i].get_Distance() <= distance && tree_[i].get_Visited() == false) {
			distance = tree_[i].get_Distance();
			pos = i;
		}
	}
	return pos;
}

/**
 * @brief      Shows the trace step by step.
 *
 * @param[in]  map   The map
 */
void SearchAlgorithm::showTrace (Map map) {
	std::vector<int> trace;
	int pos = solutionPosition_;
	while (pos != 0) {
		pos = tree_[pos].get_Parent();
		trace.push_back(pos);
	}
	int time = 10000000 / trace.size();
	for (int i = trace.size() - 1; i >= 0; i--) {
		system("clear");
		map.changeBox(tree_[trace[i]].get_CarPosition().first, tree_[trace[i]].get_CarPosition().second, 2);
		map.printMap(std::cout);
		usleep(time);
	}
}

/**
 * @brief      Saves the solution.
 *
 * @param      solution  The solution
 */
void SearchAlgorithm::saveSolution (Map& solution) {
	int i = solutionPosition_;
	while (i != 0) {
		i = tree_[i].get_Parent();
		solution.changeBox(tree_[i].get_CarPosition().first, tree_[i].get_CarPosition().second, 2);
	}
}

/**
 * @brief      Generates the closed list of the tree
 */
void SearchAlgorithm::generateClosedList (void) {
	for (int i = 0; i < tree_.size(); i++) {
		if (tree_[i].get_Visited() == true) {
			closedList_.push_back(i);
		}
	}
}