//Determine the number of players and distrabution of cards to said players

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"players.h"

void playerFunction(void)
{
  //The types of cards and the the amount
  int diamonds[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int hearts[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int spades[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int clubs[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

  int dNum = 13, hNum = 13, sNum = 13, cNum = 13; //Keeps track of the amount of numbers in each house

  int players, cards;
  
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
  for(int p = 1; p <= players; p++)
  {
    printf("Players %d's Hand\n", p);

    for(int c = 0; c < cards; c++)
    {
      int  dealt = 0;

      while (!dealt)
      {
        int house = rand() % 4;
        int index;

        switch(house) //determine whats distrabuted
        {
          case 0:
            if(dNum > 0)
            {
              index = rand() % dNum;
              printf("%dD ", diamonds[index]);
              diamonds[index] = diamonds[dNum - 1];
              dNum--;
              dealt = 1;
            }break;
          case 1:
            if(hNum > 0)
            {
              index = rand() % hNum;
              printf("%dD ", hearts[index]);
              hearts[index] = hearts[hNum - 1];
              hNum--;
              dealt = 1;
            }break;
          case 2:
            if(sNum > 0)
            {
              index = rand() % sNum;
              printf("%dD ", spades[index]);
              spades[index] = spades[sNum - 1];
              sNum--;
              dealt = 1;
            }break;
          case 3:
            if(cNum > 0)
            {
              index = rand() % cNum;
              printf("%dD ", clubs[index]);
              clubs[index] = clubs[cNum - 1];
              cNum--;
              dealt = 1;
            }break;
        }
      }
    }
  }
}
