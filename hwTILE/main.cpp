
#include <iostream>
#include <cstdlib>
#include <vector>
#include "tiling.h"

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
	string floor;
	

	floor = "";
	floor += "######\n";        
	floor += "#    #\n";        
	floor += "######\n";        
	test(has_tiling(floor));

	floor = "";
	floor += "#######\n";        
	floor += "#     #\n"; 
	floor += "#######\n";        
	test(!has_tiling(floor));

	floor = "";
	floor += "########\n"; 
	floor += "#      #\n"; 
	floor += "########\n";        
	test(has_tiling(floor));

	floor = "";
	floor += "###\n"; 
	floor += "# #\n";        
	floor += "# #\n";        
	floor += "###\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "###\n"; 
	floor += "# #\n";        
	floor += "# #\n";        
	floor += "# #\n";        
	floor += "###\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "###\n"; 
	floor += "# #\n";        
	floor += "# #\n";        
	floor += "# #\n";        
	floor += "# #\n";        
	floor += "###\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "####\n"; 
	floor += "#  #\n";        
	floor += "#  #\n";        
	floor += "####\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "####\n"; 
	floor += "#  #\n";        
	floor += "# ##\n";        
	floor += "####\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "#####\n"; 
	floor += "# # #\n";        
	floor += "# # #\n";        
	floor += "#####\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "#####\n"; 
	floor += "## ##\n";        
	floor += "#   #\n";        
	floor += "## ##\n"; 
	floor += "#####\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "######\n"; 
	floor += "###  #\n";        
	floor += "##  ##\n";        
	floor += "#  ###\n"; 
	floor += "######\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "######\n"; 
	floor += "# #  #\n";        
	floor += "#    #\n";        
	floor += "#  # #\n"; 
	floor += "######\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "######\n"; 
	floor += "###  #\n";        
	floor += "#    #\n";        
	floor += "#  # #\n"; 
	floor += "######\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "#######\n"; 
	floor += "#     #\n";        
	floor += "###  ##\n";        
	floor += "#### ##\n"; 
	floor += "#######\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "#######\n"; 
	floor += "##   ##\n";        
	floor += "###  ##\n";        
	floor += "##   ##\n"; 
	floor += "#######\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "#######\n";
	floor += "##   ##\n";
	floor += "## # ##\n"; 
	floor += "##   ##\n";
	floor += "#######\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "##########\n";
	floor += "##      ##\n";
	floor += "#  #  #  #\n"; 
	floor += "##      ##\n";
	floor += "##########\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "#########\n";
	floor += "##     ##\n";
	floor += "#  # #  #\n"; 
	floor += "##     ##\n";
	floor += "#########\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "##########\n";
	floor += "##      ##\n";
	floor += "## #  # ##\n"; 
	floor += "##      ##\n";
	floor += "##########\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "############\n";
	floor += "##   #   # #\n";
	floor += "## # # # # #\n"; 
	floor += "#  #   #   #\n";
	floor += "############\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "############\n";
	floor += "##   #   ###\n";
	floor += "## # # # # #\n"; 
	floor += "#  #   #   #\n";
	floor += "############\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "############\n";
	floor += "#          #\n";
	floor += "#          #\n"; 
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "############\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "############\n";
	floor += "##         #\n";
	floor += "#          #\n"; 
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#         ##\n";
	floor += "############\n"; 
	test(!has_tiling(floor));

	floor = "";
	floor += "############\n";
	floor += "##         #\n";
	floor += "#          #\n"; 
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "##         #\n";
	floor += "############\n"; 
	test(has_tiling(floor));

	floor = "";
	floor += "############\n";
	floor += "#####  #####\n";
	floor += "####    ####\n"; 
	floor += "###      ###\n";
	floor += "##        ##\n";
	floor += "#          #\n";
	floor += "#          #\n";
	floor += "##        ##\n";
	floor += "###      ###\n";
	floor += "####    ####\n";
	floor += "#####  #####\n";
	floor += "############\n";
	test(has_tiling(floor));

	floor = "";
	floor += "############\n";
	floor += "#####  #####\n";
	floor += "####    ####\n"; 
	floor += "###      ###\n";
	floor += "##        ##\n";
	floor += "##         #\n";
	floor += "#         ##\n";
	floor += "##        ##\n";
	floor += "###      ###\n";
	floor += "####    ####\n";
	floor += "#####  #####\n";
	floor += "############\n";
	test(!has_tiling(floor));

	floor = "";
	floor += "##########\n";
	floor += "#   ######\n";
	floor += "#    #####\n"; 
	floor += "#      ###\n";
	floor += "## #    ##\n";
	floor += "##      ##\n";
	floor += "###     ##\n";
	floor += "####   ###\n";
	floor += "##########\n";
	test(!has_tiling(floor));


	cout << "Assignment complete." << endl;
}



