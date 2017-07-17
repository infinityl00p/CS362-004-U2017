/***********************************************************
* Name: James S Gill
* Description: Ensure that every person has a handcount of 5
* at the start of their turn and the other player has 0
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
      printf("**************unittest3 - handCount FAILED***************\n");
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

  for(i = 0; i < numTurns; i++) {
    // first player has 5 cards
      x = state.handCount[0];
      assert(x==5);
      // second player has 0 cards until his turn is called
      x = state.handCount[1];
      assert(x==0);

      //end first players turn
      x = endTurn(&state);

      //player 1 should have 0 handcount
      x = state.handCount[0];
      assert(x==0);

      //second player has 5 cards after his turn is called
      x = state.handCount[1];
      assert(x==5);

      //second player has 0 cards drawn after he finished his turn
      x = endTurn(&state);
      x = state.handCount[1];
      assert(x==0);
  }

  #if (NOISY_TEST == 1)
    printf("**************unittest3 - handCount  PASSED ***************\n");
  #endif

  return 0;
}