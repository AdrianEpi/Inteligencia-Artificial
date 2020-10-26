/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     map.hpp                                            =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cassert>
#include <iostream>
#include <vector>

/*------------------------------------------------*/

/**
 * @brief      This class describes the map where the car is going to move, an empty position 
 *             is stored as "0", an obstacle as "1" and a position in which the car has been "2".
 *             Also "3" will be used as the start position and "4" as the finish line.
 */
class Map {

    private:
        // Attributes
        unsigned x_;    // The rows
        unsigned y_;    // The columns
        std::vector<std::vector<unsigned>> map_;  // The map of the game

    public:
        // Builders & Destroyer
        Map (void);
        Map (unsigned x, unsigned y);
        ~Map (void);

        // Getters & Setters
        unsigned get_Rows (void) const;
        unsigned get_Columns (void) const;
        std::vector<std::vector<unsigned>> get_Map (void) const;

        void set_Rows (unsigned x);
        void set_Columns (unsigned y);
        void set_Map (std::vector<std::vector<unsigned>> map);

        // Functions
        void initialize (unsigned x, unsigned y);
        bool addObstacle (unsigned x, unsigned y);

        // Write
        std::ostream& printMap (std::ostream& os) const;

};