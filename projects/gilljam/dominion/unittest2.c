/***********************************************************
* Name: James S Gill
* Description: Tests that whose turn updates everytime a
* player ends their turn
************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int assert(int statement) {
  if (!statement) {
    printf("assertion failed");
    #if (NOISY_TEST == 1)
      printf("**************unittest2 - whoseTurn FAILED***************\n");
    #endif
    exit(0);
  }
  return 0;
}

int main() {
  int kingdom[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState state;
  int x, i, numPlayer = 2, seed = 350, numTurns = 100;

  x = initializeGame(numPlayer, kingdom, seed, &state);


  //First persons turn
  x = whoseTurn(&state);
	assert(x==0);

  for (i = 0; i < numTurns; i++){
    //Second persons turn
    x = endTurn(&state);
    x = whoseTurn(&state);
    assert(x==1);
    //First persons turn
    x = endTurn(&state);
    x = whoseTurn(&state);
    assert(x==0);
  }

  #if (NOISY_TEST == 1)
    printf("**************unittest2 - whoseTurn PASSED ***************\n");
  #endif

  return 0;
}