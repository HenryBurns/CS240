#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
class Player {
    public:
        int hands_played = 0;
        int wars = 0;
        int battles_won = 0;
        int wins = 0;
        LLC<PlayingCard> cards;
       Player(){
                name = "[empty]";
        }
       Player(std::string val){
                name = val;
        }
        std::string name;
	    friend std::ostream& operator<<(std::ostream &out_stream, const Player &other){
        out_stream << other.name << ": " << other.cards << std::endl;
        out_stream << other.hands_played << " hands played. " << other.wars << " wars. "<< other.battles_won << " battles won. " << other.wins << " won." << std::endl;
        return out_stream;
    }
};

 

#endif
