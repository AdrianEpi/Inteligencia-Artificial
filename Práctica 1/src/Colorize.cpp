/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     Colorize.cpp                                       =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
    =                           Yeixon Morales Gonzalez                            =
    =            Fecha:         27/10/2020                                         =
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
* @Date:   2020-10-27 21:31:27
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-27 22:05:21
*/
#include "../include/Colorize.hpp"


/**
 * @brief      Constructs a new instance.
 */
Colorize::Colorize (void) {
}

/**
 * @brief      Destroys the object.
 */
Colorize::~Colorize (void) {
}

/**
 * @brief      Writes a red.
 *
 * @param[in]  myString  My string
 *
 * @return     The text written in red
 */
std::string Colorize::writeRed (std::string myString) {
	myString = "\033[31m" + myString + "\033[00m";
	return myString; 
}