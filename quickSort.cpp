//quicksort - iteration and recursion methods
//Susan Tunkkari NITS19K C++ Nov 2021

#include <algorithm> 
#include <array>
#include <ctime>
#include <iostream>
#include <random> 

using namespace std;

//swap function - swaps values
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// display array
void displayResults(int array[], int size) 
{
    for (int i=0; i < size; i++)
	{
        cout <<array[i];
           if (i < size-1) 
		   	cout<<", ";
    }
    	cout <<"\n";
}

// find partition point 
int partition(int array[], int low, int high) 
{
  	//start at last (right end) element of the array- select as pivot
  	int pivot = array[high];
  
  	int i = (low - 1);

  	// loop  and compare with pivot
  	for (int j = low; j < high; j++) 
	{
    	if (array[j] <= pivot) 
		{
      		i++;  
      		swap(&array[i], &array[j]);
    	}
  	}
  	// swap pivot with the higher element 
  	swap(&array[i + 1], &array[high]);
  
  	// return partition point
  	return (i + 1);
}

//recursive quickSort function
void quickSortRecursive(int array[], int low, int high) 
{
	if (low < high) 
	{
  
	int pivot = partition(array, low, high);
	
	//recursive call for  the partitioned arrays.
    quickSortRecursive(array, low, pivot - 1);
    quickSortRecursive(array, pivot + 1, high);
  	}
}

//Iterative quickSort function
void quickSortIterative(int array1[], int low, int high)
{
    // Create an auxiliary stack
    int stack[high - low + 1];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[++top] = low;
    stack[++top] = high;
 
    // while not empty - continue popping from stack
    while (top >= 0) {
       
        high = stack[top--];
        low = stack[top--];
 
        int pivot = partition(array1, low, high);
 
        // any elements on left side of pivot 
        if (pivot - 1 > low) 
		{
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }
 
        // any elements on right side of pivot
        if (pivot + 1 < high) 
		{
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
    }
}

//main function
int main() 
{
	//create array
	int array[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
	int size = sizeof(array) / sizeof(array[0]);
  
    cout <<" ****Starting order of array**** \n\n ";
    
    displayResults(array, size);//display array before sorting
  
  //call quickSortRecursive
  	quickSortRecursive(array, 0, size - 1);
  
    cout <<"\n ****Order of array after sorting - using Quick Sort (RECURSIVE)**** \n\n ";
    displayResults(array, size);//display array after sorting- recursively
  
  //new array to show iterative version
  	int array1[] = {9, 21, 6, 77, 89, 8, 69, 12, 33, 45};
  	int size1 = sizeof(array) / sizeof(array[0]);

    cout <<"\n\n****Starting order of array1**** \n\n ";
    displayResults(array1, size);//display array before sorting 
  
   	// call quickSortIterative
  	quickSortIterative(array1, 0, size1 - 1);
  
    cout <<"\n ****Order of array after sorting - using Quick Sort (ITERATION)**** \n\n ";
    displayResults(array1, size1);//display array after sorting - iteratively
    return 0;
    
    
}
