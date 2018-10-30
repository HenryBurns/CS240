#include "LinkedList.hpp"
#include "PlayingCard.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv){
    PlayingCard* card1 = new PlayingCard();
    card1 -> card_suit = HEARTS;
    card1 -> val = 6;
    LLC<PlayingCard>* cards = new LLC<PlayingCard>();
    cards -> insert(*card1);
	
    return 0;
	}
