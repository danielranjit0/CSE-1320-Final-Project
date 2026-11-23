#include <stdio.h>

#include "players.h"
#include "interactions.h"

int main(void) 
{
    Game game = {0};
    
    if (playerFunction(&game)!= 0)//exit the program incase of an invalid input
    {
        return 1;
    }
    interactionFunction(&game);
    displayStats(&game);
    
    return 0;
}
