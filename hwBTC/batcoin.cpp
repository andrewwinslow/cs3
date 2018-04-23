
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
	// Sum of all bytes
	unsigned char sum = 0;
	for (int i = 0; i < 8; ++i)
		sum += b.prev[i] + b.nonce[i];

	// Set each byte of the result is the XOR of two bytes
	// (one from prev, one from nonce) 
	// plus sum bits shifted right by 1 
	// plus 1 
	for (int i = 0; i < 8; ++i)
		result[i] = (b.prev[i] ^ b.nonce[7-i]) + (sum >> 1) + 1;

	// "Rotate" the bytes, shifting each left by one byte and 
	// setting the last byte equal to a function of the sum
	for (int i = 0; i < 7; ++i)
		result[i] = result[i+1];
	result[7] = 256 - sum;
}


