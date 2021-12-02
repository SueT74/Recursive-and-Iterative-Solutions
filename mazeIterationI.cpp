//maze- iteration solution

//Susan Tunkkari NITS19K C++ Nov 2021


#include <iostream>
using namespace std;

void printMaze(const char maze[12][12], int row, int col);
int mazeTraverse(char maze[12][12], int row, int col, int direction);


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
  
       cout << "\n\n\n*******Great Work! You have made it out of the maze!.*******\n\n\n";
   else   
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


	while (exit == 0)  //while exit not found 
	   {
	   	printMaze(maze, row, col);   // display current location within maze
	   	   
	    if ((row == 4) && (col == 11))   // location of exit of maze
	    {
	    	exit = 1; //maze solved - end statement
	    }
       
       // facing north
       	else if (direction == 0)   
       	{
           	if (maze[row][col+1] == '.')   // check square to the right .
           	{
				row=row;
           		col=col+1;
           		direction =1;
           		maze[row][col] = '*'; 
          	}
           	else if (maze[row-1][col] == '.') // check north 
           	{
				row=row-1;
           		col=col;
           		direction =0; 
				maze[row][col] = '*';          	
           	}
           	else if (maze[row][col-1] == '.') // check left 
           	{
	            row= row;
				col=col-1;
				direction= 3; 
				maze[row][col] = '*'; 
           	}
           //backtracking
           	else if(maze[row][col+1] != '.'&& maze[row-1][col] != '.' &&maze[row][col-1] != '.')//no valid moves
           	{          		
				while(maze[row][col+1]=='#' && maze[row-1][col]=='*'&& maze[row-1][col]!='#')//while no right turn
				{
					row=row-1;
					col=col;
				} 
				if (maze[row][col+1]=='#'&&maze[row][col+1]=='#')
				{
					direction = 2;
				}
				else
					direction=1;   	
		   	}
           
           	else   
               return 0; 
       	}
       
       
       // facing east
       	else if (direction == 1) 
       	{
           	if (maze[row+1][col] == '.') // check south
           	{
           		row=row+1;
           		col=col;
           		direction =2;
           		maze[row][col] = '*'; 
          	}
           	else if (maze[row][col+1] == '.')//check  right 
           	{
				row=row;
           		col=col+1;
           		direction =1;   
				maze[row][col] = '*';         	
           	}
           	else if (maze[row-1][col] == '.') //check north
           	{
				row=row-1;
           		col=col;
           		direction =0;   
				maze[row][col] = '*';         	
           	}    
           //backtracking
           	else if(maze[row+1][col] != '.'&& maze[row][col+1] != '.'&&maze[row-1][col] != '.')
           	{
			while(maze[row-1][col]=='#'&& maze[row][col-1]=='*'&& maze[row][col-1]!='#')
			{				
				row=row;
				col=col-1;	
			}
			if(maze[row-1][col]=='#'&& maze[row][col-1]=='#')
			{
				direction = 3;
			}
			else
			direction =0;
		   }           
           	else  
               return 0;   
       }
             
       // facing south
       	else if (direction == 2) 
    	{
          	if (maze[row][col-1] == '.') // check left 
           	{
				row=row;
           		col=col-1;
           		direction =3;
           		maze[row][col] = '*'; 
           	}
       		else if (maze[row+1][col] == '.') // check south
           	{
				row=row+1;
           		col=col;
           		direction =2;  
				maze[row][col] = '*';          	
           	}
           	else if (maze[row][col+1] == '.') //check right
           	{
           		row=row;
           		col=col+1;
           		direction =1;
           		maze[row][col] = '*'; 
           	}

           	else if(maze[row][col-1] != '.'&& maze[row+1][col] != '.' && maze[row][col+1] != '.' )
           	{
           	while(maze[row][col+1]=='#'&& maze[row+1][col]=='*' &&maze[row+1][col]!='#')
			{				
				row=row+1;
				col=col; 
			}
			if (maze[row][col+1]=='#' &&maze[row+1][col]!='#')
			{
				direction = 1;
			}			
			direction=3;
		   	}
           	else   
               return 0;   
       }
       

       // facing west
       else if (direction == 3) 
       {
           if (maze[row-1][col] == '.') //check north 
           {
           		row=row-1;
           		col=col;
           		direction =0;
           		maze[row][col] = '*'; 
           }
           else if (maze[row][col-1] == '.') // check  left
           {
           		row=row;
           		col=col-1;
           		direction =3;
           		maze[row][col] = '*'; 
           }
           else if (maze[row+1][col] == '.') //check south
           {
           		row=row+1;
           		col=col;
           		direction =2;
                maze[row][col] = '*'; 
           }           
           //backtracking
           else if(maze[row-1][col] != '.' && maze[row][col-1] != '.'&& maze[row+1][col] != '.' )
           {
	           	while(maze[row+1][col]=='#'&& maze[row][col+1]=='*' &&  maze[row][col+1]!='#')
				{
	           	row=row;
	           	col=col+1;
				}	
				if(maze[row+1][col]=='#'&& maze[row][col+1]=='#')
				{							
					direction = 0;
				}
				else 
					direction =2;
		   }            	
			else
				return 0;			                          
       }
   }   
   return exit; 
}





