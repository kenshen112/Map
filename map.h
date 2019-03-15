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
#include "bst.h"
#ifndef MAP_H
#define MAP_H

using namespace custom;

   template <class K, class V>
      class map
   {
      
     private:
      BST <pair<K, V>> *bst;

	  int numElements; // we can either use this or just call BST'S size, Tim.
      
     public:
      //default constructor, all constructor's should be inline in C++ Tim
          map()
          {
             bst = nullptr;
             numElements = 0;
          }
      //copy constructor
          map(const map <K, V> & rhs)
          {
             bst = rhs.bst;
          }
      //assignment operator
          map <K, V> & operator=(const map <K, V> & rhs)
          {
             bst = rhs.bst;
             
             return *this;
          }
      //destructor
	  ~map()
	  {
		  bst = nullptr;
		  numElements = 0;
		  delete bst;
	  }
      
	  int size() const
	  {
		  return numElements;
	  }
	  bool empty() const
	  {
		  return numElements == 0;
	  }
      
          void clear()
          {
             bst.clear();
          }
      
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
 *MAP:ITERATOR
 *The iterator for a map 
 *****************************************************/
template <class T> //T instead of K or V? -Jess
      class map <T> :: iterator
   {
      //trick to this is that basically all of the methods just call
      // the identical method in the BST iterator
     private:
      typename BST <T> :: iterator bsit; // bsit, binary search iterator
      
     public:
      //constructors
      iterator()
      {
         bsit();
      }
      
      iterator(BST <T> :: iterator it)
      {
         this->bsit = it;
      }

         
      iterator(iterator it)
      {
         this->bsit = it.bsit;
      }
      
      //operators: =, ++, --, *, ==, !=
      iterator operator = (const iterator &rhs)
         {
            this->bsit = rhs.bsit;
            return *this;
         }
      
      
      /**************************
       * Increment
       * going up
       ********************/
      iterator operator ++ ()
      {
         bsit++;
         return *this;
      }

      /*********************
       * Decrement
       * going down
       ********************/
      iterator operator -- ()
      {
         bsit--;
         return *this;
      }
   
      /*****************
       * Dereference operator
       * to get to the actual data
       ***************/
      T& operator*()
      {
         return *bsit;
      }

      /******************************
       *Equvalence operator
       * are two iterators pointing to the same thing
       *****************************/
      bool operator == (const iterator it)
      {
         return this->bsit == it.bsit;
      }

      /**************************************
       * NOT equals operator
       * do two iterators point to different things
       *************************************/
      bool operator != (const iterator it)
      {
         return this->bsit != it.bsit;
      }
      
   }

/*************************************
 *ACCESS OPERATOR
 *allows for random access
 ************************************/
template <class K, class V>
V & Map::operator[] (const K & k) throw(const char *)
{
   //I don't have a good grasp on the pseudocode for these yet -Jess
}

/*************************************
 *ACCESS OPERATOR CONST
 *allows for random access
 *************************************/
template <class K, class V>
   V Map::operator[] (const K & k) throw(const char *)
{
   //see above ^^
}

/*************************************
 *INSERT with K,V
 *inserts a new value with a key
 ************************************/
template <class K, class V>
   void Map::insert(const K & k, const V & v) throw(const char *)
{
   //do we need 2 inserts? Maybe I read the book wrong -Jess
}
/************************************
 *INSERT with pair <K, V>
 *inserts a new value using a pair
 ***********************************/
template <class K, class V>
   void Map::insert(const pair <K, V> & input) throw(const char *)
{
   Map::iterator *it = bst.find(input);//please make sure I got this right

   if(it != nullptr)
      *it = input;
   else
      bst.insert(input);
}

#endif // MAP_H

