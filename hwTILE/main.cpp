
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
	srand('f' + 2018);
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

	floor = "";
	floor += "##################################################\n";
	floor += "#                      ###########################\n";
	floor += "##################################################\n";
	floor += "#                       ##########################\n";
	floor += "##################################################\n";
	floor += "#                        #########################\n";
	floor += "##################################################\n";
	test(!has_tiling(floor));

	floor = "";
	floor += "##################################################\n";
	floor += "#                      ###########################\n";
	floor += "##################################################\n";
	floor += "#                          #######################\n";
	floor += "##################################################\n";
	floor += "#                        #########################\n";
	floor += "##################################################\n";
	test(has_tiling(floor));

	for (int i = 0; i < 100; ++i)
	{
		bool tileable = true;

		floor = "";
		floor += "##################################################\n";
		for (int j = 0; j < 50; ++j)
		{
			string floor_row("#"); 
			int l = rand() % 48;
			tileable = tileable && ((l % 2) == 0);
			for (int k = 0; k < l; ++k)		
				floor_row += ' ';	
			for (int k = 1+l; k < 50; ++k)		
				floor_row += '#';	
			floor_row += "\n";	
			floor += floor_row;
			floor += "##################################################\n";

		}		

		test(has_tiling(floor) == tileable);
	}	
	
	floor = "";
	floor += "##################################################\n";
	floor += "###  ###########  ###  ######  #####    ####  ####\n";
	floor += "#  ###  ###  ####  ########  ######  #######  ####\n";
	floor += "#####  #########  ######  ###########  ###  ######\n";
	floor += "##################################################\n";
	test(has_tiling(floor));

	floor = "";
	floor += "##################################################\n";
	floor += "###  ###########  ###  ######  #####    ####  ####\n";
	floor += "#  ###  ###  ####  #######   ######  #######  ####\n";
	floor += "#####  #########  ######  ###########  ###  ######\n";
	floor += "##################################################\n";
	test(!has_tiling(floor));

	for (int i = 0; i < 100; ++i)
	{
		floor = "";
		for (int j = 0; j < 50; ++j)
			floor += "##################################################\n";

		for (int j = 0; j < 100; ++j)
		{
			int row = (rand() % 48) + 1;
			int col = (rand() % 47) + 1;
			int loc = 51*row + col;

			if (floor[loc] == ' ' || floor[loc+1] == ' ')
				continue;	

			floor[loc] = ' ';
			floor[loc+1] = ' ';
		}		

		bool tileable = rand() % 2;
		if (!tileable)
		{
			while (true)
			{
				int row = (rand() % 48) + 1;
				int col = (rand() % 48) + 1;
				int loc = 51*row + col;
				if (floor[loc] == ' ')
					continue;
				floor[loc] = ' ';
			}
		}
		cout << floor << endl << endl;
		cout << has_tiling(floor) << " " << tileable << endl;
		test(has_tiling(floor) == tileable);
	}	


	cout << "Assignment complete." << endl;
}



