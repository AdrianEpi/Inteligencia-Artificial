/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     car.cpp                                            =
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
* @Date:   2020-10-09 15:50:33
* @Last Modified by:   Yeixon Morales
* @Last Modified time: 2020-10-26 11:40:28
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/car.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Car::Car (void) {
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
Car::~Car (void) {
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
 * @brief      Gets the sensor.
 *
 * @return     The sensor.
 */
Sensor Car::get_Sensor (void) const {
	return sensor_;
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
 * @brief      Sets the sensor.
 *
 * @param[in]  newSensor  The new sensor
 */
void Car::set_Sensor (Sensor newSensor) {
	sensor_ = newSensor;
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
 * @brief      Updates the existing sensor with new values. Values must be 0 if empty, 1 otherwhise.
 *
 * @param[in]  n     The north position
 * @param[in]  s     The south position
 * @param[in]  e     The east position
 * @param[in]  w     The west position
 */
void Car::updateSensor (unsigned n, unsigned s, unsigned e, unsigned w) {
	sensor_.set_North(n);
	sensor_.set_South(s);
	sensor_.set_East(e);
	sensor_.set_West(w);
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

