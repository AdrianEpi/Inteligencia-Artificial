/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     map.hpp                                            =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cassert>
#include <iostream>
#include <vector>

/*------------------------------------------------*/

/**
 * @brief      This class describes the map where the car is going to move, an empty position is stored as "0", an obstacle as "1" and a position in which the car has been "2".
 */
class Map {

    private:
        // Attributes
        unsigned n_;    // The rows
        unsigned m_;    // The columns
        std::vector<std::vector<unsigned>> map_;  // The map of the game

    public:
        // Builders & Destroyer
        Map ();
        Map (unsigned n, unsigned m);
        ~Map ();

        // Getters & Setters
        unsigned get_Rows (void) const;
        unsigned get_Columns (void) const;
        std::vector<std::vector<unsigned>> get_Map (void) const;

        void set_Rows (unsigned n);
        void set_Columns (unsigned m);
        void set_Map (std::vector<std::vector<unsigned>> map);

        // Functions
        void initialize (unsigned n, unsigned m);

        // Write
        std::ostream& printMap (std::ostream& os) const;

};