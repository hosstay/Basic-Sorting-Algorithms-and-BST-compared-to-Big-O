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


//Node class for use in tree
class Node
{
   sort_data key;
   Node* left;
   Node* right;
public:
   Node() { left = NULL; right = NULL; };
   void setKey(sort_data aKey) { key = aKey; };
   void setLeft(Node* aLeft) { left = aLeft; };
   void setRight(Node* aRight) { right = aRight; };
   sort_data Key() { return key; };
   int KeyK() { return key.key; };
   float KeyV() { return key.val; };
   Node* Left() { return left; };
   Node* Right() { return right; };
};

//binary search tree class
class Tree
{
   Node* root;
public:
   Tree();
   ~Tree();
   Node* Root() { return root; };
   int addNode(sort_data key, int iter);
   int inOrder(Node* n, int iter, int size);
private:
   int addNode(sort_data key, Node* leaf, int iter);
   void freeNode(Node* leaf);
};

// Constructor
Tree::Tree()
{
   root = NULL;
}

// Destructor
Tree::~Tree()
{
   freeNode(root);
}

// Free the node and all of its children by recursion
void Tree::freeNode(Node* leaf)
{
   if (leaf != NULL)
   {
      freeNode(leaf->Left());
      freeNode(leaf->Right());
      delete leaf;
   }
}

// Add a node
// if root doesn't exist create it, 
// otherwise send the key and root to other addNode function
int Tree::addNode(sort_data key, int iter)
{
   // No elements. Add the root
   if (root == NULL)
   {
      Node* n = new Node();
      n->setKey(key);
      root = n;
      iter++;
   }
   else
   {
      iter = addNode(key, root, iter);
   }
   iter++;
   return iter;
}

// Add a node (private)
// checking for less than or equal to for left and
// greater than for right and passing the key and new root
// recursively if a subtree root already exists.
int Tree::addNode(sort_data key, Node* leaf, int iter)
{
   if (key.key <= leaf->KeyK())
   {
      if (leaf->Left() != NULL)
         iter = addNode(key, leaf->Left(), iter);
      else
      {
         Node* n = new Node();
         n->setKey(key);
         leaf->setLeft(n);
      }
   }
   else
   {
      if (leaf->Right() != NULL)
         iter = addNode(key, leaf->Right(), iter);
      else
      {
         Node* n = new Node();
         n->setKey(key);
         leaf->setRight(n);
      }
   }
   iter++;

   return iter;
}

// Print the tree in-order
// Traverse the left sub-tree, root, right sub-tree
int Tree::inOrder(Node* n, int iter, int size)
{
   if (n)
   {
      iter = inOrder(n->Left(), 0, size);

      //writting to file
      ofstream out_file;
      string file_name = "BST" + to_string(size) + ".dat";

      out_file.open(file_name, ofstream::app);
      if (out_file.fail())
      {
         cout << "Could not open file. Terminating program.\n";
      }
      else
      {
         out_file << "Key: " << n->KeyK() << " Val: " << n->KeyV() << " \n";
      }
      out_file.close();

      iter = inOrder(n->Right(), 0, size);
      iter++;
   }
   return iter;
}