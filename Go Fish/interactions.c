//How the players and the cards will interact with one another

#include<stdio.h>
#include<stdlib.h>

#include "interactions.h"

int hasCard(Player *player, int rank) //checking for the value of the cards
{
  for(int i = 0; i < player->handCount; i++)
    {
      if(player->hand[i].rank == rank)
        return 1;
    }
  return 0;
}

void removeCard(Player *player, int index) //remove taken cards
{
  for(int i = index; i < player -> handCount - 1; i++)
    {
      player->hand[i] = player -> hand[i + 1];
    }

  player->handCount--;
}

void transferCards(Player *from, Player *to, int rank)//transfer all cards of a particular number
{
  for(int i = 0; i < from-> handCount;)
    {
      if(from -> hand[i].rank == rank)
      {
        to->hand[to -> handCount] = from -> hand[1];
        to -> handCount++;

        removeCard(from, 1);
      }
      else
        i++;
    }
}

void checkBook(Player *player)//checks if someone has 4 cards of the same value
{
  for(int rank = 1; rank <= 13; rank++)
    {
      int count = 0;

      for(int i = 0; i < player -> handCount; i++)
      {
        if(player -> hand[i].rank == rank)
          count++;
      }
      if(count == 4)
      {
        printf("Player collected a book of rank %d!\n", rank);

        for(int i = 0; i < player -> handCount;)//remove cards
          {
            if(player -> hand[i].rank == rank)
              removeCard(player, i);
            else
              i++;
          }
        player -> books++;
      }
    }
}

void drawCard(Game *game, Player *player)//draws cards from deck
{
  if(game -> deckCount <= 0)
  {
    printf("There are no cards left in the deck!\n");
    return;
  }

player -> hand [player -> handCount] =
    game -> deck[game -> deckCount - 1];

player -> handCount++;

game -> deckCount--;

  printf("Player drew a card!\n");
}

int gameOver(Game *game)//determine if the game has ended
{
  if(game -> deckCount > 0)
    return 0;

  for(int i = 0; i < game -> playerCount; i++)
    {
      if(game -> players[i].handCount>0)
        return 0;
    }

  return 1;
}

void interaction(Game *game)//how they interact
{
  while(!gameOver(game))
    {
      int current = game -> currentPlayer;
      Player *player = &game -> players[current];

      printf("\n--- Player %d's Turn ---\n", current + 1);

      if(player -> handCount == 0)
      {
        drawCard(game, player);

        if(player -> handCount == 0)//if player doesnt have cards
        {

          game -> currentPlayer = (game -> currentPlayer + 1) % game -> playerCount;

          continue;
        }
      }

      printf("Your cards: ");

      for(int i = 0; i < player -> handCount; i++)
        {
          printf("%d%c ", player -> hand[i].rank, player -> hand[i].suit);
        }

      printf("\n");

      int target;
      int rank;

      printf("Choose a player to ask (1-%d): ", game -> playerCount);

      scanf("%d", &target);

        if (target < 1 ||
            target > game->playerCount ||
            target == current + 1)
        {
            printf("Invalid player selection!\n");
            continue;
        }

        printf("Which rank do you want to ask for (1-13)? ");
        scanf("%d", &rank);

        if (rank < 1 || rank > 13 ||
            !hasCard(player, rank))
        {
            printf("You must request a rank in your hand!\n");
            continue;
        }

        Player *opponent = &game->players[target - 1];

        printf("\nPlayer %d asks Player %d for rank %d.\n",
            current + 1, target, rank);

        if (hasCard(opponent, rank))
        {
            printf("The player has that card!\n");

            transferCards(opponent, player, rank);

            checkBooks(player);

            printf("Player %d gets another turn!\n",
                current + 1);

            continue;
        }
        else
        {
            printf("GO FISH!\n");

            drawCard(game, player);

            checkBooks(player);

            //if drawn card matches cards on hand they will get another turn
            if (player->handCount > 0 && player->hand[player->handCount - 1].rank == rank)
            {
                printf("You drew the requested rank! "
                       "Take another turn!\n");

                continue;
            }
        }
        
        game->currentPlayer = (game->currentPlayer + 1) % game->playerCount; //next player
    }
}

void displayStats(Game *game) //keeps track of win, loss, and streeks
{
    int highestBooks = 0;

    // Find the highest number of the same value.
    for (int i = 0; i < game->playerCount; i++)
    {
        if (game->players[i].books > highestBooks)highestBooks = game->players[i].books;
    }

    printf("\n=== GAME RESULTS ===\n");

    for (int i = 0; i < game->playerCount; i++)
    {
        Player *p = &game->players[i];

        if (p->books == highestBooks)
        {
            printf("Player %d WINS!\n", i + 1);

            p->wins++;
            p->currentStreak++;

            if (p->currentStreak > p->bestStreak) p->bestStreak = p->currentStreak;
        }
        else
        {
            printf("Player %d LOSES!\n", i + 1);

            p->losses++;
            p->currentStreak = 0;
        }

        printf("\nPlayer %d Statistics:\n", i + 1);

        printf("Wins: %d\n", p->wins);
        printf("Losses: %d\n", p->losses);

        printf("Current Win Streak: %d\n",
            p->currentStreak);

        printf("Best Win Streak: %d\n",
            p->bestStreak);

        if (p->losses > 0)
        {
            printf("Win/Loss Ratio: %.2f\n", (double)p->wins / p->losses);
        }
        else
        {
            printf("Win/Loss Ratio: No losses yet\n");
        }
    }
}
