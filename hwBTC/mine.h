
#ifndef MINE_H
#define MINE_H

#include "batcoin.h"

// Returns a BlockHeader whose prev bytes are equal to the 
// output of bathash(prev) and that hashes to a set of bytes
// where the first difficulty of them are equal to 0.
BlockHeader mine(BlockHeader prev, int difficulty);

#endif

