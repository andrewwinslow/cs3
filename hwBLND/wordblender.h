
#ifndef WORDBLENDER_H
#define WORDBLENDER_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class WordBlender
{
	// For the mandatory running times below:
	// 
	// n is the number of words in the provided file.
	// 
	// k is the max_word_count.
	// 
	// Assume that all strings have length O(1).

	public:
		// Constructs a Wordblender that creates blend words 
		// from those provided in the file. The file is promised
		// to have the following format:
		// 
		// word1
		// word2
		// ...
		// wordN
		/
		// where word1 < word2 < ... < wordN
		//
		// Must run in O(nk) time. 
		WordBlender(string filename, int max_word_count);

		// Returns the lexicographically first blend word that:
		// -Starts and ends with the given words
		// -Otherwise consists entirely of words found in filename
		// -Consists of word_count words.
		//
		// If no such blend word exists, returns "". 
		// 
		// Must run in O(1) time. 
		string blend(string first_word, string last_word, int word_count);

	private:
		string** table;
		int max_word_count;
};

#endif

