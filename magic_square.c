/*
Name : Suraj Roy 
Date : 27/07/2022
Description : WAP to generate a n*n magic square
Sample Input : Enter a number: 5

Sample Output : 
17  24   1   8  15  
23   5   7  14  16  
 4   6  13  20  22  
10  12  19  21   3  
11  18  25   2   9
 */

#include <stdio.h>
#include <stdlib.h>

//function protype 
void magic_square(int **m_squ, int n);

int main()
{
       //declaring variable
       int **m_squ, n, i;
   
       //reading user input
       printf("Enter a number: ");
       scanf("%d", &n);
   
       //condition check odd or even given by user
       if(n % 2 == 0)
       {
	      printf("Error : Please enter only positive odd numbers\n");
       }
     
       //if number is odd
       else
       {
	      //generated dynamic 2d arrray
	      m_squ = malloc(n * sizeof(int *));
	      for(i = 0; i < n; i++)
	      {
		     m_squ[i] = malloc(n * sizeof(int));
	      }
 
	      //function call
       	      magic_square(m_squ, n);     
       
	      //free
	      free(m_squ);
       }
      
       return 0;
}

//function
void magic_square(int **m_squ,int n)
{
       //declaring vaiable
       int row, col, i, j;
       row = 0;
       //first number in top centre
       col = n / 2;
       
       //store number from 1 to n * n
       for(i = 1; i <= n * n; i++)
       {

	      m_squ[row][col] = i;

	      //moving one row up and one column right
	      row--;
	      col++;
	      
	      if(i % n == 0)
	      {
		     row = row + 2;
		     col = col - 1;
		     
		     if(row == n)
		     {
			    row = row - n;
		     }
	      }
	      
	      else
	      {
		     if(col == n)
		     {
			    col = col - n;
		     }
		     
		     if(row < 0)
		     {
			    row = row + n;
		     }
	      }
       }
  
       //return m_squ to main and display output
       for(i = 0; i < n; i++)
       {
	      for(j = 0; j < n; j++)
	      {
		     printf("%2d  ", m_squ[i][j]);
	      }
	      printf("\n");
       }
       
}
