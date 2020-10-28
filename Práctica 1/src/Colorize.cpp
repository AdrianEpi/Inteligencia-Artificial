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
* @Last Modified time: 2020-10-28 07:30:07
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/Colorize.hpp"

/*------------------------------------------------*/


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
 * @brief      Writes the given text with grey color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeGrey (std::string myString) {
	return ("\033[30m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with red color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeRed (std::string myString) {
	return ("\033[31m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with green color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeGreen (std::string myString) {
	return ("\033[32m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text inn color yellow.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeYellow (std::string myString) {
	return ("\033[33m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with blue color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeBlue (std::string myString) {
	return ("\033[34m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with magenta color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeMagenta (std::string myString) {
	return ("\033[35m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with cyan color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeCyan (std::string myString) {
	return ("\033[36m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with white color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the color.
 */
std::string Colorize::writeWhite (std::string myString) {
	return ("\033[37m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a grey background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintGrey (std::string myString) {
	return ("\033[40m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a red background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintRed (std::string myString) {
	return ("\033[41m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a green background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintGreen (std::string myString) {
	return ("\033[42m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a yellow background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintYellow (std::string myString) {
	return ("\033[43m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a blue background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintBlue (std::string myString) {
	return ("\033[44m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a magenta background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintMagenta (std::string myString) {
	return ("\033[45m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a cyan background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintCyan (std::string myString) {
	return ("\033[46m" + myString + "\033[00m");
}

/**
 * @brief      Writes the given text with a white background color.
 *
 * @param[in]  myString  My string
 *
 * @return     The string written with the background color.
 */
std::string Colorize::paintWhite (std::string myString) {
	return ("\033[47m" + myString + "\033[00m");
}