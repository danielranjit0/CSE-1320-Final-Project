#include <stdio.h>

#include "players.h"
#include "interactions.h"

int main(void) {
    playerFunction(&game);
    interactionFunction(&game);
    displayStats(&game);
    
    return 0;
}
