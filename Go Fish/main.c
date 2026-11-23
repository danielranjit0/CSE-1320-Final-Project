#include <stdio.h>

#include "players.h"
#include "interactions.h"

int main(void) 
{
    Game game = {0};
    
    playerFunction(&game);
    interactionFunction(&game);
    displayStats(&game);
    
    return 0;
}
