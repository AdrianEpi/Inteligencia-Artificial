/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     sensor.cpp                                         =
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
* @Date:   2020-10-08 10:47:15
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-14 09:03:45
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/sensor.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Sensor::Sensor (void) {
	set_North(0);
	set_South(0);
	set_East(0);
	set_West(0);
}

/**
 * @brief      Constructs a new instance. Values must be 0 if empty, 1 otherwhise.
 *
 * @param[in]  n     The new value
 * @param[in]  s     The new value
 * @param[in]  e     The new value
 * @param[in]  w     The new value
 */
Sensor::Sensor (unsigned n, unsigned s, unsigned e, unsigned w) {
	set_North(n);
	set_South(s);
	set_East(e);
	set_West(w);
}

/**
 * @brief      Destroys the object.
 */
Sensor::~Sensor (void) {
}

/**
 * @brief      Gets the north.
 *
 * @return     The north.
 */
unsigned Sensor::get_North (void) const {
	return n_;
}

/**
 * @brief      Gets the south.
 *
 * @return     The south.
 */
unsigned Sensor::get_South (void) const {
	return s_;
}

/**
 * @brief      Gets the east.
 *
 * @return     The east.
 */
unsigned Sensor::get_East (void) const {
	return e_;
}

/**
 * @brief      Gets the west.
 *
 * @return     The west.
 */
unsigned Sensor::get_West (void) const {
	return w_;
}

/**
 * @brief      Sets the north.
 *
 * @param[in]  n     The new value. Value must be 0 if empty, 1 otherwhise.
 *
 */
void Sensor::set_North (unsigned n) {
	assert((n >= 0) && (n <= 4));
	n_ = n;
}

/**
 * @brief      Sets the south.
 *
 * @param[in]  s     The new value. Value must be 0 if empty, 1 otherwhise.
 */
void Sensor::set_South (unsigned s) {
	assert((s >= 0) && (s <= 4));
	s_ = s;
}

/**
 * @brief      Sets the east.
 *
 * @param[in]  e     The new value. Value must be 0 if empty, 1 otherwhise.
 */
void Sensor::set_East (unsigned e) {
	assert((e >= 0) && (e <= 4));
	e_ = e;
}

/**
 * @brief      Sets the west.
 *
 * @param[in]  w     The new value. Value must be 0 if empty, 1 otherwhise.
 */
void Sensor::set_West (unsigned w) {
	assert((w >= 0) && (w <= 4));
	w_ = w;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newSensor  The new sensor
 *
 * @return     The result of the assignment
 */
Sensor& Sensor::operator= (const Sensor& newSensor) {
	this -> set_North(newSensor.get_North());
	this -> set_South(newSensor.get_South());
	this -> set_East(newSensor.get_East());
	this -> set_West(newSensor.get_West());
	return *this;
}