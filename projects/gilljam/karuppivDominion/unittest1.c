/***********************************************************
* Name: James S Gill
* Description: Tests that initialize game always starts a game
* and that the state of the game is updated
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
      printf("**************unittest1 - isGameOver FAILED***************\n");
    #endif
    exit(0);
  }
  return 0;
}

int main() {
  int kingdom[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState state;
  int x, numPlayer = 2, seed = 350, maxDeck = 500;

  x = initializeGame(numPlayer, kingdom, seed, &state);
  //game doesn't end right when it begins
  x = isGameOver(&state);
	assert(x==0);

  //each player has 5 cards on deck
  x = state.deckCount[numPlayer-1];
  assert (x==10);

  //hand count for each player should be 0
  x = state.handCount[numPlayer-1];
  assert (x==0);

  //No cards discarded yet
  x = state.discardCount[numPlayer-1];
  assert (x==0);

  //2 players exist
  x = state.numPlayers;
  assert (x==2);

  //first players turn
  x = state.whoseTurn;
  assert (x==0);

  //1 numbuy at beginning of first turn
  x = state.numBuys;
  assert (x==1);

  //No cards have been played yet
  x = state.playedCards[maxDeck];
  assert (x==0);


  #if (NOISY_TEST == 1)
    printf("**************unittest1 - isGameOver PASSED***************\n");
  #endif

  return 0;
}