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
    std::ifstream file;
    file.open(argv[1]);
    std::string name1;
    std::string name2;
    file >> name1;
    file >> name2;
    std::cout << "Pre game here" << std::endl;
    Player* player1 = new Player(name1);
    Player* player2 = new Player(name2);
    Game* game = new Game();
    std::cout << *game << std::endl;
    Player winner = game->play(*player1, *player2);
    winner.wins++;
    std::cout << "Winner: " << winner << "\n Num cards: " << winner.cards.len()<< std::endl;
    std::cout << "Player 1: " << *player1 << std::endl;
    std::cout << "Player 2: " << *player2 << std::endl;
    delete game;
    delete player1;
    delete player2;
    return 0;
	}


