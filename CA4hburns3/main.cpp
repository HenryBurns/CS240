#include "LinkedList.hpp"
#include "PlayingCard.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv){
    PlayingCard* card1 = new PlayingCard(14, DIAMONDS);
    LLC<PlayingCard>* cards = new LLC<PlayingCard>();
    cards -> insert(*card1);
    PlayingCard* card2 = new PlayingCard(5, HEARTS);
    cards -> insert(*card2);
    std::cout << *cards << std::endl;
	
    return 0;
	}
