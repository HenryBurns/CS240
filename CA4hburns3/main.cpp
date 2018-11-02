#include "LinkedList.hpp"
#include "PlayingCard.hpp"
#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv){
    if(argc < 2){
            std::cout << "Please enter a valid number of arguments." << std::endl;
            return 1;
    }
    std::ofstream file;
    file.open(argv[1]);
    std::cout << "Pre game here" << std::endl;
    Game* game = new Game();
    std::cout << *game << std::endl;
    int winner = game->play();
    std::cout << *game << std::endl;
    std::cout << "Post game here. Winner: " <<winner << std::endl;
    delete game;
    return 0;
	}
