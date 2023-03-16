/*
Name : Suraj Roy
Date : 27/07/2022
Description : 
Sample Input :

Enter number of rows : 2
Enter number of columns : 3
Enter values for 2 x 3 matrix :
1 2 3 4 5 6
Enter number of rows : 3
Enter number of columns : 2
Enter values for 3 x 2 matrix :
10 11 20 21 30 31

Sample Output :
Product of two matrix :
140  146
320  335
*/

#include <stdio.h>
#include <stdlib.h>

//protype function
int matrix_mul(int **mat_a, int row1 , int col1, int **mat_b, int row2, int col2, int **result, int row, int col);

int main()
{
       //declaration variable
       int **mat_a, **mat_b, **result, row1, col1, row2, col2, row, col, i, j;

       //reading user input
       printf("Enter number of rows : ");
       scanf("%d", &row1);

       printf("Enter number of columns : ");
       scanf("%d", &col1);


       //creating 2d array mat_a both dynamic
       mat_a = malloc(row1 * sizeof(int *));
       for(i = 0; i < row1; i++)
       {
   	      mat_a[i] = malloc(col1 * sizeof(int));
       }
       
       printf("Enter values for %d x %d matrix :\n", row1 , col1);

       //reading user input
       for(i = 0; i < row1; i++)
       {
   	      for(j = 0; j < col1; j++)
   	      {
   		     scanf("%d", &mat_a[i][j]);
   	      }
       }

       printf("Enter number of rows : ");
       scanf("%d", &row2);
    
       printf("Enter number of columns : ");
       scanf("%d", &col2);
    
       //condition if col1 is not equal to row2
       if( col1 != row2)
       {
   	      printf("Matrix multiplication is not possible\n");
       }
       
       else
       {
	      //creating 2d array mat_b both dynamic
   	      mat_b = malloc(row2 * sizeof(int *));
   	      for(i = 0; i < row2; i++)
   	      {
   		     mat_b[i] = malloc(col2 * sizeof(int));
   	      }

   	      printf("Enter values for %d x %d matrix :\n", row2, col2);

	      //reading user input for mat_b
   	      for(i = 0; i < row2; i++)
   	      {
   		     for(j = 0; j < col2; j++)
   		     {
   			    scanf("%d", &mat_b[i][j]);
   		     }
   	      }
	   
	      //initializing row and col for result matrix
   	      row = row1;
   	      col = col2;
	   
	   
	      //creating 2d array result to store output
  	      result = malloc(row * sizeof(int *));
   	      for(i = 0; i < row2; i++)
   	      {
   		     result[i] = malloc(col * sizeof(int));
   	      }
	     
	      //function call
	      matrix_mul(mat_a, row1, col1, mat_b, row2, col2, result, row, col);	
	      free(result);   
       }
       
       return 0;
}
//function for product of two matries
int matrix_mul(int **mat_a, int row1 , int col1, int **mat_b, int row2, int col2, int **result, int row, int col)
{

       //declare variable
       int i, j, k;

       //multiplying mat_a, mat_b and storing it in result
       for (int i = 0; i < row; i++)
       {
	      for (int j = 0; j < col; j++)
	      {
		     for (int k = 0; k < col1; k++) 
		     {
			    result[i][j] += mat_a[i][k] * mat_b[k][j];
		     }
	      }
       }


       //print and returning 2d to main
       printf("Product of two matrix :\n");
       for (int i = 0; i < row; i++)
       {
	      for (int j = 0; j < col; j++)
	      {
		     printf("%d  ", result[i][j]);
	      }
	      printf("\n");
       }
}
