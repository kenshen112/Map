/***********************************************************************
* Header:
*    MAP
* Summary:
*    This will contain the Map class and it's functions
*    
* Author
*    Jessica Smith
*    Ken Smith
*    Tim O'Barr
************************************************************************/
//don't forget to include the BST class when we are done with it!
#include "pair.h"
#ifndef MAP_H
#define MAP_H

using namespace custom { //not sure if we need the namespace custom?

template <class T>
   class map{

  private:
   BST bst;

  public:
   map();
   map operator=(const map & rhs);
   ~map();

   int size();
   bool empty();
   
   void clear();
   V access(K k);
   void insert(K k, V v);
   void insert(Pair);   
   class iterator;

   iterator find(K k);
   iterator begin();
   iterator end();

};
   
/*****************************************************
 * 
 * 
 * 
 *****************************************************/

}
#endif // MAP_H

