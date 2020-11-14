/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     game.hpp                                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
    =                           Yeixon Morales Gonzalez                            =
    =            Date:          08/10/2020                                         =
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
#include "map.hpp"
#include "car.hpp"
#include "A-starAlgorithm.hpp"
#include "GreedyAlgorithm.hpp"
#include "Chrono.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <cstring>

/*------------------------------------------------*/

/**
 * @brief      This class describes the game of the calculation of the minimum
 *             route for an autonomous car.
 */
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
        Map solution_;                              // The solution    
        HeuristicFunction* heuristicFunction_;      // The heuristic function that is going to be used
        SearchAlgorithm* algorithm_;                // The algorithm thats going to follow the car
        unsigned algorithmSelector_;                // The selected algorithm for being able to reset it

    public:
        //Builders & Destroyer
        Game (void);
        Game (std::string);
        ~Game (void);

        // Getters & Setters
        unsigned get_M (void) const;
        unsigned get_N (void) const;
        unsigned get_Obstacles (void) const;
        std::pair<unsigned, unsigned> get_StartPoint (void) const;
        std::pair<unsigned, unsigned> get_FinishLine (void) const;
        Car get_Car (void) const;
        Map get_Map (void) const;
        Map get_Solution (void) const;
        HeuristicFunction* get_HeuristicFunction (void) const;
        SearchAlgorithm* get_SearchAlgorithm (void) const;
        unsigned get_AlgorithmSelector (void) const;

        void set_M (unsigned m);
        void set_N (unsigned n);
        void set_Obstacles (unsigned obstacles);
        void set_StartPoint (std::pair<unsigned, unsigned> startPoint);
        void set_FinishLine (std::pair<unsigned, unsigned> finishLine);
        void set_Car (Car car);
        void set_Map (Map map);
        void set_Solution (Map map);
        void set_HeuristicFunction (HeuristicFunction* newHeuristicFunction);
        void set_SearchAlgorithm (SearchAlgorithm* newSearchAlgorithm);
        void set_AlgorithmSelector (unsigned newSelector);

        // Operators Overload
        Game& operator= (const Game& newGame);

        // Fuctions
        void selectHeuristicFunction (int selector);
        void selectAlgorithm (int selector);
        void manualData (void);
        void generateManualObstacles (unsigned ammount);
        void generateRandomObstacles (unsigned ammount);
        void dataSaver (std::string& data, int mode);
        void findSolution (void);
        void updateToOpenList (void);

        // Read
        void readFile (std::string& file);
        std::ostream& saveData (std::ostream& os) const;
}; 