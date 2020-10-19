/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     car.hpp                                            =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
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
#include "../include/sensor.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cassert>
#include <iostream>

/*------------------------------------------------*/

/**
 * @brief      This class describes a car. A car has as attributes the position of the car at the current 
 *             moment on the map. Also a car has a sensor who knows whats near the car.
 */
class Car {
    
    private:
        // Attributes
        unsigned coordinateX_;      // The coordinate X of the car
        unsigned coordinateY_;      // The coordinate Y of the car
        Sensor sensor_;             // A sensor with the available movements

    public:
        // Builders & Destroyer
        Car (void);
        Car (unsigned x, unsigned y);
        ~Car (void);

        // Getters & Setters
        unsigned get_CoordinateX (void) const;
        unsigned get_CoordinateY (void) const;
        Sensor get_Sensor (void) const;
 
        void set_CoordinateX (unsigned x);
        void set_CoordinateY (unsigned y);
        void set_Sensor (Sensor newSensor);

        // Functions
        void updatePosition (unsigned x, unsigned y);
        void updateSensor (unsigned n, unsigned s, unsigned e, unsigned w);

        // Write
        std::ostream& printCarPosition (std::ostream& os) const;

};