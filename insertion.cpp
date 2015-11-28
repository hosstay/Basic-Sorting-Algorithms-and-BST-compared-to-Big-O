/*****************************************************************************
Taylor Hoss
X432Z869
Program #10

This is a program that implements four sorting algoritms and a binary search
tree. It will generate data sets of 100, 500, and 1000 via arrays using a
datatype that holds a key to be sorted by and a value that acts as a
placeholder for data. As each sort goes through each data set it tells how
many iterations it went through to get to the sorted list. Also when
the data is added to the binary search tree and later transversed in-order
it gives iteration counts as well. All of these iteration counts can be
compared to the Big-O worst-case calculations.

*****************************************************************************/

#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>

#endif //IOSTREAM

#ifndef SORT_DATA_CPP
#define SORT_DATA_CPP

#include "sort_data.cpp"

#endif //SORT_DATA_CPP

#ifndef FSTREAM
#define FSTREAM

#include <fstream>

#endif //FSTREAM

#ifndef STRING
#define STRING

#include <string>

#endif //STRING

#ifndef NAMESPACE_STD
#define NAMESPACE_STD

using namespace std;

#endif //NAMESPACE_STD

//function that implements the insertion sort algorithm
void insertionSort(sort_data sortAry[], int n)
{
   int iter = 0;
   int j = 0;
   sort_data swap;

   //walks from 0 to end and inserts each into current line
   for (int i = 0; i < n; i++)
   {
      j = i;
      //moves smaller value down the list until its in its right position
      while (j > 0 && sortAry[j].key < sortAry[j - 1].key)
      {
         swap = sortAry[j - 1];
         sortAry[j - 1] = sortAry[j];
         sortAry[j] = swap;

         j = j - 1;

         iter++;
      }
   }

   cout << "Insertion Sort Iterations: " << iter << endl;
}