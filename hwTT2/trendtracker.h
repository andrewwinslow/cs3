
#ifndef TRENDTRACKER_H
#define TRENDTRACKER_H

#include <vector>
#include <string>

using namespace std;

class Trendtracker
{
	// For the mandatory running times below:
	// n is the number of hashtags in the Trendtracker.

	public:
		// Creates a new empty collection of hashtags.
		Trendtracker();
	
		// Inserts a hashtag (tweeted 0 times) into the Trendtracker.
		// If the hashtag already is in Trendtracker, does nothing.
		// 
		// Must run in O(log(n)) time if the hashtag is already in 
		// the Trendtracker, and O(n) time otherwise.
		void insert(string ht);

		// Return the number of hashtags in the Trendtracker.
		//
		// Must run in O(1) time.
		int size();

		// Adds 1 to the total number times a hashtag has been tweeted.
		// If the hashtag does not exist in TrendTracker, does nothing.
		//
		// Must run in O(log(n)) time.
		void tweeted(string ht);

		// Returns the number of times a hashtag has been tweeted.
		// If the hashtag does not exist in Trendtracker, returns -1.
		// 
		// Must run in O(log(n)) time.
		int popularity(string name);

		// Returns a most-tweeted hashtag.
		// If the Trendtracker has no hashtags, returns "".
		// 
		// Must run in O(1) time.
		string top_trend();

		// Fills the provided vector with the k most-tweeted hashtags, 
		// in order of most-tweeted-to-least-tweeted.
		// 
		// If there are fewer than k hashtags, then the vector is filled
		// with all hashtags (in most-tweeted-to-least-tweeted order).
		//
		// Must run in O(k) time.
		void trending(int k, vector<string> &T); 

	private: 
		// A simple class representing a hashtag and 
		// the number of times it has been tweeted.
		class Entry
		{
			public:
				string hashtag;
				int pop;
		};

		// Optional helper method.
		// Returns the index in S of the hashtag with the given name. 
		// I.e. the index i such that H[S[i]]->name == name.
		// 
		// Should run in O(log(n)) time.
		int S_index(string ht);

		// Optional helper method to return the lowest index in E
		// containing an Entry with the specified pop.
		// 
		// Should run in O(log(n)) time.
		int lowest_E_index_with_pop(int pop);


		// Stores indices of Entries in E.
		// Sorted lexicographically by hashtag (small-to-large).
		vector<int> S;      

		// Entries sorted by number of tweets (large-to-small).
		vector<Entry> E; 
};

#endif 

