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
#include "pair.h"
#ifndef MAP_H
#define MAP_H

using namespace custom { //not sure if we need the namespace custom?

   template <class K, class V>
      class map{
      
     private:
      BST bst; //not sure how to do this one. They want it as a member variable.
      //I'll need to read up some more on exactly how they want that done. 
      
     public:
      //default constructor
      map();
      //copy constructor
      map(const map <K, V> & rhs);
      //assignment operator
      map <K, V> & operator=(const map <K, V> & rhs);
      //destructor
      ~map();
      
      int size() const;
      bool empty() const;
      
      void clear();
      
      //access functions
      V & operator[] (const K & k) throw(const char *);
      V operator[] (const K & k) const throw(const char *);
      
      void insert(const K & k, const V & v) throw(const char *);
      void insert(const pair <K, V> & input) throw(const char *);   

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

