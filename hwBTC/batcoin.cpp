
#include <sstream>
#include "batcoin.h"

using namespace std;

BlockHeader :: BlockHeader()
{
	for (int i = 0; i < 8; ++i)
		prev[i] = nonce[i] = 0;
}

string BlockHeader :: to_string()
{
	ostringstream oss;
	oss << " prev: ";
	for (int i = 0; i < 8; ++i) 
	{
		unsigned int v = prev[i];
		if (v < 100)
			oss << " ";
		if (v < 10)
			oss << " ";
		oss << v;
		if (i < 7)
			oss << " ";
	}
	oss << endl;

	oss << "nonce: ";
	for (int i = 0; i < 8; ++i) 
	{
		unsigned int v = nonce[i];
		if (v < 100)
			oss << " ";
		if (v < 10)
			oss << " ";
		oss << v;
		if (i < 7)
			oss << " ";
	}
	oss << endl;

	return oss.str();
}

void bathash(BlockHeader b, unsigned char* result)
{
	// This is somewhat similar to SHA-2 
	// Specifically, 128-bit SHA-2.

	for (int i = 0; i < 8; ++i)
		result[i] = b.prev[i] ^ b.nonce[i];

	unsigned char K[9] = {'f', '2', '0', '1', '8', '3', '3', '3', '3'};

	for (int r = 0; r < 32; ++r)
	{
		unsigned char T[5];

		T[0] = (result[4] & result[5]) ^ (~result[4] & result[7]) + K[r % 9];
		T[1] = (result[0] & result[1]) ^ (result[0] & result[2]) ^ (result[1] & result[2]);
		T[2] = (result[0] >> 1) ^ (result[0] >> 3) ^ (result[0] >> 6);
		T[3] = (result[4] >> 2) ^ (result[4] >> 5) ^ (result[4] >> 7);

		result[3] = result[3] + result[7] + T[0] + T[3];
		T[4] = result[7] + T[0] + T[1] + T[2] + T[3];
		for (int i = 6; i >= 0; --i)
			result[i+1] = result[i];
		result[0] = T[4];
	}
}


