
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "wordblender.h"

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
	WordBlender W1("eleven-words.txt", 15);

	test(W1.blend("apple", "lefty", 2) == "applefty");
	test(W1.blend("apple", "tyrol", 3) == "appleftyrol");
	test(W1.blend("apple", "olive", 4) == "appleftyrolive");
	test(W1.blend("apple", "vegas", 5) == "appleftyrolivegas");
	test(W1.blend("apple", "ascot", 6) == "appleftyrolivegascot");
	test(W1.blend("apple", "otter", 7) == "appleftyrolivegascotter");
	test(W1.blend("apple", "error", 8) == "appleftyrolivegascotherror");
	test(W1.blend("apple", "orange", 9) == "appleftyrolivegascotherrorange");
	test(W1.blend("apple", "gear", 10) == "appleftyrolivegascotherrorangear");

	test(W1.blend("title", "lefty", 2) == "titlefty");
	test(W1.blend("lefty", "tyrant", 2) == "leftyrant");
	test(W1.blend("olive", "otter", 4) == "olivegascotter");
	test(W1.blend("vegas", "error", 4) == "vegascotherror");
	test(W1.blend("otter", "arcane", 5) == "otterrorangearcane");
	test(W1.blend("kidnap", "olfactory", 5) == "kidnappleftyrolfactory");

	test(W1.blend("swims", "olive", 3) == "");
	test(W1.blend("olive", "ingot", 4) == "");
	test(W1.blend("olive", "otter", 5) == "");
	test(W1.blend("kidnap", "olfactory", 4) == "");
	test(W1.blend("kidnap", "olfactory", 6) == "");


	WordBlender W2("five-letter-words.txt", 4);

	test(W2.blend("salsa", "sauce", 2) == "salsauce");
	test(W2.blend("soggy", "gyros", 2) == "soggyros");
	test(W2.blend("turbo", "boast", 2) == "turboast");
	test(W2.blend("vital", "aloft", 2) == "vitaloft");
	test(W2.blend("witch", "chins", 2) == "witchins");
	test(W2.blend("wagon", "onion", 2) == "wagonion");

	test(W2.blend("zilch", "meows", 3) == "zilchimeows");
	test(W2.blend("gumbo", "champ", 3) == "gumbotchamp");
	test(W2.blend("japan", "elfin", 3) == "japangelfin");
	test(W2.blend("jelly", "ravel", 3) == "jellycravel");
	test(W2.blend("jingo", "taboo", 3) == "jingottaboo");
	test(W2.blend("micro", "gecko", 3) == "microugecko");
	test(W2.blend("kebab", "debug", 3) == "kebabidebug");

	test(W2.blend("latch", "shrub", 4) == "latcheapishrub");
	test(W2.blend("irate", "biome", 4) == "iraterrabbiome");
	test(W2.blend("hoist", "abyss", 4) == "hoistakebabyss");
	test(W2.blend("gulch", "shark", 4) == "gulcheapishark");


	WordBlender W3("six-letter-words.txt", 6);

	test(W3.blend("locate", "animal", 4) == "locatechnormanimal");
	test(W3.blend("smooth", "stolen", 4) == "smoothreadjustolen");
	test(W3.blend("worked", "intent", 4) == "workeditorigintent");
	test(W3.blend("symbol", "amount", 4) == "symboldestreamount");

	test(W3.blend("advise", "desert", 5) == "advisectoriginsidesert");
	test(W3.blend("unable", "secure", 5) == "unablengthreadvisecure");
	test(W3.blend("actual", "define", 5) == "actualmostrainsidefine");
	test(W3.blend("garden", "stones", 5) == "gardensureloadjustones");
	test(W3.blend("refine", "injury", 5) == "refineededitoriginjury");

	test(W3.blend("animal", "medium", 6) == "animalpinevadamagenomedium");
	test(W3.blend("advise", "desert", 6) == "advisectoriginsidecadesert");
	test(W3.blend("config", "genome", 6) == "confignorepeattachangenome");
	test(W3.blend("wooden", "newbie", 6) == "woodengagermanimalpinewbie");
	test(W3.blend("animal", "animal", 6) == "animalmostrainsidebianimal");
	test(W3.blend("animal", "zebras", 6) == "");
	test(W3.blend("verify", "animal", 6) == "");


	cout << "Assignment complete." << endl;
}



