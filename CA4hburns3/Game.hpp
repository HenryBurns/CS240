#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include <string>

class Game {
    public:
        Player player1;
        Player player2;
        void setUp();
        void setCommunity();
        void readyPlayers(Player &player1, Player &player2);
        LLC<PlayingCard> community;
        Game();
        ~Game(); 
        Game(Player &p1, Player &p2);
        Player &play(Player & player1, Player &player2);
        void battle(Player &player1, Player &player2);
        void war(Player &player1, Player &player2);
	    friend std::ostream& operator<<(std::ostream &, const Game &);
};

       
        
#endif
