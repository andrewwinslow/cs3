
#ifndef BATCOIN_H
#define BATCOIN_H

#include <string>

using namespace std;

class BlockHeader
{
	public:
		BlockHeader();
		string to_string();

		// These store 8 bytes of information each,
		// storing each byte as an unsigned char.
		unsigned char prev[8];  // Previous BlockHeader hash value
		unsigned char nonce[8]; // The nonce for this BlockHeader
};

// The hash function used in the Batcoin protocol.
void bathash(BlockHeader b, unsigned char* result);

#endif

