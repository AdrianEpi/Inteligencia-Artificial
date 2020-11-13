/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     map.cpp                                            =
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
/*
* @Author: Adrian Epifanio
* 		   Luciano Sekulic 
* 		   Yeixon Morales 
* @Date:   2020-10-08 16:43:42
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-13 23:11:01
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/map.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Map::Map (void) {
	set_Rows(0);
	set_Columns(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  x     The rows
 * @param[in]  y     The columns
 */
Map::Map (unsigned x, unsigned y) {
	initialize(x, y);
}

/**
 * @brief      Destroys the object.
 */
Map::~Map (void) {
}

/**
 * @brief      Gets the rows.
 *
 * @return     The rows.
 */
unsigned Map::get_Rows (void) const {
	return x_;
}

/**
 * @brief      Gets the columns.
 *
 * @return     The columns.
 */
unsigned Map::get_Columns (void) const {
	return y_;
}

/**
 * @brief      Gets the map.
 *
 * @return     The map.
 */
std::vector<std::vector<unsigned>> Map::get_Map (void) const {
	return map_;
}

/**
 * @brief      Sets the rows.
 *
 * @param[in]  x     The new value
 */
void Map::set_Rows (unsigned x) {
	x_ = x;
}

/**
 * @brief      Sets the columns.
 *
 * @param[in]  y     The new value
 */
void Map::set_Columns (unsigned y) {
	y_ = y;
}

/**
 * @brief      Sets the map.
 *
 * @param[in]  map   The new value
 */
void Map::set_Map (std::vector<std::vector<unsigned>> map) {
	map_ = map;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newMap  The new map
 *
 * @return     The result of the assignment
 */
Map& Map::operator= (const Map& newMap) {
	this->set_Rows(newMap.get_Rows());
	this->set_Columns(newMap.get_Columns());
	this->set_Map(newMap.get_Map());
	return *this;
}

/**
 * @brief      Initializes the map with all the positions empty (0)
 *
 * @param[in]  x     The rows
 * @param[in]  y     The columns
 */
void Map::initialize (unsigned x, unsigned y) {
	assert((x > 0) && (y > 0));
	set_Rows(x + 2);
	set_Columns(y + 2);
	map_.resize(get_Rows() + 1);
	for (int i = 0; i <= get_Rows(); i++) {
		map_[i].resize(get_Columns() + 1);
	}
	for (int i = 0; i < get_Rows(); i++) {
		for (int j = 0; j < get_Columns(); j++) {
			if (i == 0 || j == 0 || i == get_Rows() - 1 || j == get_Columns() - 1) {
				map_[i][j] = 1;
			}
			else {
				map_[i][j] = 0;
			}
		}
	}
}

/**
 * @brief      Adds an obstacle at the given coordinates.
 *
 * @param[in]  x     The coordinate x.
 * @param[in]  y     The coordinate y.
 *
 * @return     True if introduced correctly, false otherwhise.
 */
bool Map::addObstacle (unsigned x, unsigned y) {
	assert((x >= 1) && (y >= 1) && (x < get_Rows()) && (y < get_Columns()));
	if (map_[x][y] == 0) {
		map_[x][y] = 1;
		return true;
	}
	else {
		return false;
	}
	
}

/**
 * @brief      Adds the start point at the given coordinates.
 *
 * @param[in]  x     The coordinate x.
 * @param[in]  y     The coordinate y.
 */
void Map::addStartPoint (unsigned x, unsigned y) {
	assert((x >= 1) && (y >= 1) && (x < get_Rows()) && (y < get_Columns()));
	for (int i = 0; i < get_Rows(); i++) {
		for (int j = 0; j < get_Columns(); j++) {
			if (map_[i][j] == 3) {
				map_[i][j] = 0;
				break;
			}
		}
	}
	map_[x][y] = 3;
}

/**
 * @brief      Adds the finish line at the given coordinates.
 *
 * @param[in]  x     The coordinate x.
 * @param[in]  y     The coordinate y.
 */
void Map::addFinishLine (unsigned x, unsigned y) {
	assert((x >= 1) && (y >= 1) && (x < get_Rows()) && (y < get_Columns()));
	for (int i = 0; i < get_Rows(); i++) {
		for (int j = 0; j < get_Columns(); j++) {
			if (map_[i][j] == 4) {
				map_[i][j] = 0;
				break;
			}
		}
	}
	map_[x][y] = 4;
}

/**
 * @brief      Changes the element in that position of the map
 *
 * @param[in]  x        The x coordinate
 * @param[in]  y        The y coordinate
 * @param[in]  element  The element
 */
void Map::changeBox (unsigned x, unsigned y, unsigned element) {
	assert((x >= 1) && (y >= 1) && (x < get_Rows()) && (y < get_Columns()));
	map_[x][y] = element;
}

/**
 * @brief      Calculates the length.
 *
 * @return     The length.
 */
int Map::calculateLength (void) {
	int counter = 0;
	for (int i = 1; i < get_Rows(); i++) {
		for (int j = 1; j < get_Columns(); j++) {
			if (map_[i][j] == 2) {
				counter++;
			}
		}
	}
	return counter;
}

/**
 * @brief      Prints the map. An empty block will be displayed in case theres no obstacle
 *             and the car has not been there. A '#' will be shown in the obstacles positions.
 *             A 'X' will be shown in the places where the car has been. Apart from that 'S' means
 *             the starts position and "F" the finish line.
 *
 * @param      os  The output stream
 *
 * @return     The output stream
 */
std::ostream& Map::printMap (std::ostream& os) const {
	Colorize color;
	os << std::endl << "Map size " << map_.size() - 3 << "x" << map_[0].size() - 3 << std::endl << "\t";
	for (int i = 0; i < get_Rows(); i++) {
		os << color.writeYellow(" | ");
		for (int j = 0; j < get_Columns(); j++) {
			switch (map_[i][j]) {
				case 0:
					os << " ";
					break;

				case 1:
					os << color.writeRed("#");
					break;

				case 2:
					os << "X";
					break;

				case 3:
					os << color.writeMagenta("S");
					break;

				case 4:
					os << color.writeGreen("F");
					break;

				default:
					std::cout << "Error painting the map.";
					exit(1);
					break;
			}
			os << color.writeYellow(" | ");
		}
		os << std::endl << "\t";
	}
	os << std::endl;
	return os;
}

/**
 * @brief      Saves the map to a file. An empty block will be displayed in case theres no obstacle
 *             and the car has not been there. A '#' will be shown in the obstacles positions.
 *             A 'X' will be shown in the places where the car has been. Apart from that 'S' means
 *             the starts position and "F" the finish line.
 *
 * @param      os  The output stream
 *
 * @return     The output stream
 */
std::ostream& Map::saveMap (std::ostream& os) const {
	os << std::endl << "Map size " << map_.size() - 3 << "x" << map_[0].size() - 3 << std::endl << "\t";
	for (int i = 0; i < get_Rows(); i++) {
		os << " | ";
		for (int j = 0; j < get_Columns(); j++) {
			switch (map_[i][j]) {
				case 0:
					os << " ";
					break;

				case 1:
					os << ".";
					break;

				case 2:
					os << "X";
					break;

				case 3:
					os << "S";
					break;

				case 4:
					os << "F";
					break;

				default:
					std::cout << "Error painting the map.";
					exit(1);
					break;
			}
			os << " | ";
		}
		os << std::endl << "\t";
	}
	os << std::endl;
	return os;
}
