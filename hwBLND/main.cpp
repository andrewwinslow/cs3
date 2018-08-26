
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include "wordblender.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
	abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


void populate_dictionary(unordered_set<string> &dictionary, string filename)
{
        dictionary.clear();

        ifstream f(filename);
        string line;
        while (getline(f, line))
                dictionary.insert(line);                
        f.close();
}

int is_blend(string s, string first, string last, unordered_set<string> &dictionary)
{
        if (s.find(first) != 0)
                return -1;
        if (s.find_last_of(last) != s.length() - 1)
                return -1;
        int word_count = 0;
        s.erase(s.length() - last.length() + 2, last.length());
        ++word_count;
        while (s.length() > first.length())
        {
                int i = s.length()-1;
                while (i >= 0)
                {
                        string suffix = s.substr(i, s.length());
                        if (dictionary.find(suffix) != dictionary.end())
                        {
                                s.erase(i+2, s.length());
                                ++word_count;
                                break;
                        }
                        --i;
                }
                if (i == -1)
                        return -1;
        }  
        if (s != first)
                return -1;
        ++word_count;
        return word_count;
}


int main()
{
        // Setup 
        unordered_set<string> D;


        // Setup testing for W1
        populate_dictionary(D, "eleven-words.txt");

	WordBlender W1("eleven-words.txt", 15);
	test(is_blend(W1.blend("apple", "lefty", 2), "apple", "lefty", D) == 2);
	test(is_blend(W1.blend("apple", "tyrol", 3), "apple", "tyrol", D) == 3);
	test(is_blend(W1.blend("apple", "olive", 4), "apple", "olive", D) == 4);
	test(is_blend(W1.blend("apple", "vegas", 5), "apple", "vegas", D) == 5);
	test(is_blend(W1.blend("apple", "ascot", 6), "apple", "ascot", D) == 6);
	test(is_blend(W1.blend("apple", "otter", 7), "apple", "otter", D) == 7);
	test(is_blend(W1.blend("apple", "error", 8), "apple", "error", D) == 8);
	test(is_blend(W1.blend("apple", "orange", 9), "apple", "orange", D) == 9);
	test(is_blend(W1.blend("apple", "gear", 10), "apple", "gear", D) == 10);
	test(is_blend(W1.blend("title", "lefty", 2), "title", "lefty", D) == 2);
	test(is_blend(W1.blend("lefty", "tyrant", 2), "lefty", "tyrant", D) == 2);
	test(is_blend(W1.blend("olive", "otter", 4), "olive", "otter", D) == 4);
	test(is_blend(W1.blend("vegas", "error", 4), "vegas", "error", D) == 4);
	test(is_blend(W1.blend("otter", "arcane", 5), "otter", "arcane", D) == 5);
	test(is_blend(W1.blend("kidnap", "olfactory", 5), "kidnap", "olfactory", D) == 5);
	test(W1.blend("swims", "olive", 3) == "");
	test(W1.blend("olive", "ingot", 4) == "");
	test(W1.blend("olive", "otter", 5) == "");
	test(W1.blend("kidnap", "olfactory", 4) == "");
	test(W1.blend("kidnap", "olfactory", 6) == "");

        
        // Setup testing for W2
        populate_dictionary(D, "five-letter-words.txt");

	WordBlender W2("five-letter-words.txt", 4);
        test(is_blend(W2.blend("salsa", "sauce", 2), "salsa", "sauce", D) == 2);
        test(is_blend(W2.blend("soggy", "gyros", 2), "soggy", "gyros", D) == 2);
        test(is_blend(W2.blend("turbo", "boast", 2), "turbo", "boast", D) == 2);
        test(is_blend(W2.blend("vital", "aloft", 2), "vital", "aloft", D) == 2);
        test(is_blend(W2.blend("witch", "chins", 2), "witch", "chins", D) == 2);
        test(is_blend(W2.blend("wagon", "onion", 2), "wagon", "onion", D) == 2);

        test(is_blend(W2.blend("zilch", "meows", 3), "zilch", "meows", D) == 3);
        test(is_blend(W2.blend("gumbo", "champ", 3), "gumbo", "champ", D) == 3);
        test(is_blend(W2.blend("japan", "elfin", 3), "japan", "elfin", D) == 3);
        test(is_blend(W2.blend("jelly", "ravel", 3), "jelly", "ravel", D) == 3);
        test(is_blend(W2.blend("jingo", "taboo", 3), "jingo", "taboo", D) == 3);
        test(is_blend(W2.blend("micro", "gecko", 3), "micro", "gecko", D) == 3);
        test(is_blend(W2.blend("kebab", "debug", 3), "kebab", "debug", D) == 3);

        test(is_blend(W2.blend("latch", "shrub", 4), "latch", "shrub", D) == 4);
        test(is_blend(W2.blend("irate", "biome", 4), "irate", "biome", D) == 4);
        test(is_blend(W2.blend("hoist", "abyss", 4), "hoist", "abyss", D) == 4);
        test(is_blend(W2.blend("gulch", "shark", 4), "gulch", "shark", D) == 4);


        // Setup testing for W3
        populate_dictionary(D, "six-letter-words.txt");

	WordBlender W3("six-letter-words.txt", 6);
        test(is_blend(W3.blend("locate", "animal", 4), "locate", "animal", D) == 4);
        test(is_blend(W3.blend("smooth", "stolen", 4), "smooth", "stolen", D) == 4);
        test(is_blend(W3.blend("worked", "intent", 4), "worked", "intent", D) == 4);
        test(is_blend(W3.blend("symbol", "amount", 4), "symbol", "amount", D) == 4);
        test(is_blend(W3.blend("advise", "desert", 5), "advise", "desert", D) == 5);
        test(is_blend(W3.blend("unable", "secure", 5), "unable", "secure", D) == 5);
        test(is_blend(W3.blend("actual", "define", 5), "actual", "define", D) == 5);
        test(is_blend(W3.blend("garden", "stones", 5), "garden", "stones", D) == 5);
        test(is_blend(W3.blend("refine", "injury", 5), "refine", "injury", D) == 5);
        test(is_blend(W3.blend("animal", "medium", 6), "animal", "medium", D) == 6);
        test(is_blend(W3.blend("advise", "desert", 6), "advise", "desert", D) == 6);
        test(is_blend(W3.blend("config", "genome", 6), "config", "genome", D) == 6);
        test(is_blend(W3.blend("wooden", "newbie", 6), "wooden", "newbie", D) == 6);
        test(is_blend(W3.blend("animal", "animal", 6), "animal", "animal", D) == 6);
	test(W3.blend("animal", "zebras", 6) == "");
	test(W3.blend("verify", "animal", 6) == "");


	cout << "Assignment complete." << endl;
}



