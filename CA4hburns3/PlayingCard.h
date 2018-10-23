//enum to compare the hand they have
typedef enum {
	nothing,
	one_pair,
	two_pair,
	three_of_a_kind,
	straight,
	flush, full_house,
	four_of_a_kind,
	straight_flush,
	royal_flush} bestHand;

//enum for the suit each card has
typedef enum {
	hearts = 0,
	spades = 1,
	clubs = 2,
	diamonds = 3} suit;
//struct of a card containing a value and a suit
typedef struct card{
	int val;
	int card_suit;
} CARD;

//player stuct with 2 cards, and the strength of his hand
typedef struct Player{
	bestHand hand;
	CARD* card1;
	CARD* card2;
} PLAYER;

typedef struct Everything{
		PLAYER* players[3];
		CARD* community[5];
} EVERYTHING;

int indexing(CARD*[], int);
void whichPlayerWon(EVERYTHING*, int);
void formatCardFromInput(char*, CARD*);
void printCard(CARD* card);
void printPlayer(PLAYER* player);
void printEverything(EVERYTHING* table);
void evaluateHandStrength(PLAYER* player, CARD**);
void printNumeric(int val);
int isRoyalFlush(PLAYER* player, CARD** community);
int isStraight_flush(PLAYER* player, CARD** community);
int isFour_of_a_kind(PLAYER* player, CARD** community);
int isFull_house(PLAYER* player, CARD** community);
int isFlush(PLAYER* player, CARD** community);
int isStraight(PLAYER* player, CARD** community);
int isThree_of_a_kind(PLAYER* player, CARD** community);
int isTwo_pairs(PLAYER* player, CARD** community);
int isPair(PLAYER* player, CARD** community);
char* printCardsFromStartingIndex(int start_value);
