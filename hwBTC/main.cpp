
#include <iostream>
#include "batcoin.h"
#include "mine.h"

using namespace std;

inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
	abort();
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


void test_mining(BlockHeader genesis, int difficulty, int coins)
{
	BlockHeader prev, cur;
	unsigned char result[8];


	// Mine some BatCoins! 
	prev = genesis;
	for (int i = 1; i <= coins; ++i)
	{
		// Uses your mining algorithm to mine a valid next coin,
		// i.e. find a valid next block.
		cur = mine(prev, difficulty);

		// Check that newly mined block has correct prev bytes. 
		// Namely, those in the output of bathash(prev).
		bathash(prev, result);
		for (int c = 0; c < 8; ++c)
			test(result[c] == cur.prev[c]);

		// Check that newly mined block has a hash value
		// with the first difficulty bytes equal to 0.
		bathash(cur, result);
		for (int j = 0; j < difficulty; ++j)
			test(result[j] == 0);

		// Uncomment the next line to print mined coins
		//cout << cur.to_string() << endl;
		prev = cur;
	}
}


int main()
{
	// See https://en.bitcoin.it/wiki/Genesis_block
	// for more information about first block headers.
	BlockHeader genesis; 
	genesis.prev[0] =  's';
	genesis.prev[1] =  'e';
	genesis.prev[2] =  'c';
	genesis.prev[3] =  'o';
	genesis.prev[4] =  'n';
	genesis.prev[5] =  'd';
	genesis.prev[6] =  'b';
	genesis.prev[7] =  'a';
	genesis.nonce[0] = 't';
	genesis.nonce[1] = 'b';
	genesis.nonce[2] = 'a';
	genesis.nonce[3] = 'i';
	genesis.nonce[4] = 'l';
	genesis.nonce[5] = 'o';
	genesis.nonce[6] = 'u';
	genesis.nonce[7] = 't';


	// Mine 10000 coins at difficulty 1
	bathash(genesis, genesis.prev); 
	test_mining(genesis, 1, 10000);

	// Mine 100 coins at difficulty 2
	bathash(genesis, genesis.prev); 
	test_mining(genesis, 2, 100);

	// Mine 1 coin at difficulty 3 
	bathash(genesis, genesis.prev); 
	test_mining(genesis, 3, 1);


	cout << "Assignment complete." << endl;
}



