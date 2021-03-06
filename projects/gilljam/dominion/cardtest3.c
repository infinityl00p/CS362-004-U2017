/***********************************************************
* Name: James S Gill
* Description: Tests village card, should give you +1 card
* from the deck and +2 actions
************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
#define TESTCARD "village"

int main() {
  int kingdom[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState state, testState;
  int x, numPlayer = 2, seed = 350;
  int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player1 = 0, discarded = 1, shuffledCards = 0, newCards = 0;

  x = initializeGame(numPlayer, kingdom, seed, &state);
  assert(x==0);

	printf("************** Testing Card: %s ***************\n", TESTCARD);
	memcpy(&testState, &state, sizeof(struct gameState));
	cardEffect(village, choice1, choice2, choice3, &testState, handPos, &bonus);
  newCards = 1;
  printf("handcount = %d, expected = %d\n", testState.handCount[player1], state.handCount[player1] + newCards - discarded);
  printf("deckCount = %d, expected = %d\n", testState.deckCount[player1], state.deckCount[player1] - newCards + shuffledCards);
  printf("numActions = %d, expected = %d\n", testState.numActions, state.numActions + 2);

  return 0;
}