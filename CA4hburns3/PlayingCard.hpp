#ifndef PLAYINGCARD_HPP
#define PLAYINGCARD_HPP
#include <iostream>
//enum for the suit each card has
typedef enum {
	HEARTS = 0,
	SPADES = 1,
	CLUBS = 2,
	DIAMONDS = 3} suit;
//struct of a card containing a value and a suit
class PlayingCard{
	public:
        PlayingCard();
        PlayingCard(int new_val, suit new_card_suit );
        bool operator>(const PlayingCard &other);
        bool operator<(const PlayingCard &other);
        bool operator==(const PlayingCard &other);
		int val;
	    suit card_suit;
        friend std::ostream& operator<<(std::ostream &out_stream, const PlayingCard &other);
};
#endif
