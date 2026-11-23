
#ifndef GAME_H
#define GAME_H

#define MAX_PLAYERS 6
#define MAX_CARDS 52
#define HAND_SIZE 52

typedef struct
{
  int rank;
  char suit;
}card;

typedef struct
{
  int id;
  
  card hand[HAND_SIZE];
  int handCount;
  int books;

  int wins;
  int losses;
  int currentStreak;
  int bestStreak;
}player;

void initializeDeck(card deck[]);
void shuffleDeck(card deck[]);
void dealCards(player players[], int playerCount, card deck[], int *deckCount);

void interaction(player players[], int playerCount, card desk[], int *deckCount);
void displayStats(player players[], int playerCount);

#endif
