#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "oracle.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
	abort();
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main()
{
	// Setup
	srand(2018 + 's');
	int x, y, m, m1, m2;
	vector<int> V;


	// Test missing_one.
	Oracle o1;
	for (int i = 1; i <= 999999; ++i)
		o1.tell(i);
	x = 0;
	o1.missing_one(x);
	test(x == 1000000);


	Oracle o2;
	for (int i = 2; i <= 1000000; ++i)
		o2.tell(i);
	x = 0;
	o2.missing_one(x);
	test(x == 1);


	Oracle o3;
	o3.tell(1);
	for (int i = 3; i <= 1000000; ++i)
		o3.tell(i);
	x = 0;
	o3.missing_one(x);
	test(x == 2);

       
	Oracle o4;
	m = (rand() % 1000000) + 1; 
	for (int i = 1; i <= 1000000; ++i)
		if (i != m)
			o4.tell(i);
	x = 0;
	o4.missing_one(x);
	test(x == m);

 
	Oracle o5;
	m = (rand() % 1000000) + 1;
	for (int i = 1000000; i >= 1; --i)
		if (i != m)
			o5.tell(i);
	x = 0;
	o5.missing_one(x);
	test(x == m);


	Oracle o6;
	m = (rand() % 1000000) + 1;
	V.clear();
	for (int i = 1; i <= 1000000; ++i)
		if (i != m)
			V.push_back(i);
	random_shuffle(V.begin(), V.end()); 
	for (int i : V)
		o6.tell(i);        
	x = 0;
	o6.missing_one(x);
	test(x == m);


	Oracle o7;
	m = (rand() % 1000000) + 1;
	V.clear();
	for (int i = 1; i <= 1000000; ++i)
		if (i != m)
			V.push_back(i);
	random_shuffle(V.begin(), V.end()); 
	for (int i : V)
		o7.tell(i);        
	x = 0;
	o7.missing_one(x);
	test(x == m);


	Oracle o8;
	m = (rand() % 1000000) + 1;
	V.clear();
	for (int i = 1; i <= 1000000; ++i)
		if (i != m)
			V.push_back(i);
	random_shuffle(V.begin(), V.end()); 
	for (int i : V)
		o8.tell(i);        
	x = 0;
	o8.missing_one(x);
	test(x == m);

       
	// Retest old oracles to prevent global variables 
	x = 0;
	o1.missing_one(x);
	test(x == 1000000);

	x = 0;
	o3.missing_one(x);
	test(x == 2);

	x = 0;
	o8.missing_one(x);
	test(x == m);


	// Test missing_two
	Oracle o9;
	for (int i = 1; i <= 999998; ++i)
		o9.tell(i);
	x = y = 0;
	o9.missing_two(x, y);
	test(x == 999999);
	test(y == 1000000);


	Oracle o10;
	for (int i = 3; i <= 1000000; ++i)
		o10.tell(i);
	x = y = 0;
	o10.missing_two(x, y);
	test(x == 1);
	test(y == 2);


	Oracle o11;
	o11.tell(1);
	o11.tell(3);
	for (int i = 5; i <= 1000000; ++i)
		o11.tell(i);
	x = y = 0;
	o11.missing_two(x, y);
	test(x == 2);
	test(y == 4);


	Oracle o12;
	for (int i = 2; i <= 999999; ++i)
		o12.tell(i);
	x = y = 0;
	o12.missing_two(x, y);
	test(x == 1);
	test(y == 1000000);


	Oracle o13;
	m1 = (rand() % 500000) + 1; 
	m2 = (rand() % 500000) + 500001; 
	for (int i = 1; i <= 1000000; ++i)
		if (i != m1 && i != m2)
			o13.tell(i);
	x = y = 0;
	o13.missing_two(x, y);
	test(x == m1);
	test(y == m2);


	Oracle o14;
	m1 = (rand() % 999999) + 1; 
	m2 = (rand() % 1000000) + 1; 
	if (m1 == m2)
		m2 = m1 + 1;
	else if (m1 > m2)
		swap(m1, m2);
	for (int i = 1; i <= 1000000; ++i)
		if (i != m1 && i != m2)
			o14.tell(i);
	x = y = 0;
	o14.missing_two(x, y);
	test(x == m1);
	test(y == m2);


	Oracle o15;
	m1 = (rand() % 500000) + 1; 
	m2 = (rand() % 500000) + 500001; 
	V.clear();
	for (int i = 1; i <= 1000000; ++i)
		if (i != m1 && i != m2)
			V.push_back(i);
	random_shuffle(V.begin(), V.end()); 
	for (int i : V)
		o15.tell(i);        
	x = y = 0;
	o15.missing_two(x, y);
	test(x == m1);
	test(y == m2);


	Oracle o16;
	m1 = (rand() % 999999) + 1; 
	m2 = (rand() % 1000000) + 1; 
	V.clear();
	if (m1 == m2)
		m2 = m1 + 1;
	else if (m1 > m2)
		swap(m1, m2);
	for (int i = 1; i <= 1000000; ++i)
		if (i != m1 && i != m2)
			V.push_back(i);
	random_shuffle(V.begin(), V.end()); 
	for (int i : V)
		o16.tell(i);
	x = y = 0;
	o16.missing_two(x, y);
	test(x == m1);
	test(y == m2);


	cout << "Assignment complete." << endl;
}



