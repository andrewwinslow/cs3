
#ifndef ORACLE_H
#define ORACLE_H

#include <cmath>

class Oracle
{
	public:
		// Creates a new oracle, ready to be told all numbers 
		// (in any order) from 1 to 1000000, except for one or two.
		//
		// Must run in O(1) time.
		Oracle();

		// Tells the oracle a number between 1 and 1000000 not yet told.
		//
		// Must run in O(1) time.
		void tell(int i);

		// If every number between 1 and 1000000 except one have 
		// been told, and no number has been told more than once, 
		// sets x equal to the one number not yet told.
		// 
		// Otherwise has undefined behavior.
		//
		// Must run in O(1) time.
		void missing_one(int &x);


		// If every number between 1 and 1000000 except two have 
		// been told, and no number has been told more than once, 
		// sets x and y equal to the two numbers not yet told (where x < y).
		//
		// Otherwise has undefined behavior.
		//
		// Must run in O(1) time.
		void missing_two(int &x, int &y);

	private:
		long long int data[2];
};

#endif

