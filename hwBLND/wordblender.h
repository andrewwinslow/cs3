
#ifndef WORDBLENDER_H
#define WORDBLENDER_H

#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class WordBlender
{
        // For the running times below,
	// assume that all strings have length O(1).

	public:
		// Constructs a Wordblender that creates blend words 
		// from those provided in the file. The file is promised
		// to have the following format:
		// 
		// word1
		// word2
		// ...
		// wordN
		//
		// where word1 < word2 < ... < wordN
		//
		// Must run in O(nk) time, where:
                // n is the number of words in the file
                // k equals max_word_count 
		WordBlender(string filename, int max_word_count);

		// Returns a blend word that:
		// -Starts and ends with the given words
		// -Otherwise consists entirely of words found in filename
		// -Consists of word_count total words.
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

