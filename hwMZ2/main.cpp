
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


	// Test a few mazes without portals 

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



	// Test mazes with portals  

	maze = "";
	maze += "### #\n";
	maze += "#1#1#\n";
	maze += "# ###\n";
	soln = "";
	soln += "###o#\n";
	soln += "#o#o#\n";
	soln += "#o###\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += " 1##1 \n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "oo##oo\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += " 1  1 \n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "oo  oo\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += "  1#2 \n";
	maze += "# ####\n";
	maze += "# 2#1#\n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "oo1#oo\n";
	soln += "#o####\n";
	soln += "#oo#1#\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "# ######\n";
	maze += "#  1  2#\n";
	maze += "########\n";
	maze += "#12    #\n";
	maze += "### ####\n";
	soln = "";
	soln += "#o######\n";
	soln += "#ooo  2#\n";
	soln += "########\n";
	soln += "#ooo   #\n";
	soln += "###o####\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += " 5# 3 \n";
	maze += "######\n";
	maze += "#5  3#\n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "oo# oo\n";
	soln += "######\n";
	soln += "#oooo#\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "########\n";
	maze += "  0  0  \n";
	maze += "#      #\n";
	maze += "########\n";
	soln = "";
	soln += "########\n";
	soln += "ooo  ooo\n";
	soln += "#      #\n";
	soln += "########\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "########\n";
	maze += "  9  9  \n";
	maze += "#      #\n";
	maze += "########\n";
	soln = "";
	soln += "########\n";
	soln += "oooooooo\n";
	soln += "#      #\n";
	soln += "########\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "########\n";
	maze += "  9  9  \n";
	maze += "#0    0#\n";
	maze += "########\n";
	soln = "";
	soln += "########\n";
	soln += "oo9  9oo\n";
	soln += "#o    o#\n";
	soln += "########\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += "  98  \n";
	maze += "# 89 #\n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "oooooo\n";
	soln += "# 89 #\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += "1 ## 1\n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "o ## o\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += "0 ## 0\n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "o ## o\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += "6    6\n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "oooooo\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "######\n";
	maze += "4    4\n";
	maze += "######\n";
	soln = "";
	soln += "######\n";
	soln += "o    o\n";
	soln += "######\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "##########\n";
	maze += "# 2#2 6#6#\n";
	maze += "  ######  \n";
	maze += "# 3#3 4#4#\n";
	maze += "##########\n";
	soln = "";
	soln += "##########\n";
	soln += "# 2#2 6#6#\n";
	soln += "oo######oo\n";
	soln += "#oo#ooo#o#\n";
	soln += "##########\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "##########\n";
	maze += "# 2#2 6#6#\n";
	maze += "  ### ##  \n";
	maze += "# 3#3 4#4#\n";
	maze += "##########\n";
	soln = "";
	soln += "##########\n";
	soln += "# 2#2 6#6#\n";
	soln += "oo### ##oo\n";
	soln += "#oo#ooo#o#\n";
	soln += "##########\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "#### ####\n";
	maze += "# 6  ####\n";
	maze += "####   0#\n";
	maze += "#### ## #\n";
	maze += "#### ## #\n";
	maze += "#0     6#\n";
	maze += "#### ####\n";
	soln = "";
	soln += "####o####\n";
	soln += "# 6 o####\n";
	soln += "####o  0#\n";
	soln += "####o## #\n";
	soln += "####o## #\n";
	soln += "#0  o  6#\n";
	soln += "####o####\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "#### ####\n";
	maze += "# 0  ####\n";
	maze += "####   6#\n";
	maze += "#### ## #\n";
	maze += "#### ## #\n";
	maze += "#6   0  #\n";
	maze += "#### ####\n";
	soln = "";
	soln += "####o####\n";
	soln += "# ooo####\n";
	soln += "####   6#\n";
	soln += "#### ## #\n";
	soln += "#### ## #\n";
	soln += "#6  oo  #\n";
	soln += "####o####\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "##############\n";
	maze += "# 3        3 #\n";
	maze += "# ########## #\n";
	maze += "              \n";
	maze += "# ########## #\n";
	maze += "#  0      0  #\n";
	maze += "##############\n";
	soln = "";
	soln += "##############\n";
	soln += "# 3        3 #\n";
	soln += "# ########## #\n";
	soln += "oo          oo\n";
	soln += "#o##########o#\n";
	soln += "#ooo      ooo#\n";
	soln += "##############\n";
	test(solve(maze) == soln);

	maze = "";
	maze += "# ######################################\n";
	maze += "#   ###     ##                      ## #\n";
	maze += "### ### ### #  ###### ######## #  # #  #\n";
	maze += "# #    7# #7##      #        # #### # ##\n";
	maze += "# ####### # ##### # # ###### # #       #\n";
	maze += "#         #     # # #      # # #  ##   #\n";
	maze += "# ### ### ##### # # ######## # #####   #\n";
	maze += "# ### #    5#   ###          # ##    ###\n";
	maze += "#     # ### #4######## #######  # #### #\n";
	maze += "# # # # ### #          ##    ## # ## # #\n";
	maze += "# # # #     ########## #   #### # ## # #\n";
	maze += "# # ##### #    4 5  3# ### #    #      #\n";
	maze += "# #    ## #######  # #3#      #1### ####\n";
	maze += "# #### ##   # # #### # #####  #   # #  #\n";
	maze += "# ## ## ###       ## #  2    ## # # # ##\n";
	maze += "## # #  ###### ## ## ####### ##1# # # ##\n";
	maze += "#  # #       # ##         2            #\n";
	maze += "###################################### #\n";
	soln = "";
	soln += "#o######################################\n";
	soln += "#ooo###     ##                      ## #\n";
	soln += "###o### ### #  ###### ######## #  # #  #\n";
	soln += "# #ooooo# #o##      #        # #### # ##\n";
	soln += "# ####### #o##### # # ###### # #       #\n";
	soln += "#         #ooooo# # #      # # #  ##   #\n";
	soln += "# ### ### #####o# # ######## # #####   #\n";
	soln += "# ### #    5#ooo###          # ##    ###\n";
	soln += "#     # ### #o######## #######  # #### #\n";
	soln += "# # # # ### #          ##    ## # ## # #\n";
	soln += "# # # #     ########## #   #### # ## # #\n";
	soln += "# # ##### #    oooooo# ### #    #      #\n";
	soln += "# #    ## #######  # #o#      #1### ####\n";
	soln += "# #### ##   # # #### #o#####  #   # #  #\n";
	soln += "# ## ## ###       ## #ooo    ## # # # ##\n";
	soln += "## # #  ###### ## ## ####### ##1# # # ##\n";
	soln += "#  # #       # ##         ooooooooooooo#\n";
	soln += "######################################o#\n";
	test(solve(maze) == soln);


	cout << "Assignment complete." << endl;
}



