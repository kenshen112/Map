/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
#include "fstream"     // for ifstream
using namespace std;
void readFile(map <string, Count> & counts, const string & fileName);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   //i need to implement:
   //a prompt
   //a file reader
   //     inserting into the map
   //and interface to find and respond to a word search

   map <string, int> words;

   string fileName;

   std::cout << "Whar is the filename to be counted? ";
   std::cin >> filename;

   readFile(words, fileName);

   string instruction;

   std::cout << "What word while frequency is to be found. Type ! when done\n"
             << "> ";
   
   std::cin >> instruction;
   
   while(instruction != '!')
   {
      typename::map::iterator it;
      it = find(instruction);

      if(it == nullptr)
      {
         std::cout << "\t" << instruction << " : 0\n";
      }
      else
      {
         std::cout << "\t" << instruction << " : " << *it.second << std::endl;
      }
      
      std::cout << "> ";
      std::cin >> instruction;
   }
   
}


void readFile(map <string, Count> & counts, const string & fileName)
{
   ifstream fin(fileName);

   if(fin.fail())
   {
      std::cout << "Error opening file " << fileName << std::endl;
      return;
   }

   string word;
   
   while(fin >> word)
   {
      counts[word] += 1;
   }

   fin.close();
}
