/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     game.hpp                                           =
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
* @Date:   2020-10-09 17:21:53
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-13 18:22:17
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/game.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Game::Game (void) {
	selectHeuristicFunction(2);
	selectAlgorithm(2);
	set_Obstacles(0);
}

/**
 * @brief      Constructs a new instance from the data read by file.
 *
 * @param[in]  inputFile  The input file
 */
Game::Game (std::string inputFile) {
	readFile(inputFile);
}

/**
 * @brief      Destroys the object.
 */
Game::~Game (void) {
}

/**
 * @brief      Gets the m.
 *
 * @return     The m.
 */
unsigned Game::get_M (void) const {
	return m_;
}

/**
 * @brief      Gets the n.
 *
 * @return     The n.
 */
unsigned Game::get_N (void) const {
	return n_;
}

/**
 * @brief      Gets the obstacles.
 *
 * @return     The obstacles.
 */
unsigned Game::get_Obstacles (void) const {
	return obstacles_;
}

/**
 * @brief      Gets the start point.
 *
 * @return     The start point.
 */
std::pair<unsigned, unsigned> Game::get_StartPoint (void) const {
	return startPoint_;
}

/**
 * @brief      Gets the finish line.
 *
 * @return     The finish line.
 */
std::pair<unsigned, unsigned> Game::get_FinishLine (void) const {
	return finishLine_;
}

/**
 * @brief      Gets the car.
 *
 * @return     The car.
 */
Car Game::get_Car (void) const {
	return car_;
}

/**
 * @brief      Gets the map.
 *
 * @return     The map.
 */
Map Game::get_Map (void) const {
	return map_;
}

/**
 * @brief      Gets the solution.
 *
 * @return     The solution.
 */
Map Game::get_Solution (void) const {
	return solution_;
}

/**
 * @brief      Gets the heuristic function.
 *
 * @return     The heuristic function.
 */
HeuristicFunction* Game::get_HeuristicFunction (void) const {
	return heuristicFunction_;
}

/**
 * @brief      Gets the search algorithm.
 *
 * @return     The search algorithm.
 */
SearchAlgorithm* Game::get_SearchAlgorithm (void) const {
	return algorithm_;
}

/**
 * @brief      Sets the m.
 *
 * @param[in]  m     The new value
 */
void Game::set_M (unsigned m) {
	m_ = m;
}

/**
 * @brief      Sets the n.
 *
 * @param[in]  n     The new value
 */
void Game::set_N (unsigned n) {
	n_ = n;
}

/**
 * @brief      Sets the obstacles.
 *
 * @param[in]  obstacles  The obstacles
 */
void Game::set_Obstacles (unsigned obstacles) {
	obstacles_ = obstacles;
}

/**
 * @brief      Sets the start point.
 *
 * @param[in]  startPoint  The start point
 */
void Game::set_StartPoint (std::pair<unsigned, unsigned> startPoint) {
	startPoint_ = startPoint;
}

/**
 * @brief      Sets the finish line.
 *
 * @param[in]  finishLine  The finish line
 */
void Game::set_FinishLine (std::pair<unsigned, unsigned> finishLine) {
	finishLine_ = finishLine;
}

/**
 * @brief      Sets the car.
 *
 * @param[in]  car   The new value
 */
void Game::set_Car (Car car) {
	car_ = car;
}

/**
 * @brief      Sets the map.
 *
 * @param[in]  map   The new value
 */
void Game::set_Map (Map map) {
	map_ = map;
}

/**
 * @brief      Sets the solution.
 *
 * @param[in]  map   The new value
 */
void Game::set_Solution (Map map) {
	solution_ = map;
}

/**
 * @brief      Gets the heuristic function.
 *
 * @param      newHeuristicFunction  The new heuristic function
 */
void Game::get_HeuristicFunction (HeuristicFunction* newHeuristicFunction) {
	heuristicFunction_ = newHeuristicFunction;
}

/**
 * @brief      Gets the search algorithm.
 *
 * @param      newSearchAlgorithm  The new search algorithm
 */
void Game::get_SearchAlgorithm (SearchAlgorithm* newSearchAlgorithm) {
	algorithm_ = newSearchAlgorithm;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newGame  The new game
 *
 * @return     The result of the assignment
 */
Game& Game::operator= (const Game& newGame) {
	set_M(newGame.get_M());
	set_N(newGame.get_N());
	set_Obstacles(newGame.get_Obstacles());
	set_StartPoint(newGame.get_StartPoint());
	set_FinishLine(newGame.get_FinishLine());
	set_Car(newGame.get_Car());
	set_Map(newGame.get_Map());
	return *this;
}

/**
 * @brief      Selects the heuristic function that is going to use the program
 *
 * @param[in]  selector  The selector
 */
void Game::selectHeuristicFunction (int selector) {
	switch(selector) {
		case 0:
			break;
		case 1:
			heuristicFunction_ = new EuclideanDistance();
			break;

		case 2: 
			heuristicFunction_ = new ManhattanDistance();
			break;

		default:
			std::cout << std::endl << "Sorry, that heuristic function does not exist." << std::endl;
			exit(1);
			break;
	}
}

/**
 * @brief      Selects the search algorithm that is going to run the program.
 *
 * @param[in]  selector  The selector
 */
void Game::selectAlgorithm (int selector) {
	switch(selector) {
		case 0:
			break;
		case 1:
			algorithmSelector_ = 1;
			algorithm_ = new AStarAlgorithm();
			break;

		case 2: 
			algorithmSelector_ = 2;
			algorithm_ = new GreedyAlgorithm();
			break;

		default:
			std::cout << std::endl << "Sorry, that algorithm does not exist." << std::endl;
			exit(1);
			break;
	}
}

/**
 * @brief      Method for introducing the game parametres by keyboard.
 */
void Game::manualData (void) {
	unsigned input;
	std::cout << std::endl << "Introduce the number of rows: ";
	std::cin >> input;
	set_M(input);
	std::cout << std::endl << "Introduce the number of columns: ";
	std::cin >> input;
	set_N(input);
	std::cout << std::endl << "Introduce the start X position: ";
	std::cin >> input;
	startPoint_.first = input;
	std::cout << std::endl << "Introduce the start Y position: ";
	std::cin >> input;
	startPoint_.second = input;
	std::cout << std::endl << "Introduce the finish X position: ";
	std::cin >> input;
	finishLine_.first = input;
	std::cout << std::endl << "Introduce the finish Y position: ";
	std::cin >> input;
	finishLine_.second = input;
	map_.initialize(get_M(), get_N());
	map_.addStartPoint(startPoint_.first, startPoint_.second);
	map_.addFinishLine(finishLine_.first, finishLine_.second);
}

/**
 * @brief      Generate obstacles on the given positions
 *
 * @param[in]  ammount  The ammount
 */
void Game::generateManualObstacles (unsigned ammount) {
	if ((get_Obstacles() + ammount) <= (0.95 * (map_.get_Rows() - 2) * (map_.get_Columns() - 2))) {
		for (int i = 0; i < ammount; i++) {
			bool validObstacle = false;
			while (!validObstacle) {
				unsigned tmpX, tmpY;
				std::cout << ammount - i << " remaining obstacles, introduce the x coordinate: ";
				std::cin >> tmpX;
				std::cout << ammount - i << " remaining obstacles, introduce the y coordinate: ";
				std::cin >> tmpY;
				validObstacle = map_.addObstacle(tmpX, tmpY);
				if (!validObstacle) {
					std::cout << std::endl << "Sorry that position is already used";
				}
			}
		}
		set_Obstacles(get_Obstacles() + ammount);
	}
	else {
		std::cout << std::endl << "Sorry too many obstacles in map right now";
	}
}

/**
 * @brief      Generate any ammount of random obstacles that is less than the 95% of the map size
 *
 * @param[in]  ammount  The ammount
 */
void Game::generateRandomObstacles (unsigned ammount) {
	assert((get_Obstacles() +ammount) <= ((map_.get_Rows() - 2) * (map_.get_Columns() - 2)));
	int counter = 0;
	bool validObstacle = false;
	while (counter < ammount) {
		unsigned tmpX = (1 + rand() % (map_.get_Rows() - 2));
		unsigned tmpY = (1 + rand() % (map_.get_Columns() - 2));
		validObstacle = map_.addObstacle(tmpX, tmpY);
		if (validObstacle) {
			counter++;
			validObstacle = false;
		}
	}
	set_Obstacles(get_Obstacles() + ammount);
}

/**
 * @brief      Stores the data readen by the readFile method. It has one mode for each
 *             type of data. 0 -> Map size, 1 -> Start point, 2 -> finish line,
 *             3 -> obstacles ammount, 4 -> each obstacle position
 *
 * @param[in]  data  The data
 * @param[in]  mode  The mode
 */
void Game::dataSaver (std::string& data, int mode) {
	std::string tmp = "";
	bool firstData = true;
	int aux = 0, aux2 = 0, counter = 0;
	while (counter <= data.length()) {
		if ((data[counter] != ' ') && (data[counter] != '\n') && (data[counter] != '\0')) {
			tmp += data[counter];
		}
		else {
			aux = std::atoi(tmp.c_str());
			switch (mode) {
				case 0: // Map size
					if (firstData) {
						set_M(aux);
					}
					else {
						set_N(aux);
					}
					break;

				case 1: // Start point
					if (firstData) {
						startPoint_.first = aux;
					}
					else {
						startPoint_.second = aux;
					}
					break;

				case 2: // Finish line
					if (firstData) {
						finishLine_.first = aux;
					}
					else {
						finishLine_.second = aux;
					}
					break;

				case 3: // Obstacles ammount
					set_Obstacles(aux);
					break;	

				case 4: // Obstacles position
					if (firstData) {
						aux2 = aux;
					}
					else {
						map_.addObstacle(aux2, aux);
					}
					break;

				default:
					std::cout << std::endl << "Error on data saver" << std::endl;
					exit(1);
					break;
			}
			if (firstData) {
				firstData = false;
			}
			tmp = "";
		}
		counter++;
	}
}

/**
 * @brief      Finds the solution running the selected algorithm.
 */
void Game::findSolution (void) {
	selectAlgorithm(algorithmSelector_);
	car_.set_CoordinateX(startPoint_.first);
	car_.set_CoordinateY(startPoint_.second);
	map_.set_CarPosition(startPoint_);
	Chrono temporizer;
	temporizer.startChrono();
	if (algorithm_ -> runAlgorithm(get_Map(), get_Car(), get_HeuristicFunction(), finishLine_) == false) {
		temporizer.stopChrono();
		std::cout << std::endl << "There's no possible way for the car to reach the finish line" << std::endl;
	}
	else {
		temporizer.stopChrono();
		solution_ = algorithm_ -> get_Map();
		//solution_ = algorithm_ -> get_Tree()[algorithm_ -> get_SolutionPosition()].first;
		solution_.changeBox(startPoint_.first, startPoint_.second, 3);
	}	
	std::cout << std::endl << "CPU Time: " << temporizer.get_Seconds(5) << " seconds." << std::endl;
}

/**
 * @brief      Reads a the data from a file.
 *
 * @param[in]  inputFile  The input file
 */
void Game::readFile (std::string& inputFile) {
	std::ifstream file(inputFile, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, file not found." << std::endl;
		exit(1);
	}
	else {
		std::string line = "";
		// Map size
		getline(file, line);
		dataSaver(line, 0);
		// Start point
		getline(file, line);
		dataSaver(line, 1);
		// Finish line
		getline(file, line);
		dataSaver(line, 2);
		// Obstacles ammount
		getline(file, line);
		dataSaver(line, 3);

		map_.initialize(get_M(), get_N());
		map_.addStartPoint(startPoint_.first, startPoint_.second);
		map_.addFinishLine(finishLine_.first, finishLine_.second);
		// Each obstacle position
		for (int i = 0; i < get_Obstacles(); i++) {
			getline(file, line);
			dataSaver(line, 4);
		}
	}
	file.close();
}

/**
 * @brief      Saves game data into a file for being able to load that game later.
 *
 * @param      os    The output stream
 *
 * @return     The output stream
 */
std::ostream& Game::saveData (std::ostream& os) const {
	os << get_M() << " " << get_N() << std::endl;
	os << get_StartPoint().first << " " << get_StartPoint().second << std::endl;
	os << get_FinishLine().first << " " << get_FinishLine().second << std::endl;
	os << get_Obstacles() << std::endl;
	for (int i = 1; i < map_.get_Rows() - 1; i++) {
		for (int j = 1; j < map_.get_Columns() - 1; j++) {
			if (map_.get_Map()[i][j] == 1) {
				os << i << " " << j << std::endl;
			}
		}
	}
	return os;
}
