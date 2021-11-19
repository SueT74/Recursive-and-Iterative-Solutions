// Susan Tunkkari C++ 2021 NITS19K 

/*The greatest common divisor of integers x and y is
the largest integer that evenly divides both x and y. Write a recursive function gcd that returns the
greatest common divisor of x and y, defined recursively as follows: If y is equal to 0, then gcd(x, y)
is x; otherwise, gcd(x, y) is gcd(y, x % y), where % is the remainder operator. [Note: For this algorithm,
x must be larger than y.]*/

#include <iostream>
using namespace std;

//find gcd recursively
int gcdRecursive(int x, int y){
	
	if (x < y)//make sure x>y
	{
        	int tmp = x;
        	x = y;
        	y = tmp;
   	 }
    
   	 if (y == 0) //if y is 0 return x value
	{
        	return x;
    	} 
	else 
	{
		return gcdRecursive(y, x % y);//gcd calculate
    	}
}

//find gcd with iteration
int gcdIteration(int,int){
	
	int x,y,r; 

	if (x < y) //make sure x > y
	{
		int tmp = x;
		x = y;
		y = tmp;
	}

	if (y == 0)// if y is 0 gcd return x value
	{
		return x;
	} 


	while(y != 0)//calculate gcd
		{
		r = x % y;
		x = y;
		y = r;
	}

	return x;
}
 

int main()
{
	int x,y;

// get numbers from user
	cout << "Enter x and y: ";
	cin >> x >> y;

	//print recursive result
	cout << "\n***********************"<< endl;
	cout<< "GCD recursively is: " <<gcdRecursive(x,y) <<endl;

	//print ilerative
	cout << "\n***********************"<< endl;
	cout<< "GCD iteratively is: " <<gcdIteration(x,y)<<endl;
	return 0;
}
