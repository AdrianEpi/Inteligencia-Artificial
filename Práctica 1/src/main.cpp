/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Estrategias de Búsqueda                =
    =            File name:     main.cpp                                           =
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
* @Date:   2020-10-08 11:04:26
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-30 10:54:35
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/game.hpp"
#include "../include/Colorize.hpp"

/*------------------------------------------------*/

void menu (Game& myGame);
bool selector (Game& myGame, unsigned sentinel, bool& generatedGame);

int main (void) {
	srand(time(NULL));	// For generating random numbers
	Game myGame;
	menu(myGame);
}	

/**
 * @brief      Prints the menu on screen
 *
 * @param      myGame  My game
 */
void menu (Game& myGame) {
    bool finishGame = false;
    unsigned selection = 0;
    bool generatedGame = false;
    while (!finishGame) {
        std::cout << std::endl << "\t=====Welcome to the \"Minimum Route Calculator For A Autonomous Car\" simulator. =====" << std::endl;
        std::cout << std::endl << "\t 1. Introduce the game specs by keyboard.";
        std::cout << std::endl << "\t 2. Load a data file.";
        std::cout << std::endl << "\t 3. Generate random obstacles";
        std::cout << std::endl << "\t 4. Introduce obstacles by keyboard";
        std::cout << std::endl << "\t 5. Print map on screen.";
        std::cout << std::endl << "\t 6. Save solution to file";
        std::cout << std::endl << "\t 7. Save data to file for using it again";
        std::cout << std::endl << "\t 8. Generate Solution";
        std::cout << std::endl << "\t 9. Show trace";
        std::cout << std::endl << "\t 0. Exit" << std::endl;
        std::cin >> selection;
        finishGame = selector(myGame, selection, generatedGame);
    }
    exit(0);
}

/**
 * @brief      Runs the functions selected on the menu
 *
 * @param      myGame         My game
 * @param[in]  sentinel       The sentinel
 * @param      generatedGame  The generated game
 *
 * @return     True if program finishes, false otherwise
 */
bool selector (Game& myGame, unsigned sentinel, bool& generatedGame) {
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
    else if (sentinel == 3 && generatedGame) {
        std::cout << std::endl << "Please enter the ammount of obstacles: ";
        std::cin >> auxUnsigned;
        myGame.generateRandomObstacles(auxUnsigned);
    }
    else if (sentinel == 4 && generatedGame) {
        std::cout << std::endl << "Please enter the ammount of obstacles: ";
        std::cin >> auxUnsigned;
        myGame.generateManualObstacles(auxUnsigned);
    }       
    else if (sentinel == 5 && generatedGame) {
        myGame.get_Map().printMap(std::cout);
    }
    else if (sentinel == 6 && generatedGame) {
        std::cout << std::endl << "Please enter the output file name: ";
        std::cin >> auxString;
        std::ofstream os(auxString);
        myGame.get_Map().saveMap(os);
    }
    else if (sentinel == 7 && generatedGame) {
        std::cout << std::endl << "Please enter the output file name: ";
        std::cin >> auxString;
        std::ofstream os(auxString);
        myGame.saveData(os);
    }
    else if (sentinel == 8 && generatedGame) {
        ////////// NOT IMPLEMENTED YET
        return false;
    }
    else if (sentinel == 9 && generatedGame) {
        ////////// NOT IMPLEMENTED YET
        return false;
    }
    else {
        std::cout << std::endl << "Sorry, map has not been generated yet";
    }
    return false;
}