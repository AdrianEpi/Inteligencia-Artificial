/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     game.hpp                                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
    =                           Yeixon Morales Gonzalez                            =
    =            Fecha:         08/10/2020                                         =
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
* @Date:   2020-10-09 17:21:53
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-28 08:38:18
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/game.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Game::Game (void) {
	unsigned input;
	std::cout << std::endl << "Introduce the number of rows: ";
	std::cin >> input;
	set_M(input);

	std::cout << std::endl << "Introduce the number of columns: ";
	std::cin >> input;
	set_N(input);

	std::cout << std::endl << "Introduce the start X position: ";
	std::cin >> input;
	startPoint_.first = input;
	std::cout << std::endl << "Introduce the start Y position: ";
	std::cin >> input;
	startPoint_.second = input;

	std::cout << std::endl << "Introduce the finish X position: ";
	std::cin >> input;
	finishLine_.first = input;
	std::cout << std::endl << "Introduce the finish Y position: ";
	std::cin >> input;
	finishLine_.second = input;

	std::cout << std::endl << "Introduce the number of obstacles: ";
	std::cin >> input;
	set_Obstacles(input);

	map_.initialize(get_M(), get_N());
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  m           The rows
 * @param[in]  n           The columns
 * @param[in]  startPoint  The start point
 * @param[in]  finishLine  The finish line
 * @param[in]  obstacles   The obstacles
 */
Game::Game (unsigned m, unsigned n, std::pair<unsigned, unsigned> startPoint, std::pair<unsigned, unsigned> finishLine, unsigned obstacles) {
	assert(m > 0 && n > 0);
	set_M(m);
	set_N(n);
	startPoint_.first = startPoint.first;
	startPoint_.second = startPoint.second;
	finishLine_.first = finishLine.first;
	finishLine_.second = finishLine.second;
	obstacles = obstacles;
	map_.initialize(get_M(), get_N());
}

/**
 * @brief      Destroys the object.
 */
Game::~Game (void) {
}

/**
 * @brief      Gets the m.
 *
 * @return     The m.
 */
unsigned Game::get_M (void) const {
	return m_;
}

/**
 * @brief      Gets the n.
 *
 * @return     The n.
 */
unsigned Game::get_N (void) const {
	return n_;
}

/**
 * @brief      Gets the obstacles.
 *
 * @return     The obstacles.
 */
unsigned Game::get_Obstacles (void) const {
	return obstacles_;
}

/**
 * @brief      Gets the start point.
 *
 * @return     The start point.
 */
std::pair<unsigned, unsigned> Game::get_StartPoint (void) const {
	return startPoint_;
}

/**
 * @brief      Gets the finish line.
 *
 * @return     The finish line.
 */
std::pair<unsigned, unsigned> Game::get_FinishLine (void) const {
	return finishLine_;
}

/**
 * @brief      Gets the car.
 *
 * @return     The car.
 */
Car Game::get_Car (void) const {
	return car_;
}

/**
 * @brief      Gets the map.
 *
 * @return     The map.
 */
Map Game::get_Map (void) const {
	return map_;
}

/**
 * @brief      Sets the m.
 *
 * @param[in]  m     The new value
 */
void Game::set_M (unsigned m) {
	m_ = m;
}

/**
 * @brief      Sets the n.
 *
 * @param[in]  n     The new value
 */
void Game::set_N (unsigned n) {
	n_ = n;
}

/**
 * @brief      Sets the obstacles.
 *
 * @param[in]  obstacles  The obstacles
 */
void Game::set_Obstacles (unsigned obstacles) {
	obstacles_ = obstacles;
}

/**
 * @brief      Sets the start point.
 *
 * @param[in]  startPoint  The start point
 */
void Game::set_StartPoint (std::pair<unsigned, unsigned> startPoint) {
	startPoint_ = startPoint;
}

/**
 * @brief      Sets the finish line.
 *
 * @param[in]  finishLine  The finish line
 */
void Game::set_FinishLine (std::pair<unsigned, unsigned> finishLine) {
	finishLine_ = finishLine;
}

/**
 * @brief      Sets the car.
 *
 * @param[in]  car   The new value
 */
void Game::set_Car (Car car) {
	car_ = car;
}

/**
 * @brief      Sets the map.
 *
 * @param[in]  map   The new value
 */
void Game::set_Map (Map map) {
	map_ = map;
}

/**
 * @brief      Generate obstacles on the given positions
 */
void Game::generateManualObstacles (void) {
	for (int i = 0; i < get_Obstacles(); i++) {
		bool validObstacle = false;
		while (!validObstacle) {
			unsigned tmpX, tmpY;
			std::cout << get_Obstacles() - i << " remaining obstacles, introduce the x coordinate: ";
			std::cin >> tmpX;
			std::cout << get_Obstacles() - i << " remaining obstacles, introduce the y coordinate: ";
			std::cin >> tmpY;
			validObstacle = map_.addObstacle(tmpX, tmpY);
		}
	}
}

/**
 * @brief      Generate any ammount of random obstacles that is less than the 95% of the map size
 *
 * @param[in]  ammount  The ammount
 */
void Game::generateRandomObstacles (unsigned ammount) {
	assert(ammount <= (0.95 * (map_.get_Rows() - 2) * (map_.get_Columns() - 2)));
	int counter = 0;
	bool validObstacle = false;
	while (counter < ammount) {
		unsigned tmpX = (1 + rand() % (map_.get_Rows() - 2));
		unsigned tmpY = (1 + rand() % (map_.get_Columns() - 2));
		validObstacle = map_.addObstacle(tmpX, tmpY);
		if (validObstacle) {
			counter++;
			validObstacle = false;
		}
	}
}
