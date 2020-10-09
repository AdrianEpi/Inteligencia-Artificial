/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     map.cpp                                            =
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
/*
* @Author: Adrian Epifanio
* @Date:   2020-10-08 16:43:42
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-09 19:44:44
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
	// We initilize the map as map.size() - 3 because size is always 1 more than real size,
	// the other 2 units to reach 3 is because the initialize function creates the map 2 rows 
	// and 2 columns bigger than the real size for making the sensor count right.
	if ((map.size() != get_Rows() + 1) || (map[0].size() != get_Columns() + 1)) {
		initialize(map.size() - 3, map[0].size() - 3);
	}
	for (int i = 0; i <= get_Rows(); i++) {
		for (int j = 0; j <= get_Columns(); j++) {
			map_[i][j] = map[i][j];
		}
	}
}

/**
 * @brief      Initializes the map with all the positions empty (0)
 *
 * @param[in]  x     The rows
 * @param[in]  y     The columns
 */
void Map::initialize (unsigned x, unsigned y) {
	assert(x > 0 && y > 0);
	set_Rows(x + 2);
	set_Columns(y + 2);
	map_.resize(get_Rows() + 1);
	for (int i = 0; i <= get_Rows(); i++) {
		map_[i].resize(get_Columns() + 1);
	}
	for (int i = 0; i <= get_Rows(); i++) {
		for (int j = 0; j <= get_Columns(); j++) {
			if (i == 0 || j == 0 || i == get_Rows() || j == get_Columns()) {
				map_[i][j] = 1;
			}
			else {
				map_[i][j] = 0;
			}
		}
	}
}

/**
 * @brief      Adds an obstacle on the given coordinates.
 *
 * @param[in]  x     The coordinate x.
 * @param[in]  y     The coordinate y.
 *
 * @return     True if introduced correctly, false otherwhise.
 */
bool Map::addObstacle (unsigned x, unsigned y) {
	assert(x >= 1 && y >= 1);
	if (map_[x][y] == 0) {
		map_[x][y] = 1;
	}
	else {
		std::cout << std::endl << "Sorry, that place is already used.";
	}
	
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
	os << std::endl << "Map size " << map_.size() - 3 << "x" << map_[0].size() - 3 << std::endl << "\t";
	for (int i = 0; i <= get_Rows(); i++) {
		for (int j = 0; j <= get_Columns(); j++) {
			switch (map_[i][j]) {
				case 0:
					os << "  | ";
					break;

				case 1:
					os << "# | ";
					break;

				case 2:
					os << "X | ";
					break;

				case 3:
					os << "S | ";
					break;

				case 4:
					os << "F | ";
					break;

				default:
					std::cout << "ERROR";
					break;
			}
		}
		os << std::endl << "\t";
	}
}