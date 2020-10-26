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
* @Last Modified by:   Yeixon Morales
* @Last Modified time: 2020-10-26 11:40:28
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/game.hpp"

/*------------------------------------------------*/

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

Game::~Game (void) {
}

unsigned Game::get_M (void) const {
	return m_;
}

unsigned Game::get_N (void) const {
	return n_;
}

unsigned Game::get_Obstacles (void) const {
	return obstacles_;
}

std::pair<unsigned, unsigned> Game::get_StartPoint (void) const {
	return startPoint_;
}

std::pair<unsigned, unsigned> Game::get_FinishLine (void) const {
	return finishLine_;
}

Car Game::get_Car (void) const {
	return car_;
}

Map Game::get_Map (void) const {
	return map_;
}

void Game::set_M (unsigned m) {
	m_ = m;
}

void Game::set_N (unsigned n) {
	n_ = n;
}

void Game::set_Obstacles (unsigned obstacles) {
	obstacles_ = obstacles;
}

void Game::set_StartPoint (std::pair<unsigned, unsigned> startPoint) {
	startPoint_ = startPoint;
}

void Game::set_FinishLine (std::pair<unsigned, unsigned> finishLine) {
	finishLine_ = finishLine;
}

void Game::set_Car (Car car) {
	car_ = car;
}

void Game::set_Map (Map map) {
	map_ = map;
}

void Game::generateObstacles (void) {
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

void Game::generateRandomObstacles (void) {

}
