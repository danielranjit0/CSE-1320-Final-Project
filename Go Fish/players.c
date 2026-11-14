#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  //The types of cards and the the amount
  int dimonds[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int hearts[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int spades[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int clubs[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

  int dNum = 13, hNum = 13, sNum = 13, cNum = 13; //Keeps track of the amount of numbers in each house

  int players;
  int cards;

  srand(time(NULL)); //random num generator
  
  printf("Howmany players (2-6): \n");
  scanf("%d", &players);

  //How many cards everyone gets
  if(players >= 2 && players <= 3)//more then 2 and less then 3 players get 7 cards each
  {
    cards = 7;
  }
  else if(players > 3 && players<= 6)//4 or more players get 5 cards each
  {
    cards = 5;
  }
  else//invalid answers
  {
    printf("This is an invalid number please pick a number between (2-6)!\n");
    return 1;
  }

  //Dealing Cards
  for(int p = 1; p < players; p++)
  {
    printf("Players %d's Hand", p);

    for(int c = 0; c < cards; c++)
    {
      int  dealt = 0;

      while (!dealt)
      {
        int house = rand() % 4;

        case
      }
    }
  }
}
