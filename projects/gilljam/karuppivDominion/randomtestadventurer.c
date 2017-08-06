/**************************************
    Name: James Gill
    Date: July.30/2017
    Description: random tests adventurerCard is executing as expected
 Reveal cards from your deck until you reveal 2 treasurer cards
 put those treasure cards in your hand and discard the other
 revealed cards
***************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "rngs.h"

#define NOISE_TEST 1
#define TEST_CARD "Adventurer"

int checkAdventurerCard(int p, struct gameState *post) {
    struct gameState pre;
    int r;

    memcpy (&pre, post, sizeof(struct gameState));

    r = Adventurer(p, 0, 0, post);
// increase handcount by 2
    pre.handCount[p] += 2;

    if (memcmp(&pre, post, sizeof(struct gameState)) != 0) {
        #if (NOISE_TEST==1)
            printf("%s failed at: \n", TEST_CARD);
            printf ("drawCard: player: %d   handCount: %d   deckCount: %d   discardCount: %d\n",
                p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
        #endif
    }


    return 0;
}


int main() {
    //Set initial variables
    int kingdom[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState state;
    int p, r, numPlayers, deckCount, discardCount, handCount;

    printf("***********Random Testing %s***********/\n", TEST_CARD);
    //set random player number
    srand(time(NULL));
    //2 to 4 players (0 indexed)
    numPlayers = rand() % 3 + 2;

    /* Citation: Code taken from testDrawCard.c to setup different game states */
    //for the number of players
    for (p = 0; p < numPlayers; p++) {
        //for a max deckCount of 5
        for (deckCount = 0; deckCount < 5; deckCount++) {
            //for a max discardCount of 5
            for (discardCount = 0; discardCount < 5; discardCount++) {
                //for a max handCount of 5
                for (handCount = 0; handCount < 5; handCount++) {
                    memset(&state, 23, sizeof(struct gameState));
                    r = initializeGame(2, kingdom, 1, &state);
                    state.deckCount[p] = deckCount;
                    memset(state.deck[p], 0, sizeof(int) * deckCount);
                    state.discardCount[p] = discardCount;
                    memset(state.discard[p], 0, sizeof(int) * discardCount);
                    state.handCount[p] = handCount;
                    memset(state.hand[p], 0, sizeof(int) * handCount);
                    checkAdventurerCard(p, &state);
                }
            }
        }
    }
    printf("***********End Test***********/\n\n\n\n\n");

    return 0;
}
