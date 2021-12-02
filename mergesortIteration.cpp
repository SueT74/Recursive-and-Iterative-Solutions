//Susan Tunkkari NITS19K C++ Nov 2021

//mergeSort by iteration.

#include <array>
#include <iostream>
using namespace std;

// funct to get smallest of two numbers
int smallest(int x, int y) 
{ 
	if (x<y)
	{
		return x;
	}
	else 
		return y;
}
 
// merge function
void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int mid1 = mid - left + 1;
    int mid2 =  right - mid;
 
    // create temp arrays 
    int leftArray[mid1], rightArray[mid2];
 
    //copy data to the temp arrays
    for (i = 0; i < mid1; i++)
	{
		leftArray[i] = array[left + i];
	}  
    for (j = 0; j < mid2; j++)
	{
		rightArray[j] = array[mid + 1+ j];
	}

    i = 0;
    j = 0;
    k = left;
    
    while (i < mid1 && j < mid2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }
    }
 
    // copy any remaining elements - leftArray
    while (i < mid1)
    {
        array[k] = leftArray[i];
        i++; 
		k++;     
    }
 
    // Copy any remaining elements - rightArray
    while (j < mid2)
    {
        array[k] = rightArray[j];
        j++; 
        k++;
    }
}

//mergeSort - iteratively 
void mergeSort(int array[], int size)
{
   	int subSize;
   	int start;

   	for (subSize=1; subSize<=size-1; subSize = 2*subSize)
   	{
       	// starting points of different sub-arrays 
      	for (start=0; start<size-1; start =start+ 2*subSize)
      	{
        	int mid = smallest(start + subSize - 1, size-1);
 
           	int end = smallest(start + 2*subSize - 1, size-1);
 
        // merge sub-arrays 
        merge(array, start, mid, end);
       	}
   	}
}
 
//display array
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
 
// main function
int main()
{
	//create array
   	int array[] = {12, 10, 25, 88, 47, 51, 8, 2, 5, 36};
   	int size = sizeof(array)/sizeof(array[0]);
 
    cout <<" ****Starting order of array**** \n\n ";
    displayResults(array, size);//display array before sorting
 	
 	//call mergeSort
    mergeSort(array, size);
 
    cout <<"\n ****Order of array after sorting - using mergeSort (iteration)**** \n\n ";
    displayResults(array, size);//display array after sorting
    return 0;
}

