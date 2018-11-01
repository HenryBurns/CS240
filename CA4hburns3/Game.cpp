#include "LinkedList.hpp"
#include "PlayingCard.hpp"
#include "Game.hpp"

Game::Game(){
    for(int i = 2; i < 15; i++){
        for(int j = 0; j < 4; j ++){
            community.insert(PlayingCard(i, HEARTS));
            community.insert(PlayingCard(i, DIAMONDS));
            community.insert(PlayingCard(i, SPADES));
            community.insert(PlayingCard(i, CLUBS));
            }
        }
    community.shuffle();
    for(int i = 0; i < 26; i ++){
            player1.insert(community.getElement(i));
    }
    for(int i = 26; i < 52; i++){
            player2.insert(community.getElement(i));
    }
}
 
