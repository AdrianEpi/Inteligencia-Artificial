/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Práctica 1. Estrategias de Búsqueda                =
	=            File name:     main.cpp                                           =
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
/*
* @Author: Adrian Epifanio
* 		   Luciano Sekulic 
* 		   Yeixon Morales 
* @Date:   2020-10-08 11:04:26
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-14 09:35:42
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/game.hpp"
#include "../include/Colorize.hpp"

/*------------------------------------------------*/

void menu (Game& myGame);
bool selector (Game& myGame, unsigned sentinel, bool& generatedGame);

/**
 * @brief      Main function of the program, creates the game and calls the menu.
 *
 * @return     0 If program finishes correctly
 */
int main (void) {
	srand(time(NULL));	// For generating random numbers
	Game myGame;
	menu(myGame);
	return 0;
}	

/**
 * @brief      Prints the menu on screen and ask de user to select an option
 *
 * @param      myGame  The game
 */
void menu (Game& myGame) {
	bool finishGame = false;
	unsigned selection = 0;
	bool generatedGame = false;
	while (!finishGame) {
		std::cout << std::endl << "\t=====   Welcome to the \"Minimum Route Calculator For An Autonomous Car\" simulator.   =====" << std::endl;
		std::cout << std::endl << "\t 1. Introduce the game specs by keyboard.";
		std::cout << std::endl << "\t 2. Load a data file.";
		std::cout << std::endl << "\t 3. Generate random obstacles";
		std::cout << std::endl << "\t 4. Introduce obstacles by keyboard";
		std::cout << std::endl << "\t 5. Print map on screen.";
		std::cout << std::endl << "\t 6. Print solution on screen.";
		std::cout << std::endl << "\t 7. Save solution to file";
		std::cout << std::endl << "\t 8. Save data to file for using it again";
		std::cout << std::endl << "\t 9. Generate Solution";
		std::cout << std::endl << "\t 10. Show trace";
		std::cout << std::endl << "\t 11. Choose heuristic function";
		std::cout << std::endl << "\t 12. Choose search algorithm";
		std::cout << std::endl << "\t 13. Use openList solution";
		std::cout << std::endl << "\t 0. Exit" << std::endl;
		std::cin >> selection;
		finishGame = selector(myGame, selection, generatedGame);
	}
	exit(0);
}

/**
 * @brief      Runs the functions selected on the menu
 *
 * @param      myGame         The game
 * @param[in]  sentinel       The user's selection
 * @param      generatedGame  If the map has been generated or not
 *
 * @return     True if program finishes, false otherwise
 */
bool selector (Game& myGame, unsigned sentinel, bool& generatedGame) {
	system("clear");
	std::string auxString = "";
	unsigned auxUnsigned;
	if (sentinel == 0) {
		std::cout << std::endl << "Program finished correctly." << std::endl;
		return true;
	}
	else if (sentinel == 1) {
		Game newGame;
		myGame = newGame;
		myGame.manualData();
		generatedGame = true;
	}
	else if (sentinel == 2) {
		std::cout << std::endl << "Please enter the file name: ";
		std::cin >> auxString;
		Game newGame(auxString);
		myGame = newGame;
		generatedGame = true;
	}
	else if (sentinel == 7 && generatedGame) {
		std::cout << std::endl << "Please enter the output file name: ";
		std::cin >> auxString;
		std::ofstream os(auxString);
		myGame.get_Solution().saveMap(os);
	}
	else if (sentinel == 8 && generatedGame) {
		std::cout << std::endl << "Please enter the output file name: ";
		std::cin >> auxString;
		std::ofstream os(auxString);
		myGame.saveData(os);
	}
	else if (generatedGame) {
		switch (sentinel) {
			case 3:
				std::cout << std::endl << "Please enter the ammount of obstacles: ";
				std::cin >> auxUnsigned;
				myGame.generateRandomObstacles(auxUnsigned);
				break;

			case 4:
				std::cout << std::endl << "Please enter the ammount of obstacles: ";
				std::cin >> auxUnsigned;
				myGame.generateManualObstacles(auxUnsigned);
				break;

			case 5:
				myGame.get_Map().printMap(std::cout);
				break;

			case 6:
				myGame.get_Solution().printMap(std::cout);
				break;

			case 9:
				myGame.findSolution();
				break;

			case 10:
				myGame.get_SearchAlgorithm() -> showTrace(myGame.get_Map());
				break;

			case 11:
				std::cout << std::endl << "Please select the heuristic function you want to run";
				std::cout << std::endl << "1. Euclidean distance";
				std::cout << std::endl << "2. Manhattan distance";
				std::cout << std::endl << "0. Cancel\n";
				std::cin >> sentinel;
				myGame.selectHeuristicFunction(sentinel);
				break;

			case 12:
				std::cout << std::endl << "Please select the search algorithm you want to run";
				std::cout << std::endl << "1. A-Star algorithm";
				std::cout << std::endl << "2. Greedy algorithm";
				std::cout << std::endl << "0. Cancel\n";
				std::cin >> sentinel;
				myGame.selectAlgorithm(sentinel);
				break;

			case 13:
				myGame.updateToOpenList();
				break;

			default:
				std::cout << std::endl << "Not valid option" << std::endl;
				break;
		}
	}
	else {
		std::cout << std::endl << "Sorry, map has not been generated yet";
	}
	return false;
}