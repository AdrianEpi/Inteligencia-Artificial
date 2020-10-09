/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     car.cpp                                            =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         08/10/2020                                         =
    =            Subject:       Inteligencia Artificial                            =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Adrian Epifanio
* @Date:   2020-10-09 15:50:33
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-09 15:59:45
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/car.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Car::Car () {
	updatePosition(1, 1);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  x     The coordinate X
 * @param[in]  y     The coordinate Y
 */
Car::Car (unsigned x, unsigned y) {
	updatePosition(x, y);
}

/**
 * @brief      Destroys the object.
 */
Car::~Car () {
}

/**
 * @brief      Gets the coordinate x.
 *
 * @return     The coordinate x.
 */
unsigned Car::get_CoordinateX (void) const {
	return coordinateX_;
}

/**
 * @brief      Gets the coordinate y.
 *
 * @return     The coordinate y.
 */
unsigned Car::get_CoordinateY (void) const {
	return coordinateY_;
}

/**
 * @brief      Sets the coordinate x.
 *
 * @param[in]  x     The new value
 */
void Car::set_CoordinateX (unsigned x) {
	coordinateX_ = x;
}

/**
 * @brief      Sets the coordinate y.
 *
 * @param[in]  y     The new value
 */
void Car::set_CoordinateY (unsigned y) {
	coordinateY_ = y;
}

/**
 * @brief      Updates the car position in map.
 *
 * @param[in]  x     The coordinate X
 * @param[in]  y     The coordinate Y
 */
void Car::updatePosition (unsigned x, unsigned y) {
	assert(x >= 1 && y >= 1);
	set_CoordinateX(x);
	set_CoordinateY(y);
}

/**
 * @brief      Prints a car position.
 *
 * @param      os    The output stream
 *
 * @return     The output stream.
 */
std::ostream& Car::printCarPosition (std::ostream& os) const {
	os << "The car position  is: (" << get_CoordinateX() << "," << get_CoordinateY() << ")." << std::endl;
}

