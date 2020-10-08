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
* @Last Modified time: 2020-10-08 17:44:17
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/map.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Map::Map () {
	set_Rows(0);
	set_Columns(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  n     The rows
 * @param[in]  m     The columns
 */
Map::Map (unsigned n, unsigned m) {
	initialize(n, m);
}

/**
 * @brief      Destroys the object.
 */
Map::~Map () {
}

/**
 * @brief      Gets the rows.
 *
 * @return     The rows.
 */
unsigned Map::get_Rows (void) const {
	return n_;
}

/**
 * @brief      Gets the columns.
 *
 * @return     The columns.
 */
unsigned Map::get_Columns (void) const {
	return m_;
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
 * @param[in]  n     The new value
 */
void Map::set_Rows (unsigned n) {
	n_ = n;
}

/**
 * @brief      Sets the columns.
 *
 * @param[in]  m     The new value
 */
void Map::set_Columns (unsigned m) {
	m_ = m;
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
 * @param[in]  n     The rows
 * @param[in]  m     The columns
 */
void Map::initialize (unsigned n, unsigned m) {
	assert(n > 0 && m > 0);
	set_Rows(n + 2);
	set_Columns(m + 2);
	map_.resize(get_Rows() + 1);
	for (int i = 0; i <= get_Rows(); i++) {
		map_[i].resize(get_Columns() + 1);
	}
	for (int i = 0; i <= get_Rows(); i++) {
		for (int j = 0; j <= get_Columns(); j++) {
			map_[i][j] = 0;
		}
	}
}

/**
 * @brief      Prints the map.
 *
 * @param      os  The output stream
 *
 * @return     The output stream
 */
std::ostream& Map::printMap (std::ostream& os) const {
	os << std::endl << "Map size " << map_.size() - 3 << "x" << map_[0].size() - 3 << std::endl << "\t| ";
	for (int i = 1; i < get_Rows() - 1; i++) {
		for (int j = 1; j < get_Columns() - 1; j++) {
			os << map_[i][j] << " | ";
		}
		os << std::endl;
		if (i < get_Rows() - 2) {
			os << "\t| ";
		}
	}
}
