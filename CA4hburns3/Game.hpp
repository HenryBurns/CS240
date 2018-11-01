#ifndef GAME_HPP
#define GAME_HPP

class Game {
    public:
        LLC<PlayingCard> player1;
        LLC<PlayingCard> player2;
        LLC<PlayingCard> community;
        Game();
        int Battle();
        void War();
};

       
        
#endif
