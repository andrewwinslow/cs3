
#include <cassert>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "trendtracker.h"

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
	vector<string> R;
	string s, line;


	// Test size() and insert().
	Trendtracker T1;
	test(T1.size() == 0);
	test(T1.popularity("#algorithms") == -1);
	test(T1.popularity("#cs4all") == -1);
	test(T1.popularity("#programming") == -1);

	T1.insert("#cs4all");
	test(T1.size() == 1);
	test(T1.popularity("#algorithms") == -1);
	test(T1.popularity("#cs4all") == 0);
	test(T1.popularity("#programming") == -1);

	T1.insert("#algorithms");
	test(T1.size() == 2);
	test(T1.popularity("#algorithms") == 0);
	test(T1.popularity("#cs4all") == 0);
	test(T1.popularity("#programming") == -1);

	T1.insert("#programming");
	test(T1.size() == 3);
	test(T1.popularity("#algorithms") == 0);
	test(T1.popularity("#cs4all") == 0);
	test(T1.popularity("#programming") == 0);

        T1.insert("#algorithms");
	test(T1.size() == 3);
	test(T1.popularity("#algorithms") == 0);
	test(T1.popularity("#cs4all") == 0);
	test(T1.popularity("#programming") == 0);

	T1.tweeted("#programming");
	test(T1.popularity("#algorithms") == 0);
	test(T1.popularity("#cs4all") == 0);
	test(T1.popularity("#programming") == 1);

	T1.tweeted("#programming");
	test(T1.popularity("#algorithms") == 0);
	test(T1.popularity("#cs4all") == 0);
	test(T1.popularity("#programming") == 2);

	T1.tweeted("#programming");
	test(T1.popularity("#algorithms") == 0);
	test(T1.popularity("#cs4all") == 0);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#cs4all");
	test(T1.popularity("#algorithms") == 0);
	test(T1.popularity("#cs4all") == 1);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#algorithms");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 1);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#cs4all");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#datastructures");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#datastructures") == -1);
	test(T1.popularity("#programming") == 3);

	T1.insert("#datastructures");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#datastructures") == 0);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#datastructures");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#datastructures") == 1);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#datastructures");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#datastructures") == 2);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#datastructures");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#datastructures") == 3);
	test(T1.popularity("#programming") == 3);

	T1.tweeted("#datastructures");
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#datastructures") == 4);
	test(T1.popularity("#programming") == 3);


	Trendtracker T2;
	T2.insert("#3333");
	T2.insert("#programming");
	T2.insert("#cs4all");
	T2.insert("#C++");
	T2.insert("#algorithms");
	T2.tweeted("#programming");
	T2.tweeted("#programming");
	T2.tweeted("#programming");
	T2.tweeted("#programming");
	T2.tweeted("#programming");
	T2.tweeted("#C++");
	T2.tweeted("#C++");
	T2.tweeted("#C++");
	T2.tweeted("#C++");
	T2.tweeted("#cs4all");
	T2.tweeted("#cs4all");
	T2.tweeted("#cs4all");
	T2.tweeted("#algorithms");
	T2.tweeted("#algorithms");
	T2.tweeted("#3333");
	test(T2.popularity("#programming") == 5);
	test(T2.popularity("#cs4all") == 3);
	test(T2.popularity("#algorithms") == 2);
	test(T2.popularity("#C++") == 4);
	test(T2.popularity("#3333") == 1);
	T2.insert("#3333");
	T2.insert("#programming");
	T2.insert("#cs4all");
	T2.insert("#C++");
	T2.insert("#algorithms");
	test(T2.popularity("#programming") == 5);
	test(T2.popularity("#cs4all") == 3);
	test(T2.popularity("#algorithms") == 2);
	test(T2.popularity("#C++") == 4);
	test(T2.popularity("#3333") == 1);

        
	// Enforce no usage of global variables
	test(T1.popularity("#algorithms") == 1);
	test(T1.popularity("#cs4all") == 2);
	test(T1.popularity("#datastructures") == 4);
	test(T1.popularity("#programming") == 3);
        

	Trendtracker T3;
	test(T3.top_trend() == ""); 
	T3.trending(1, R);
	test(R.size() == 0);
	T3.trending(2, R);
	test(R.size() == 0);
	T3.trending(3, R);
	test(R.size() == 0);

	T3.insert("#programming");
	test(T3.top_trend() == "#programming"); 
	T3.trending(1, R);
	test(R.size() == 1);
	test(R[0] == "#programming");
	T3.trending(2, R);
	test(R.size() == 1);
	test(R[0] == "#programming");
	T3.trending(3, R);
	test(R.size() == 1);
	test(R[0] == "#programming");

	T3.tweeted("#programming");
	test(T3.top_trend() == "#programming");
	T3.trending(1, R);
	test(R.size() == 1);
	test(R[0] == "#programming");
	T3.trending(2, R);
	test(R.size() == 1);
	test(R[0] == "#programming");
	T3.trending(3, R);
	test(R.size() == 1);
	test(R[0] == "#programming");

	T3.insert("#C++");
	T3.tweeted("#C++");
	T3.tweeted("#C++"); 
	test(T3.top_trend() == "#C++"); 
	T3.trending(1, R);
	test(R.size() == 1);
	test(R[0] == "#C++");
	T3.trending(2, R);
	test(R.size() == 2);
	test(R[0] == "#C++");
	test(R[1] == "#programming");
	T3.trending(3, R);
	test(R.size() == 2);
	test(R[0] == "#C++");
	test(R[1] == "#programming");

	T3.insert("#3333");
	T3.tweeted("#3333");
	T3.tweeted("#3333");
	T3.tweeted("#3333");
	test(T3.top_trend() == "#3333"); 
	T3.trending(1, R);
	test(R.size() == 1);
	test(R[0] == "#3333");
	T3.trending(2, R);
	test(R.size() == 2);
	test(R[0] == "#3333");
	test(R[1] == "#C++");
	T3.trending(3, R);
	test(R.size() == 3);
	test(R[0] == "#3333");
	test(R[1] == "#C++");
	test(R[2] == "#programming");

	T3.insert("#cs4all");
	T3.tweeted("#cs4all");
	T3.tweeted("#cs4all");
	T3.tweeted("#cs4all");
	T3.tweeted("#cs4all");
	test(T3.top_trend() == "#cs4all");
	T3.trending(1, R);
	test(R.size() == 1);
	test(R[0] == "#cs4all");
	T3.trending(2, R);
	test(R.size() == 2);
	test(R[0] == "#cs4all");
	test(R[1] == "#3333");
	T3.trending(3, R);
	test(R.size() == 3);
	test(R[0] == "#cs4all");
	test(R[1] == "#3333");
	test(R[2] == "#C++");
        
	// At this point:
	// cs4all: 4
	// 3333: 3
	// C++: 2
	// programming: 1

	T3.tweeted("#programming");
	T3.tweeted("#programming");
	T3.tweeted("#programming");
	T3.tweeted("#programming");
	test(T3.top_trend() == "#programming");
	T3.trending(5, R);
	test(R.size() == 4);
	test(R[0] == "#programming");
	test(R[1] == "#cs4all");
	test(R[2] == "#3333");
	test(R[3] == "#C++");

	// At this point:
	// programming: 5
	// cs4all: 4
	// 3333: 3
	// C++: 2

	T3.tweeted("#cs4all");
	T3.tweeted("#cs4all");
	T3.tweeted("#3333");
	test(T3.top_trend() == "#cs4all");
	T3.trending(5, R);
	test(R.size() == 4);
	test(R[0] == "#cs4all");
	test(R[1] == "#programming");
	test(R[2] == "#3333");
	test(R[3] == "#C++");
	 
	// At this point:
	// cs4all: 6
	// programming: 5
	// 3333: 4
	// C++: 2

	for (int i = 0; i < 10000; ++i)
		T3.tweeted("#C++");
	test(T3.top_trend() == "#C++");
	T3.trending(5, R);
	test(R.size() == 4);
	test(R[0] == "#C++");
	test(R[1] == "#cs4all");
	test(R[2] == "#programming");
	test(R[3] == "#3333");


		
	// Tests with large data
	Trendtracker T4;

	// Test insert() 
	ifstream f;
	f.open("common.txt");
	assert(f.is_open()); // If this fails, you're missing common.txt
	while (getline(f, line))
		T4.insert(line);
	f.close();
	test(T4.size() == 3597); 

	// Test tweeted() 
	f.open("common.txt");
	while (getline(f, line))
		T4.tweeted(line);
	f.close();

	// Test popularity() 
	f.open("common.txt");
	for (int i = 0; i < 1000; ++i)
	{	
		getline(f, line);
		test(T4.popularity(line) > 0);
	}
	f.close();

	// Test top_trend() 
	for (int i = 0; i < 1000; ++i)
		test(T4.top_trend() == "#finishing");

	// Test trending() 
	for (int i = 0; i < 1000; ++i)
		T4.trending(10, R);
	test(R[0] == "#finishing");
	test(R[1] == "#discovering");

	for (int i = 0; i < 100; ++i)
		T4.trending(1000, R);
	test(R[0] == "#finishing");
	test(R[1] == "#discovering");


	cout << "Assignment complete." << endl;
}



