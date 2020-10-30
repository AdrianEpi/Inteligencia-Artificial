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


/**
 * @brief      This class describes a colorizer.
 */
class Colorize {

	public:
        // Builder & Destroyer
		Colorize (void);
		~Colorize (void);

		// Text color functions
		std::string writeGrey (const std::string& myString);
        std::string writeRed (const std::string& myString);
        std::string writeGreen (const std::string& myString);
        std::string writeYellow (const std::string& myString);
        std::string writeBlue (const std::string& myString);
        std::string writeMagenta (const std::string& myString);
        std::string writeCyan (const std::string& myString);
        std::string writeWhite (const std::string& myString);

        // Background color functions
        std::string paintGrey (const std::string& myString);
        std::string paintRed (const std::string& myString);
        std::string paintGreen (const std::string& myString);
        std::string paintYellow (const std::string& myString);
        std::string paintBlue (const std::string& myString);
        std::string paintMagenta (const std::string& myString);
        std::string paintCyan (const std::string& myString);
        std::string paintWhite (const std::string& myString);
};