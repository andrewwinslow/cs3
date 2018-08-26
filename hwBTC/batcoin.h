
#ifndef BATCOIN_H
#define BATCOIN_H

#include <string>

using namespace std;

class BlockHeader
{
	public:
		// Initializes a new BlockHeader to all zeroes
		BlockHeader();

		// Returns a string representation of the BlockHeader values.
		// For example:
		//
		//  prev: 114  64 204  51 183  55   8 239
		// nonce:  39 196 114 213  34  95 241  38
		//
		string to_string();

		// These store 8 bytes of information each,
		// storing each byte as an unsigned char.
		unsigned char prev[8];  // Previous BlockHeader hash value
		unsigned char nonce[8]; // The nonce for this BlockHeader
};

// The hash function used in the Batcoin protocol.
void bathash(BlockHeader b, unsigned char* result);

#endif

