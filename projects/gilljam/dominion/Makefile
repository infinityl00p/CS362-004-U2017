CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)


#cardtest1: cardtest1.c dominion.o rngs.o
#	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

#cardtest2: cardtest2.c dominion.o rngs.o
#	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

#cardtest3: cardtest3.c dominion.o rngs.o
#	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

#cardtest4: cardtest4.c dominion.o rngs.o
#	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard1.out: randomtestcard1.c dominion.c rngs.c
	echo "randomtestcard1.c:" > randomtestcard1.out
	gcc -o randomtestcard1 -g dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	echo >> randomtestcard1.out
	gcov -b -c dominion.c >> randomtestcard1.out
	echo 'coverage results:'>> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestcard2.out: randomtestcard2.c dominion.c rngs.c
	echo "randomtestcard2.c:" > randomtestcard2.out
	gcc -o randomtestcard2 -g dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	echo >> randomtestcard2.out
	gcov -b -c dominion.c >> randomtestcard2.out
	echo 'coverage results:'>> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	echo "randomtestadventurer.c:" > randomtestadventurer.out
	gcc -o randomtestadventurer -g dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	echo >> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out
	echo 'coverage results:'>> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out


#testDrawCard: testDrawCard.c dominion.o rngs.o
#	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

#unittest1: unittest1.c dominion.o rngs.o
#	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

#unittest2: unittest2.c dominion.o rngs.o
#	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

#unittest3: unittest3.c dominion.o rngs.o
#	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

#unittest4: unittest4.c dominion.o rngs.o
#	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

#badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
#	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

#testBuyCard: testDrawCard.c dominion.o rngs.o
#	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

#testAll: dominion.o testSuite.c
#	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

#runtests: testDrawCard
#	./testDrawCard &> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out

#unittestresults: cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 dominion.o
#	./cardtest1 >> unittestresults.out 2>&1
#	./cardtest2 >> unittestresults.out 2>&1
#	./cardtest3 >> unittestresults.out 2>&1
#	./cardtest4 >> unittestresults.out 2>&1
#	./unittest1 >> unittestresults.out 2>&1
#	./unittest2 >> unittestresults.out 2>&1
#	./unittest3 >> unittestresults.out 2>&1
#	./unittest4 >> unittestresults.out 2>&1
#	gcov dominion.c >> unittestresults.out
#	cat dominion.c.gcov >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player randomtestcard1 randomtestcard1.out randomtestcard2 randomtestcard2.out randomtestadventurer randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe randomtestcard1 randomtestcard1.exe randomtestcard1.out randomtestcard2 randomtestcard2.exe randomtestcard2.out randomtestadventurer randomtestadventurer.out *.gcov *.gcda *.gcno *.so
