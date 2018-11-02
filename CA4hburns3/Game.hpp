#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"

class Game {
    public:
        Player player1;
        Player player2;
        LLC<PlayingCard> community;
        Game();
        int play();
        void battle();
        void war();
	    friend std::ostream& operator<<(std::ostream &, const Game &);
};

       
        
#endif
