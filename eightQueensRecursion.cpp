// Eight Queens problem- recursive solution
//Susan Tunkkari NITS19K C++ Nov 2021


#include<iostream>
#include <windows.h>
using namespace std;

// display solution board
void displayBoard(int board[8][8]) 
{
   	for (int i = 0; i < 8; i++) 
	{
      	for (int j = 0; j < 8; j++)
	        if(board[i][j] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);//put as diff colors to make it easier to see 
	        	cout << " Q ";
			} 
	        else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);	
	        	cout << " - ";
			} 
	        cout << endl;
	}
}
//check that a square is valid to place queen
bool squareValid(int board[8][8], int row, int col)
 {
  	//check for queen in row/col
   	for (int i = 0; i < col; i++) 
    	if (board[row][i])
	  	{
	  		return false;//not valid square
	  	}
  
    //check for queen in the left diagonal     
	for (int i=row, j=col; i>=0 && j>=0; i--, j--)
	    if (board[i][j])
		{
		  	return false;//not valid square
		} 
         
	//check for queen in the right  diagonal     
	for (int i=row, j=col; j>=0 && i<8; i++, j--)
	    if (board[i][j]) 
		{
		  	return false;//not valid square
		}
			   
	   	return true; //valid square
}
//search for places to place the queens
bool placeQueens(int board[8][8], int col) 
{
	//a solution is found - all queens placed in squares - end statement
	if (col >= 8) 
	   	{
      		return true;
      	}
   
   //check if the queen can be placed or not for each of the rows
   	for (int i = 0; i < 8; i++) 
	{ 
      	if (squareValid(board, i, col) ) //check if square is valid
	 	{
	  		//if square is valid, then place the queen in the square
        	board[i][col] = 1; 
       		//check colums (recursively)
       	 	if (placeQueens(board, col + 1))	
        		return true;
        		
         	board[i][col] = 0; // if no valid place - remove queen from the square
      	} 
   	}
   	return false; //No place is found	
}


int main() 
{
   	int board[8][8];
   	
   	for(int i = 0; i<8; i++)
   		for(int j = 0; j<8; j++)
   		//start with values to 0 
	  	board[i][j] = 0; 
	   	if (placeQueens(board, 0) == false ) //check starting from 0 - if all 0 no solution was found 
			{ 
			    cout << "No solution was found";
			    return false;
			}		   	
		   displayBoard(board);
}
