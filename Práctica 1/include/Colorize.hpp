/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     Colorize.hpp                                       =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>

/*------------------------------------------------*/
class Colorize {
	public:
		Colorize (void);
		~Colorize (void);

		std::string writeGrey (std::string myString);
        std::string writeRed (std::string myString);
        std::string writeGreen (std::string myString);
        std::string writeYellow (std::string myString);
        std::string writeBlue (std::string myString);
        std::string writeMagenta (std::string myString);
        std::string writeCyan (std::string myString);
        std::string writeWhite (std::string myString);
        std::string paintGrey (std::string myString);
        std::string paintRed (std::string myString);
        std::string paintGreen (std::string myString);
        std::string paintYellow (std::string myString);
        std::string paintBlue (std::string myString);
        std::string paintMagenta (std::string myString);
        std::string paintCyan (std::string myString);
        std::string paintWhite (std::string myString);
};