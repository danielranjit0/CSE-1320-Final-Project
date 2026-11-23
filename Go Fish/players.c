// Determine the number of players and distribution of cards to said players

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "players.h"

int playerFunction(Game *game)
{
    int players, cards;

    srand(time(NULL)); // Random number generator

    printf("How many players (2-6): \n");
    scanf("%d", &players);

    // How many cards everyone gets
    if (players >= 2 && players <= 3)
    {
        cards = 7;
    }
    else if (players > 3 && players <= 6)
    {
        cards = 5;
    }
    else
    {
        printf("This is an invalid number please pick a number between (2-6)!\n");
        return 1;
    }

    // 1. Save player count and reset deck/player states in the Game struct
    game->playerCount = players;
    game->currentPlayer = 0;
    game->deckCount = 0;

    // 2. Build the 52-card deck inside game->deck
    char suits[4] = {'D', 'H', 'S', 'C'};
    for (int s = 0; s < 4; s++)
    {
        for (int r = 1; r <= 13; r++)
        {
            game->deck[game->deckCount].rank = r;
            game->deck[game->deckCount].suit = suits[s];
            game->deckCount++;
        }
    }

    // 3. Shuffle the deck (Fisher-Yates shuffle)
    for (int i = game->deckCount - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card temp = game->deck[i];
        game->deck[i] = game->deck[j];
        game->deck[j] = temp;
    }

    // 4. Deal cards from game->deck into each player's hand
    for (int p = 0; p < players; p++)
    {
        game->players[p].handCount = 0;
        game->players[p].books = 0;

        printf("Player %d's Hand: ", p + 1);

        for (int c = 0; c < cards; c++)
        {
            // Take the top card from game->deck and put it in the player's hand
            Card dealtCard = game->deck[game->deckCount - 1];
            game->deckCount--;

            game->players[p].hand[game->players[p].handCount] = dealtCard;
            game->players[p].handCount++;

            printf("%d%c ", dealtCard.rank, dealtCard.suit);
        }
        printf("\n");
    }

    return 0;
}
