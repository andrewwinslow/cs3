
#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <vector>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

class Autocompleter
{
	// For the mandatory running times below:
	// n is the number of strings in the dictionary.
	// Assume that the length of every string is O(1). 

	public:
		// Creates a new Autocompleter with an empty dictionary.
		//
		// Must run in O(1) time.
		Autocompleter();

		// Adds a string x to the dictionary.
		// If x is already in the dictionary, does nothing.
		//
		// Must run in O(log(n)) time.
		void insert(string x, int freq);

		// Returns the number of strings in the dictionary
		// of possible completions. 
		// 
		// Must run in O(n) time.
		int size();

		// Fills the vector T with the three most-frequent completions of x.
		// If x has less than three completions, then 
		// T is filled with all completions of x.
		// The completions appear in T from most to least frequent.
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

		// A helper class that implements a binary search tree node.
		class Node
		{
			public:
				Node()
				{
					height = -1;
					left = right = nullptr;
				}

				Node(Entry e)
				{
					this->e = e;
					height = -1;
					left = right = nullptr;
				}

				Entry e;
				int height;
				Node* left;
				Node* right;
		};

		// A convenience method for getting the height of a subtree.
		// Useful for rebalance().
		static int height(Node* root)
		{
			if (root == nullptr)
				return -1;
			return root->height;
		}

		// Root of the binary-search-tree-based data structure
		Node* root;


		// Optional helper methods (you'll probably want them)

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

		// Inserts an Entry into an AVL tree rooted at root.
		//
		// Should run in O(log(n)) time.
		void insert_recurse(Entry e, Node* root);

		// Rebalances the AVL tree rooted at root.
		// Helpful for insert(). 
		// Should be called on every node visited during
		// the search in reverse search order.
		// 
		// Should run in O(1) time. 
		void rebalance(Node* root);    

		// Perform left and right rotations around the root
		// of an AVL tree (helpful for implementing rebalance).
		//
		// Should run in O(1) time.
		void right_rotate(Node* root); 
		void left_rotate(Node* root);  
};

#endif

