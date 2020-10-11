/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     sensor.hpp                                         =
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

/*------------------------------------------------*/

/**
 * @brief      This class describes a sensor. A sensor must know if the adjacent directions are empty (0) or not (1)
 */
class Sensor {

    private:
        // Attributes
        unsigned n_;     // North direction
        unsigned s_;     // South direction
        unsigned e_;     // East direction
        unsigned w_;     // West direction

    public:
        // Builders & Destroyer
        Sensor (void);
        Sensor (unsigned n, unsigned s, unsigned e, unsigned w);
        ~Sensor (void);

        // Getters & Setters
        unsigned get_North (void) const;
        unsigned get_South (void) const;
        unsigned get_East (void) const;
        unsigned get_West (void) const;

        void set_North (unsigned n);
        void set_South (unsigned s);
        void set_East (unsigned e);
        void set_West (unsigned w);

};