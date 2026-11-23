//Allow everyting to access game information

#ifndef GAME_H
#define GAME_H

#define MAX_PLAYERS 6
#define MAX_CARDS 52
#define MAX_RANK 13

typedef struct
{
    int rank;
    char suit;
} Card;

typedef struct
{
    Card hand[MAX_CARDS];
    int handCount;

    int books;

    int wins;
    int losses;

    int currentStreak;
    int bestStreak;

} Player;

typedef struct
{
    Player players[MAX_PLAYERS];

    Card deck[MAX_CARDS];
    int deckCount;

    int playerCount;
    int currentPlayer;

} Game;

#endif
