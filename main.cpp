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

#include <cstdlib>
#include <ctime>

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

#include "selection.cpp"
#include "insertion.cpp"
#include "bubble.cpp"
#include "quick.cpp"
#include "bst.cpp"

//function prototypes for simple data manipulation 
void fill_array(sort_data sortAry[], int n);
void print_quick_sort(sort_data Ary[], int n);
void print_bubble_sort(sort_data Ary[], int n);
void print_ins_sort(sort_data Ary[], int n);
void print_sel_sort(sort_data Ary[], int n);

int main(void)
{
   int iter = 0;

	//create arrays
	sort_data sortAry1[100];
	sort_data sortAry5[500];
	sort_data sortAry10[1000];

	//initialize random seed
	srand(time(NULL));

   /* LIST 100 */
   //output
   cout << "List 100\n\n";
   cout << "Big - O calculated value for n^2: " << (100 * 100) << "\n";
   
   //creating arrays
   fill_array(sortAry1, 100);
   sort_data selAry1[100];
   sort_data insAry1[100];
   sort_data bubAry1[100];
   sort_data quickAry1[100];

   copy(sortAry1, sortAry1 + 100, selAry1);
   copy(sortAry1, sortAry1 + 100, insAry1);
   copy(sortAry1, sortAry1 + 100, bubAry1);
   copy(sortAry1, sortAry1 + 100, quickAry1);

   //selection
   selectionSort(selAry1, 100);
   print_sel_sort(selAry1, 100);

   //insertion
   insertionSort(insAry1, 100);
   print_ins_sort(insAry1, 100);

   //bubble
   bubbleSort(bubAry1, 100);
   print_bubble_sort(bubAry1, 100);

   //quick
   cout << "Big - O calculated value for nlogn: 200\n";
   iter = quickSort(quickAry1, 0, 99, 0);
   cout << "Quick Sort Iterations: " << iter << endl;
   print_quick_sort(quickAry1, 100);

   //adding to binary search tree
   Tree* tree1 = new Tree();

   //adding array to BST
   for (int i = 0; i < 100; i++)
   {
      iter = tree1->addNode(quickAry1[i], 0);
   }

   cout << "\nBig - O calculated value for n: 100\n";
   cout << "Adding to BST iterations: " << iter << endl;

   //printing BST in-order
   //clearing file before recursion
   ofstream out_file1;
   out_file1.open("BST100.dat", ofstream::trunc);
   if (out_file1.fail())
   {
      cout << "Could not open file. Terminating program.\n";
   }
   else { out_file1 << ""; }
   out_file1.close();

   iter = tree1->inOrder(tree1->Root(), 0, 100);
   cout << "Printing BST iterations: " << iter << endl << endl;

   //deleting tree
   delete tree1;

   /* LIST 500 */
   //output
   cout << "\nList 500\n\n";
   cout << "Big - O calculated value for n^2: " << (500 * 500) << "\n";

   //creating arrays
   fill_array(sortAry5, 500);
   sort_data selAry5[500];
   sort_data insAry5[500];
   sort_data bubAry5[500];
   sort_data quickAry5[500];

   copy(sortAry5, sortAry5 + 500, selAry5);
   copy(sortAry5, sortAry5 + 500, insAry5);
   copy(sortAry5, sortAry5 + 500, bubAry5);
   copy(sortAry5, sortAry5 + 500, quickAry5);

   //selection
   selectionSort(selAry5, 500);
   print_sel_sort(selAry5, 500);

   //insertion
   insertionSort(insAry5, 500);
   print_ins_sort(insAry5, 500);

   //bubble
   bubbleSort(bubAry5, 500);
   print_bubble_sort(bubAry5, 500);

   //quick
   cout << "Big - O calculated value for nlogn: 1350\n";
   iter = quickSort(quickAry5, 0, 499, 0);
   cout << "Quick Sort Iterations: " << iter << endl;
   print_quick_sort(quickAry5, 500);

   //adding to binary search tree
   Tree* tree5 = new Tree();

   //adding array to BST
   for (int i = 0; i < 500; i++)
   {
      iter = tree5->addNode(quickAry5[i], 0);
   }

   cout << "\nBig - O calculated value for n: 500\n";
   cout << "Adding to BST iterations: " << iter << endl;

   //printing BST in-order
   //clearing file before recursion
   ofstream out_file5;
   out_file5.open("BST500.dat", ofstream::trunc);
   if (out_file5.fail())
   {
      cout << "Could not open file. Terminating program.\n";
   }
   else { out_file5 << ""; }
   out_file5.close();

   iter = tree5->inOrder(tree5->Root(), 0, 500);
   cout << "Printing BST iterations: " << iter << endl << endl;

   //deleting tree
   delete tree5;

   /* LIST 1000 */
   //output
   cout << "\nList 1000\n\n";
   cout << "Big - O calculated value for n^2: " << (1000 * 1000) << "\n";

   //creating arrays
   fill_array(sortAry10, 1000);
   sort_data selAry10[1000];
   sort_data insAry10[1000];
   sort_data bubAry10[1000];
   sort_data quickAry10[1000];

   copy(sortAry10, sortAry10 + 1000, selAry10);
   copy(sortAry10, sortAry10 + 1000, insAry10);
   copy(sortAry10, sortAry10 + 1000, bubAry10);
   copy(sortAry10, sortAry10 + 1000, quickAry10);

   //selection
   selectionSort(selAry10, 1000);
   print_sel_sort(selAry10, 1000);

   //insertion
   insertionSort(insAry10, 1000);
   print_ins_sort(insAry10, 1000);

   //bubble
   bubbleSort(bubAry10, 1000);
   print_bubble_sort(bubAry10, 1000);

   //quick
   cout << "Big - O calculated value for nlogn: 3000\n";
   iter = quickSort(quickAry10, 0, 999, 0);
   cout << "Quick Sort Iterations: " << iter << endl;
   print_quick_sort(quickAry10, 1000);

   //adding to binary search tree
   Tree* tree10 = new Tree();

   //adding array to BST
   for (int i = 0; i < 1000; i++)
   {
      iter = tree10->addNode(quickAry10[i], 0);
   }

   cout << "\nBig - O calculated value for n: 1000\n";
   cout << "Adding to BST iterations: " << iter << endl;

   //printing BST in-order
   //clearing file before recursion
   ofstream out_file10;
   out_file10.open("BST1000.dat", ofstream::trunc);
   if (out_file10.fail())
   {
      cout << "Could not open file. Terminating program.\n";
   }
   else { out_file10 << ""; }
   out_file10.close();

   iter = tree10->inOrder(tree10->Root(), 0, 1000);
   cout << "Printing BST iterations: " << iter << endl << endl;

   //deleting tree
   delete tree10;

	return 0;
}

//fills the array with the desired amount of data
void fill_array(sort_data sortAry[], int n)
{
   for (int i = 0; i < n; i++)
   {
      sortAry[i].key = rand();
      sortAry[i].val = (float)rand();
   }
}

//prints quick sort function data to file
void print_quick_sort(sort_data Ary[], int n)
{
   //writing to file
   string file_name = "quick" + to_string(n) + ".dat";

   ofstream out_file;
   out_file.open(file_name, ofstream::trunc);
   if (out_file.fail())
   {
      cout << "Could not open file. Terminating program.\n";
   }
   else
   {
      for (int i = 0; i < n; i++)
      {
         out_file << "key: " << Ary[i].key << " ";
         out_file << "val: " << Ary[i].val << " \n";
      }
   }
   out_file.close();
}

//prints bubble sort function data to file
void print_bubble_sort(sort_data Ary[], int n)
{
   //writing to file
   string file_name = "bub" + to_string(n) + ".dat";

   ofstream out_file;
   out_file.open(file_name, ofstream::trunc);
   if (out_file.fail())
   {
      cout << "Could not open file. Terminating program.\n";
   }
   else
   {
      for (int i = 0; i < n; i++)
      {
         out_file << "key: " << Ary[i].key << " ";
         out_file << "val: " << Ary[i].val << " \n";
      }
   }
   out_file.close();
}

//prints insertion sort function data to file
void print_ins_sort(sort_data Ary[], int n)
{
   //writing to file
   string file_name = "sins" + to_string(n) + ".dat";

   ofstream out_file;
   out_file.open(file_name, ofstream::trunc);
   if (out_file.fail())
   {
      cout << "Could not open file. Terminating program.\n";
   }
   else
   {
      for (int i = 0; i < n; i++)
      {
         out_file << "key: " << Ary[i].key << " ";
         out_file << "val: " << Ary[i].val << " \n";
      }
   }
   out_file.close();
}

//prints selection sort function data to file
void print_sel_sort(sort_data Ary[], int n)
{
   //writing to file
   string file_name = "sels" + to_string(n) + ".dat";

   ofstream out_file;
   out_file.open(file_name, ofstream::trunc);
   if (out_file.fail())
   {
      cout << "Could not open file. Terminating program.\n";
   }
   else
   {
      for (int i = 0; i < n; i++)
      {
         out_file << "key: " << Ary[i].key << " ";
         out_file << "val: " << Ary[i].val << " \n";
      }
   }
   out_file.close();
}