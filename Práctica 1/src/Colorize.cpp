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
std::string Colorize::writeGrey (std::string myString) {
	myString = "\033[30m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::writeRed (std::string myString) {
	myString = "\033[31m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::writeGreen (std::string myString) {
	myString = "\033[32m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::writeYellow (std::string myString) {
	myString = "\033[33m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::writeBlue (std::string myString) {
	myString = "\033[34m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::writeMagenta (std::string myString) {
	myString = "\033[35m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::writeCyan (std::string myString) {
	myString = "\033[36m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::writeWhite (std::string myString) {
	myString = "\033[37m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintGrey (std::string myString) {
	myString = "\033[40m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintRed (std::string myString) {
	myString = "\033[41m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintGreen (std::string myString) {
	myString = "\033[42m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintYellow (std::string myString) {
	myString = "\033[43m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintBlue (std::string myString) {
	myString = "\033[44m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintMagenta (std::string myString) {
	myString = "\033[45m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintCyan (std::string myString) {
	myString = "\033[46m" + myString + "\033[00m";
	return myString; 
}
std::string Colorize::paintWhite (std::string myString) {
	myString = "\033[47m" + myString + "\033[00m";
	return myString; 
}