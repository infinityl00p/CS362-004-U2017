/***********************************************************
* Name: James S Gill
* Description: Ensure that the total deck count matches the sum
* of all cards in the deck
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
      printf("**************unittest4 - fullDeckCount FAILED***************\n");
    #endif
    exit(0);
  }
  return 0;
}

int main() {
  int kingdom[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState state;
  int x, i, count = 0, numPlayer = 2, seed = 350;

  x = initializeGame(numPlayer, kingdom, seed, &state);
  assert (x == 0);

  x = fullDeckCount(0, silver, &state);
  assert(x >= 0);

  //count the cards in each state, should equal x
  for (i=0 ; i < state.handCount[0] ; i++){
      if (state.hand[0][i] == silver) {
        count++;
      }
  }
  for (i=0 ; i < state.deckCount[0] ; i++){
      if (state.deck[0][i] == silver) {
        count++;
      }
  }
  for (i=0 ; i< state.discardCount[0] ; i++){
      if (state.discard[0][i] == silver) {
        count++;
      }
  }

  assert(x == count);

  #if (NOISY_TEST == 1)
    printf("**************unittest4 - fullDeckCount PASSED***************\n");
  #endif

  return 0;
}