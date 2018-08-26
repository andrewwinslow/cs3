
#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <vector>
#include <string>
#include <cassert>
#include <fstream>

using namespace std;

class Autocompleter
{
	// For the mandatory running times below:
	// n is the number of strings in the dictionary.
	// Assume that the length of every string is O(1). 

	public:
		// Creates a dictionary of strings and associated frequencies,
		// using the file as a source. The file is promised to have
		// the following format:
		// 
		// string1 freq1
		// string2 freq2
		// ...
		// stringN freqN
		//
		// where string1 < string2 < ... < stringN 
		// 
		// Must run in O(n) time.
		Autocompleter(string filename);

		// Returns the number of strings in the dictionary
		// of possible completions. 
		// 
		// Must run in O(n) time.
		int size();

                // Fills the vector T with the three most-frequent completions of x.
                // If x has less than three completions, 
		// then T is filled with all completions of x.
                // The completions appear in T from most- to least-frequent.
                // 
                // Must run in O(log(n) + k) time,
		// where k is the number of completions of x in the dictionary.
                void completions(string x, vector<string> &T);

	private:
		// A helper class that stores a string and a frequency.
		class Entry
		{
			public:
				string s;
				int freq; 
		};

		// A helper class that implements a BST node.
		class Node
		{
			public:
                                Node()
                                {
                                        left = right = nullptr;
                                }

                                Node(Entry e)
                                {
                                        this->e = e;
                                        left = right = nullptr;
                                }

				Entry e;
				Node* left;
				Node* right;
		};

		// Root of the binary-search-tree-based data structure
		Node* root;

		// Optional helper methods (you'll probably want them).

		// Returns the root of a BST containing the elements
		// of the portion of a sorted vector E from index l to r.
		//
		// Should run in O(r-l) time.
		Node* construct_recurse(vector<Entry> &E, int l, int r);

		// Returns the size of the binary tree rooted at root.
		//
		// Should run in O(n) time.
		int size_recurse(Node* root);

		// Fills T with the three most-frequent completions of x
		// that are either:
		// -In the BST rooted at root.
		// -Already in T.
		//
		// Should run in O(log(n) + k), where
		// -n is the size of the BST rooted at root.
		// -k is the number of Entrys in the BST rooted at root
		//  whose strings start with x.
                void completions_recurse(string x, Node* root, vector<Entry> &T);
};


#endif

