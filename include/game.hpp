/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     game.hpp                                           =
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
#include "../include/map.hpp"
#include "../include/car.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cassert>
#include <iostream>

/*------------------------------------------------*/

class Game {

    private:
        // Attributes
        unsigned m_;                                // Rows
        unsigned n_;                                // Columns
        unsigned obstacles_;                        // The obstacles ammount
        std::pair<unsigned, unsigned> startPoint_;  // The coordinates of the start point
        std::pair<unsigned, unsigned> finishLine_;  // The coordinates of the finish line
        Car car_;                                   // The car object
        Map map_;                                   // The game map

    public:
        //Builders & Destroyer
        Game (void);
        Game (unsigned m, unsigned n, std::pair<unsigned, unsigned> startPoint, std::pair<unsigned, unsigned> finishLine, unsigned obstacles);
        ~Game (void);

        // Getters & Setters
        unsigned get_M (void) const;
        unsigned get_N (void) const;
        unsigned get_Obstacles (void) const;
        std::pair<unsigned, unsigned> get_StartPoint (void) const;
        std::pair<unsigned, unsigned> get_FinishLine (void) const;
        Car get_Car (void) const;
        Map get_Map (void) const;

        void set_M (unsigned m);
        void set_N (unsigned n);
        void set_Obstacles (unsigned obstacles);
        void set_StartPoint (std::pair<unsigned, unsigned> startPoint);
        void set_FinishLine (std::pair<unsigned, unsigned> finishLine);
        void set_Car (Car car);
        void set_Map (Map map);

        // Fuctions
        void generateObstacles (void);
        void generateRandomObstacles (void);



}; 