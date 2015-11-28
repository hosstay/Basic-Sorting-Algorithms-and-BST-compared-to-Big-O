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

//simple structure to hold key and data
//automatically sets everything to zero when created
struct sort_data
{
   int key;
   float val;

   sort_data()
   {
      key = 0;
      val = 0;
   }
};