/*20.9 (Recursive Binary Search) Modify Fig. 20.3 to use
recursive function recursiveBinarySearch to perform a binary
search of the array . The function should receive the array , the
search key, starting index and ending index as arguments. If
the search key is found, return its index in the array . If the
search key is not found, return –1 .*/

//Susan Tunkkari NITS19K C++ Nov 2021
//RecursiveBinarySearch.cpp 

#include <algorithm> 
#include <array>
#include <ctime>
#include <iostream>
#include <random> 
using namespace std;

// display array elements from index low through index high
template <typename T, size_t size>
void displayElements(const array<T, size>& items, 
   size_t low, size_t high) {
   for (size_t i{0}; i < items.size() && i < low; ++i) {
      cout << "   "; // display spaces for alignment 
   }

   for (size_t i{low}; i < items.size() && i <= high; ++i) {
      cout << items[i] << " "; // display element
   }

   cout << endl;
} 

// perform a binary search on the data                             
template <typename T, size_t size>                                
int recursiveBinarySearch(const array<T, size>& items, const T& key, int low, int high ) 
{        
	int mid = low + (high - low) / 2; 
	
	displayElements(items, low, high);                         

    // output spaces for alignment                               
    for (int i{0}; i < mid; ++i) 
	{                          
        cout << "   ";                                             
    }

    cout << " * " << endl; // indicate current middle
    
	if (high >= low)
	{

    if (items[mid]== key)
      	return mid;
      
    if ( items[mid]> key)
      	return recursiveBinarySearch(items, key ,low,  mid-1);  
      
    if (items[mid < key])
      	return recursiveBinarySearch(items, key, mid + 1, high);  
  	}

  	return -1;
} 

int main() {
   // use the default random-number generation engine to produce
   // uniformly distributed pseudorandom int values from 10 to 99
   	default_random_engine engine{
      	static_cast<unsigned int>(time(nullptr))};
  	uniform_int_distribution<unsigned int> randomInt{10, 99}; 

   const size_t arraySize{15}; // size of array 
   array<int, arraySize> arrayToSearch; // create array

   // fill arrayToSearch with random values
   	for (int &item : arrayToSearch) 
	{
      	item = randomInt(engine);
   	}

   	sort(arrayToSearch.begin(), arrayToSearch.end()); // sort the array

  	 // display arrayToSearch's values
   	displayElements(arrayToSearch, 0, arrayToSearch.size() - 1); 

	// get input from user
	cout << "\nPlease enter an integer value (-1 to quit): ";
	int searchKey; // value to locate 
	cin >> searchKey; // read an int from user
	cout << endl;


	int n={static_cast<int>(arrayToSearch.size()) - 1}	;
	
   	// repeatedly input an integer; -1 terminates the program
   	while (searchKey != -1) 
	{
    // use binary search to try to find integer
    int position{recursiveBinarySearch(arrayToSearch,searchKey,0, n-1)};

    // return value of -1 indicates integer was not found
    if (position == -1) 
	{
        cout << "The integer " << searchKey << " was not found.\n";
    }
    else 
	{
        cout << "The integer " << searchKey 
        << " was found in position " << position << ".\n";
    }

	// get input from user
	cout << "\n\nPlease enter an integer value (-1 to quit): ";
	cin >> searchKey; // read an int from user
	cout << endl;
   } 
} 
