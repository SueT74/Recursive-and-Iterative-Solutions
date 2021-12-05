//maze - recursive solution
//Susan Tunkkari NITS19K C++ Nov 2021

#include <iostream>
#include <windows.h>

using namespace std;

void printMaze(const char maze[12][12], int row, int col);
int mazeTraverse(char maze[12][12], int row, int col, int facing);

int main()
{	
	// maze designed as per picture in book
   char maze[ 12 ][ 12 ] =
      { 
      { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      { '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
      { '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
      { '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
      { '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},      
      { '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      { '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      { '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
      { '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
      { '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
      { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} 
	  };
	  
   int exit = 0;

   exit = mazeTraverse(maze, 2, 0, 1);   // get exit value from the function 

   if (exit == 1)   //exit is 1 - maze is solved
       cout << "\n\n\n*******You have made it out of the maze!.*******\n\n\n";
   else   // 
       cout << "\n\n\n***Sorry, you are still stuck in the maze.***\n\n\n";//shouldnt be needed unless there is no exit

   return 0; 
}
// print maze - showing current position
void printMaze( const char maze[12][ 12 ], int row, int col)
{
	for ( int x = 0; x < 12; ++x )
	{
	    for ( int y = 0; y < 12; ++y )
	        if ((x == row) && (y == col))
	            cout << 'X' << ' ';
	        else
	            cout << maze[ x ][ y ] << ' ';
				cout << '\n';
	   } 
   
	//show each stage of moving through maze
   	cout << "\nPress return for next move\n";
   	cin.get();
   	system("CLS");
} 

// move through the maze checking for moves
int mazeTraverse(char maze[12][12], int row, int col, int direction)
{
	int exit = 0;// initialise exit as 0 to start
	
	maze[row][col] = '*'; 
	
	printMaze(maze, row, col);   // display current location within maze
	
	while (exit == 0)  //while exit not found 
   	{
       	if ((row == 4) && (col == 11))   // location of exit of maze
       	{
           	exit = 1; //maze solved - end statement
       	}
       	else if (direction == 0)   // facing north
       	{
	        if (maze[row][col+1] == '.')   // check square to the right .
	        {
	            exit = mazeTraverse(maze, row, col+1, 1); // Move right.
	        }
	        else if (maze[row-1][col] == '.') // check north 
	        {
	            exit = mazeTraverse(maze, row-1, col, 0); // Move up
	        }
	        else if (maze[row][col-1] == '.') // check left 
	        {
	            exit = mazeTraverse(maze, row, col-1, 3); // Move left.
	        }
	        else   
            return 0; // If no move possible - returns to previous junction.
       	}
       	else if (direction == 1) // facing east
       	{
           	if (maze[row+1][col] == '.') // check south
           	{
               	exit = mazeTraverse(maze, row+1, col, 2); // Move down.
           	}
           	else if (maze[row][col+1] == '.')//check  right 
           	{
            	exit = mazeTraverse(maze, row, col+1, 1); // Move right.
           	}
           	else if (maze[row-1][col] == '.') //check north
           	{
               	exit = mazeTraverse(maze, row-1, col, 0); // Move up
           	}
           	else  
               	return 0;   
       	}
       else if (direction == 2) // facing south
       	{
           	if (maze[row][col-1] == '.') // check left 
           	{
               	exit = mazeTraverse(maze, row, col-1, 3); // Move left.
           	}
           	else if (maze[row+1][col] == '.') // check south
           	{
               	exit = mazeTraverse(maze, row+1, col, 2); // Move down.
           	}
           	else if (maze[row][col+1] == '.') //check right
           	{
               	exit = mazeTraverse(maze, row, col+1, 1); // Move right.
           	}
           	else   
              	 return 0;   
       	}
       	else if (direction == 3) // facing west
       	{
           	if (maze[row-1][col] == '.') //check north 
           	{
               	exit = mazeTraverse(maze, row-1, col, 0); // Move up.
           	}
           	else if (maze[row][col-1] == '.') // check  left
           	{
               exit = mazeTraverse(maze, row, col-1, 3); // Move left.
           	}
           	else if (maze[row+1][col] == '.') //check south
           	{
               	exit = mazeTraverse(maze, row+1, col, 2); // Move down.
           	}
           	else   
               	return 0;   
       	}
   	} 

   	return exit; 
}





