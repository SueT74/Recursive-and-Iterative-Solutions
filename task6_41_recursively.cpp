/*The greatest common divisor of integers x and y is
the largest integer that evenly divides both x and y. Write a recursive function gcd that returns the
greatest common divisor of x and y, defined recursively as follows: If y is equal to 0, then gcd(x, y)
is x; otherwise, gcd(x, y) is gcd(y, x % y), where % is the remainder operator. [Note: For this algorithm,
x must be larger than y.]*/

// Susan Tunkkari C++ 2021 NITS19K 

#include <iostream>
using namespace std;

int gcd(int, int);

int main() {
	
    	int x, y;

	cout << "Find the greatest common divisor of two numbers - Recursively"<< endl;
    	cout << "***********************************************************"<< endl;
	
	// get numbers from user
    	cout << "Enter x and y: ";
    	cin >> x >> y;

    	// For this algorithm, x must be larger than y.
    	if (x < y) 
	{
		int tmp = x;
		x = y;
		y = tmp;
   	 }
    
	cout<< "GCD is: " <<gcd(x,y);
	
    	return 0;
}
// recursive greatest common divisor
int gcd(int x, int y) {
	
    	if (y == 0) 
	{
        	return x;
   	} 
	else 
	{
        	return gcd(y, x % y);
   	}
}
