#include "LinkedList.hpp"
#include "PlayingCard.hpp" 
#include "Game.hpp"

Game::Game(Player &player1, Player &player2){ 
        Game();
}
Game::~Game(){ 
}
Game::Game(){ 
}
void Game::readyPlayers(Player &player1, Player &player2){
            for(int i = 0; i < 26; i++){
                player1.cards.addNode(community.getElement());
            }
            for(int i = 26; i < 52; i++){
               player2.cards.addNode(community.getElement());
            }
}
void Game::setCommunity(){
        for(int i = 2; i < 15; i++){ 
                community.insert(PlayingCard(i,HEARTS)); 
                community.insert(PlayingCard(i, DIAMONDS));
                community.insert(PlayingCard(i, SPADES)); 
                community.insert(PlayingCard(i, CLUBS)); 
        }
            community.shuffle();

}

void Game::setUp(){
                }
 
    std::ostream& operator<<(std::ostream &out_stream, const Game &other){
            out_stream << "Player1: " << other.player1 << std::endl; 
            out_stream << "Player2: " << other.player2 << std::endl; 
            return out_stream; }
    
    Player &Game::play(Player & player1, Player &player2){ 
            setCommunity();
            readyPlayers( player1, player2);
            int cntr = 0;

            while(player1.cards.len() > 0 && player2.cards.len() > 0 ){
                    cntr++;
                    if(cntr > 1000)
                            return player1;
                    battle(player1, player2); 
                    std::cout << "Community cards: " << community << "\n p1 length: " << player1.cards.len() << ". p2 length: " << player2.cards.len() << std::endl;
            }
            return (player1.cards.len() > player2.cards.len())? player1 : player2;

    }
    
    void Game::battle(Player &player1, Player &player2){
            community.addNode(player1.cards.getElement());
            community.addNode(player2.cards.getElement()); PlayingCard card1 =
                    community.getData(0); PlayingCard card2 = community.getData(1);
            if(card1 > card2){
                    player1.battles_won++;
                    player1.cards.addNode(community.getElement());
                    player1.cards.addNode(community.getElement()); }
            else if (card1 < card2){
                    player2.battles_won++;
                    player2.cards.addNode(community.getElement());
                    player2.cards.addNode(community.getElement()); } 
            else {
                    war(player1, player2); 
            }
    }

    void Game::war(Player &player1, Player &player2){ 
            player1.wars++;
            player2.wars++;
            std::cout << "Starting a war, mkay?" << std::endl;
            PlayingCard card1;
            PlayingCard card2;
            NODE<PlayingCard>* temp;
            int more_cards = 0;
            int length = community.len();
            if(player1.cards.len() == 0){
                    player1.battles_won++;
                    for(int i = 0; i< length; i++){
                        player2.cards.addNode(community.getElement());
                    }

            }
            else if(player2.cards.len() == 0){
                    player1.battles_won++;
                    for(int i = 0; i< length; i++){
                        player1.cards.addNode(community.getElement());
                    }
            }
            else{ std::cout << "Actually doing the war,mkay?" << std::endl;
                    if(player1.cards.len() < 4){
                            for(int i = 0; i < player1.cards.len() ; i++){
                                temp = player1.cards.getElement();
                                community.addNode(temp);
                            }
                            card1 = temp->data;

                    } else {
                        std::cout << "People have many cards left" << std::endl;
                        more_cards++;
                        for(int i = 0; i < 4 ; i++){
                                temp = player1.cards.getElement();
                                community.addNode(temp);
                            }
                            card1 = temp->data;


                    }
                    if(player2.cards.len() < 4){
                            for(int i = 0; i < player2.cards.len() ; i++){
                                temp = player2.cards.getElement();
                                community.addNode(temp);
                            }
                            card2 = temp->data;

                    } else {
                        std::cout << "More than three cards for p2, mkay?" << std::endl;
                        more_cards++;
                        for(int i = 0; i < 4 ; i++){
                                temp = player2.cards.getElement();
                                community.addNode(temp);
                            }
                        card2 = temp->data;
                    }
                    length = community.len();
                    std::cout << "Card1: " << card1 << ". Card 2: " << card2 << std::endl;
                    if(card1 > card2){
                            std::cout << "We ending p1 won" << std::endl;
                            std::cout << "P1: " << player1.cards << std::endl;
                    player1.battles_won++;
                    for(int i = 0; i< length; i++){
                        player1.cards.addNode(community.getElement());
                    }
                            std::cout << "We ended, mkay?" << std::endl;
                            return;
                    }
                    else if (card2 > card1){
                            std::cout << "We ending p2 won" << std::endl;
                            std::cout << "P2: " << player2.cards << std::endl;
                    player2.battles_won++;
                    for(int i = 0; i< length; i++){
                        player2.cards.addNode(community.getElement());
                    }
                            std::cout << "We ended, mkay?" << std::endl;
                            return;
                    }
                    else{
                        std::cout << "We have another war!!!!!!" << std::endl;
                        if(more_cards == 2){
                            war(player1, player2);
                        } else if (more_cards == 1){
                            Player temp = (player1.cards.len() > player2.cards.len())? player1 : player2;
                    temp.wins++;
                    for(int i = 0; i< length; i++){
                        temp.cards.addNode(community.getElement());
                    }
                        }
                        else{
                        player1.battles_won++;
                        for(int i = 0; i< length; i++){
                            player1.cards.addNode(community.getElement());
                            }
                        }
                    }
            }
    }
