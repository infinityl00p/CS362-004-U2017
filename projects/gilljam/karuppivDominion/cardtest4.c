/***********************************************************
* Name: James S Gill
* Description: Tests Council Room card, allows you to add 4 cards
* and 1 extra buy, each other player draws a card
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
#define TESTCARD "councilroom"

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
	cardEffect(council_room, choice1, choice2, choice3, &testState, handPos, &bonus);
  newCards = 4;
  printf("handcount = %d, expected = %d\n", testState.handCount[player1], state.handCount[player1] + newCards - discarded);
  printf("deckCount = %d, expected = %d\n", testState.deckCount[player1], state.deckCount[player1] - newCards + shuffledCards);
  //numBuys should increase by 1
  printf("numBuys = %d, expected = %d\n", testState.numBuys, state.numBuys + 1);

  return 0;
}