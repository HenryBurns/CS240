#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
class Player {
    public:
        int wins = 0;
        LLC<PlayingCard> cards;
       Player(){
                name = "[empty]";
        }
        std::string name;
	    friend std::ostream& operator<<(std::ostream &out_stream, const Player &other){
        out_stream << other.name << ": " << other.cards;
        return out_stream;
    }
};

 

#endif
