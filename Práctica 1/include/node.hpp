/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     node.hpp                                           =
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
 * @brief      This class describes a node.
 */
class Node {

    private:
        // Attributes
        std::pair<unsigned, unsigned> carPosition_; // The current position of the car
        float distance_;                            // The heuristic distance f(n)
        unsigned parent_;                           // The parent's node position in vector
        unsigned accumulatedDistance_;              // The accumulated distance in node
        bool visited_;                              // If the node has been visited/expanded by the algorithm

    public:
        // Buildes & Destroyer
        Node (void);
        Node (std::pair<unsigned, unsigned> carPosition, float distance, unsigned parent, unsigned accumulatedDistance);
        ~Node (void);

        // Getters &  Setters
        std::pair<unsigned, unsigned> get_CarPosition (void) const;
        float get_Distance (void) const;
        unsigned get_Parent (void) const;
        unsigned get_AccumulatedDistance (void) const;
        bool get_Visited (void) const;

        void set_CarPosition (std::pair<unsigned, unsigned> newCarPosition);
        void set_Distance (float newDistance);
        void set_Parent (unsigned newParent);
        void set_AccumulatedDistance (unsigned newAccumulatedDistance);
        void set_Visited (bool newVisited);
};