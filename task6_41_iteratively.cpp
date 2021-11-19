// Susan Tunkkari C++ 2021 NITS19K 
//ch6 task 6.41 done iteratively
#include <iostream>
using namespace std;

int gcd(int,int)
{
	cout << "Find the greatest common divisor of two numbers - Iteratively"<< endl;
	cout << "*************************************************************"<< endl;
	
	int x,y,r; 
	
	// get numbers from user
    	cout << "Enter x and y: ";
    	cin >> x >> y;
    
	//make sure x > y
	if (x < y) 
	{
		int tmp = x;
		x = y;
		y = tmp;
   	}
	// if y is 0 gcd = x's value
	if (y == 0) 
	{
        	return x;
   	} 
	//work out gcd
   	while(y != 0)
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
	    cout<< "GCD is: " <<gcd(x,y);
	    return 0;
}
