###############################################################
# Program:
#     Assignment 10, Map
#     Brother Kirby, CS 235
# Author:
#     Tim O'Barr
#     Jessica Smith
#     Ken Smith
# Summary:
#     Implements a mostly successful Map ADT
# Time:
#     Group: 8 Hours
#     Solo: 
#          Tim 10 Hours
#          Jessica 8 Hours
#          Ken 8 Hours
# Hardest Part:
#          Tim: going for 4 hours on one seg fault in find/insert, and tackeled many other errors for the rest of the time
#          Jessica: working out pseudocode to actual code with insert and access.
#          Ken: fixing the BST from last week, so we could get started on this week.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g -std=c++11
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g -std=c++11

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g  -std=c++11
