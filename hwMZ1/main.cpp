
#include <iostream>
#include <cstdlib>
#include <string>
#include "solve.h"

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
	string maze, soln;


	maze = "";
	maze += "##### #\n";
	maze += "#     #\n";
	maze += "# #####\n";
	soln = "";
	soln += "#####o#\n";
	soln += "#ooooo#\n";
	soln += "#o#####\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "##### #\n";
	maze += "#   # #\n";
	maze += "# # # #\n";
	maze += "# #   #\n";
	maze += "# #####\n";
	soln = "";
	soln += "#####o#\n";
	soln += "#ooo#o#\n";
	soln += "#o#o#o#\n";
	soln += "#o#ooo#\n";
	soln += "#o#####\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "########\n";
	maze += "#      #\n";
	maze += "# ## ###\n";
	maze += "#      #\n";
	maze += "## ## ##\n";
	maze += "#  ##  #\n";
	maze += "## ### #\n";
	maze += "## ### #\n";
	soln = "";
	soln += "########\n";
	soln += "#      #\n";
	soln += "# ## ###\n";
	soln += "# oooo #\n";
	soln += "##o##o##\n";
	soln += "# o##oo#\n";
	soln += "##o###o#\n";
	soln += "##o###o#\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "########\n";
	maze += "#  #    \n";
	maze += "# ## ###\n";
	maze += "#      #\n";
	maze += "# # # ##\n";
	maze += "# ###  #\n";
	maze += "#  ### #\n";
	maze += "## #####\n";
	soln = "";
	soln += "########\n";
	soln += "#  #oooo\n";
	soln += "# ##o###\n";
	soln += "#oooo  #\n";
	soln += "#o# # ##\n";
	soln += "#o###  #\n";
	soln += "#oo### #\n";
	soln += "##o#####\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "# ######\n";
	maze += "#  #   #\n";
	maze += "# ## ###\n";
	maze += "#      #\n";
	maze += "# # # ##\n";
	maze += "# ###  #\n";
	maze += "#  ###  \n";
	maze += "########\n";
	soln = "";
	soln += "#o######\n";
	soln += "#o #   #\n";
	soln += "#o## ###\n";
	soln += "#ooooo #\n";
	soln += "# # #o##\n";
	soln += "# ###oo#\n";
	soln += "#  ###oo\n";
	soln += "########\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "########\n";
	maze += "#      #\n";
	maze += "#      #\n";
	maze += "#      #\n";
	maze += "## ## ##\n";
	maze += "## ##  #\n";
	maze += "## ### #\n";
	soln = "";
	soln += "########\n";
	soln += "#      #\n";
	soln += "#      #\n";
	soln += "# oooo #\n";
	soln += "##o##o##\n";
	soln += "##o##oo#\n";
	soln += "##o###o#\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "#########################################################\n";
	maze += "#     #        #  #  #     #  #  #        #     #       #\n";
	maze += "  ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##  \n";
	maze += "#  #     #  #           #           #  #     #     #  # #\n";
	maze += "#########################################################\n";
	soln = "";
	soln += "#########################################################\n";
	soln += "#oooo #ooooooo #  #  #oooo #  #  #ooooooo #oooo #ooooooo#\n";
	soln += "oo##o##o## ##o## ## ##o##o## ## ##o## ##o##o##o##o## ##oo\n";
	soln += "#  #oooo #  #oooooooooo #oooooooooo #  #oooo #oooo #  # #\n";
	soln += "#########################################################\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "# ######################################\n";
	maze += "#   ###     ##                      ## #\n";
	maze += "### ### ### #  ###### ######## #  # #  #\n";
	maze += "# #     # # ##      #        # #### # ##\n";
	maze += "# ####### # ##### # # ###### # #       #\n";
	maze += "#         #     # # #      # # #  ##   #\n";
	maze += "# ### ### ##### # # ######## # #####   #\n";
	maze += "# ### #     #   ###          # ##    ###\n";
	maze += "#     # ### # ######## #######  # #### #\n";
	maze += "# # # # ### #          ##    ## # ## # #\n";
	maze += "# # # #     ########## #   #### # ## # #\n";
	maze += "# # ##### #          # ### #    #      #\n";
	maze += "# #    ## #######  # # #      # ### ####\n";
	maze += "# #### ##   # # #### # #####  #   # #  #\n";
	maze += "# ## ## ###       ## #       ## # # # ##\n";
	maze += "## # #  ###### ## ## ####### ## # # # ##\n";
	maze += "#  # #       # ##                      #\n";
	maze += "###################################### #\n";
	soln = "";
	soln += "#o######################################\n";
	soln += "#ooo###ooooo##                      ## #\n";
	soln += "###o###o###o#  ###### ######## #  # #  #\n";
	soln += "# #ooooo# #o##      #        # #### # ##\n";
	soln += "# ####### #o##### # # ###### # #       #\n";
	soln += "#         #ooooo# # #      # # #  ##   #\n";
	soln += "# ### ### #####o# # ######## # #####   #\n";
	soln += "# ### #     #ooo###          # ##    ###\n";
	soln += "#     # ### #o######## #######  # #### #\n";
	soln += "# # # # ### #oooooooooo##    ## # ## # #\n";
	soln += "# # # #     ##########o#   #### # ## # #\n";
	soln += "# # ##### #          #o### #    #      #\n";
	soln += "# #    ## #######  # #o#      # ### ####\n";
	soln += "# #### ##   # # #### #o#####  #   # #  #\n";
	soln += "# ## ## ###       ## #ooooooo## # # # ##\n";
	soln += "## # #  ###### ## ## #######o## # # # ##\n";
	soln += "#  # #       # ##           ooooooooooo#\n";
	soln += "######################################o#\n";
	test(solve(maze) == soln);


	cout << "Assignment complete." << endl;
}



