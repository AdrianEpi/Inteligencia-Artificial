/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     car.hpp                                            =
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

/*------------------------------------------------*/

/**
 * @brief      This class describes a car. A car has as attributes the position of the car at the current moment on the map.
 */
class Car {
    
    private:
        // Attributes
        unsigned coordinateX_;
        unsigned coordinateY_;

    public:
        // Builders & Destroyer
        Car ();
        Car (unsigned x, unsigned y);
        ~Car ();

        // Getters & Setters
        unsigned get_CoordinateX (void) const;
        unsigned get_CoordinateY (void) const;

        void set_CoordinateX (unsigned x);
        void set_CoordinateY (unsigned y);

        // Functions
        void updatePosition (unsigned x, unsigned y);

        // Write
        std::ostream& printCarPosition (std::ostream& os) const;

};