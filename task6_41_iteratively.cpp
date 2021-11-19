// Susan Tunkkari C++ 2021 NITS19K 
//ch6 task 6.41 done iteratively
#include <iostream>
using namespace std;

int gcd(int x, int y)
{
	cout << "Find the greatest common divisor of two numbers - Iteratively"<< endl;
    	cout << "*************************************************************"<< endl;
	
	// get numbers from user
    	cout << "Enter x and y: ";
    	cin >> x >> y;
	

	if (x==0) 
	{
		return y;
    	}
    	else if (y==0)
	{
		return x;		
	}

    	while (x != y) 
	{
        	if (x > y)
		{
			x = x - y;
		}

       	 	else
		{
			y = y - x;
		}       
   	 }
    
    	return x;
}
 

int main()
{
	int x,y;
    	cout<< "GCD is: " <<gcd(x,y);
    	return 0;
}
