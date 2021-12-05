#include<iostream>
#include <windows.h>
using namespace std;

//display the queens 8 board
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

//check if a square is valid to place queen
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


//main function
int main()
{
	int board[8][8];
	int queens = 0;//count for queens placed
	int temp = 0;//hold the starting point 
	int col = 0;//start at col 0
	int possible=0;//mark if valid moves in next column from queen
	
	//initiate board
	for (int i = 0; i < 8; i++) 		
		for (int k = 0; k < 8; k++)
			board[i][k] = 0;
	
	
	while (queens<8)//while all queens are not placed on board
	{
		for (int i=temp; i < 8; i++)
		{
			if (squareValid(board, i, col))
			{			
				board[i][col] = 1;//place queen on board if valid
				queens++; //add to count
				
				if (queens == 8)//if last queen was placed
				break;
	
				//queens still remaining 
				for (int j = 0; j < 8; j++)
				{
					if ( col != 7)//not at the end of the col
						if (squareValid(board, j, col+1))//check next col for possible moves
							possible+=1;//mark if there is valid/possible moves for next col
				}
				//no valid/possible places
				if (possible== 0)
				{
					board[i][col] = 0; //remove the queen from the board
					queens--; //remove queen from count
				}	
				else //else if there is possible moves 
				{
					col++;//go to next col
					temp = 0; //reset search start point
					break;//break out of loop- search starts again on next col
				}
			}
 
			if (i == 7 && board[i][col] == 0)//last row of col and no queen placed/valid place 
				if (i == 7 && board[i][col-1] == 1)//prev col has a queen in end row
				{
					col=col-1;// backtrack to col
					board[i][col] = 0;// remove queen from board
					queens--;//remove from count								
				}
				
			if (i == 7 && board[i][col] == 0)//last row and no queen
			{				
				col--;//backtrack
				for (int j = 0; j< 8; j++)
				{
					if (board[j][col] == 1)//search for queen to remove
					{
						board[j][col] = 0;//remove queen from board
						queens--;//remove queen from count
						temp = j+1; //search again for valid square from 1 row over						
					}							
				}				
			}
		}	
	}		
	displayBoard(board);
}




