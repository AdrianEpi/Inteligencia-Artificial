/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     node.cpp                                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =                           Luciano Sekulic Gregoris                           =
    =                           Yeixon Morales Gonzalez                            =
    =            Date:          05/11/2020                                         =
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
/*
* @Author: Adrian Epifanio
* 		   Luciano Sekulic 
* 		   Yeixon Morales 
* @Date:   2020-10-09 15:50:33
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-14 09:00:40
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/node.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Node::Node (void) {
    set_Visited(false);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  carPosition          The car position
 * @param[in]  distance             The distance
 * @param[in]  parent               The parent
 * @param[in]  accumulatedDistance  The accumulated distance
 */
Node::Node (std::pair<unsigned, unsigned> carPosition, float distance, unsigned parent, unsigned accumulatedDistance) {
    set_CarPosition(carPosition);
    set_Distance(distance);
    set_Parent(parent);
    set_AccumulatedDistance(accumulatedDistance);
    set_Visited(false);
}

/**
 * @brief      Destroys the object.
 */
Node::~Node (void) {
}

/**
 * @brief      Gets the car position.
 *
 * @return     The car position.
 */
std::pair<unsigned, unsigned> Node::get_CarPosition (void) const {
    return carPosition_;
}

/**
 * @brief      Gets the distance.
 *
 * @return     The distance.
 */
float Node::get_Distance (void) const {
    return distance_;
}

/**
 * @brief      Gets the parent.
 *
 * @return     The parent.
 */
unsigned Node::get_Parent (void) const {
    return parent_;
}

/**
 * @brief      Gets the accumulated distance.
 *
 * @return     The accumulated distance.
 */
unsigned Node::get_AccumulatedDistance (void) const {
    return accumulatedDistance_;
}

/**
 * @brief      Gets the visited.
 *
 * @return     The visited.
 */
bool Node::get_Visited (void) const {
    return visited_;
}

/**
 * @brief      Sets the car position.
 *
 * @param[in]  newCarPosition  The new car position
 */
void Node::set_CarPosition (std::pair<unsigned, unsigned> newCarPosition) {
    carPosition_ = newCarPosition;
}

/**
 * @brief      Sets the distance.
 *
 * @param[in]  newDistance  The new distance
 */
void Node::set_Distance (float newDistance) {
    distance_ = newDistance;
}

/**
 * @brief      Sets the parent.
 *
 * @param[in]  newParent  The new parent
 */
void Node::set_Parent (unsigned newParent) {
    parent_ = newParent;
}

/**
 * @brief      Sets the accumulated distance.
 *
 * @param[in]  newAccumulatedDistance  The new accumulated distance
 */
void Node::set_AccumulatedDistance (unsigned newAccumulatedDistance) {
    accumulatedDistance_ = newAccumulatedDistance;
}

/**
 * @brief      Sets the visited.
 *
 * @param[in]  newVisited  Indicates if new visited
 */
void Node::set_Visited (bool newVisited) {
    visited_ = newVisited;
}	
