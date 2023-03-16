/*
Name : Suraj Roy 
Date : 30/07/2022
Description : WAP to implement fragments using Array of Pointers
Sample Input : 
Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 5 
Enter no of columns in row[2] : 3
Enter 4 values for row[0] : 2 34 6 8
Enter 5 values for row[1] : 345 67 1 576 2
Enter 3 values for row[2] : 456 87 2

Sample Output :
Before sorting output is:
2.000000 34.000000 6.000000 8.000000 12.500000
345.000000 67.000000 1.000000 576.000000 2.000000 198.199997
456.000000 87.000000 2.000000 181.666672
After sorting output is:
2.000000 34.000000 6.000000 8.000000 12.500000 
456.000000 87.000000 2.000000 181.666672 
345.000000 67.000000 1.000000 576.000000 2.000000 198.199997 
*/

#include <stdio.h>
#include<stdlib.h>

void fragments( float **a, int row,int *arr);

int main()
{
       int row, i, j, col;
       //reading user input
       printf("Enter no.of rows : ");
       scanf("%d", &row);
       //create 1d array
       int arr[row];

       //reading number of column
       for(i = 0; i < row; i++)
       {
	      printf("Enter no of columns in row[%d] : ", i);
	      scanf("%d", &arr[i]);
       }

       //using dynamic memory allocation array to pointer
       float *a[row];
       for(i = 0; i < row; i++)
       {
      	      printf("Enter %d values for row[%d] : ", arr[i], i);
	      a[i] = malloc((arr[i]+1) * sizeof(float*));

	      //reading user input of element
	      for(j = 0; j < arr[i]; j++)
	      {
		     scanf(" %f", &a[i][j]);
	      }
       }

       //display before sorting and performing average of each 1d array
       printf("Before sorting output is:\n");

       for(i = 0; i < row;i++)
       {
	      float sum = 0;
	      for(j = 0; j < arr[i]; j++)
	      {
		     printf("%f ", a[i][j]);
		     sum =sum + a[i][j];
	      }

	      printf("%f\n", a[i][j] = (sum / j));
       }
       //calling function
       fragments(a, row, arr);
       //free memory allocated
       for ( i = 0; i < row; i++)
       {
	      free(a[i]);
       }
       return 0;
}
//function
void fragments(float **a, int row , int *arr)
{
       //declare variables
       int i, j;

       //performing swapping
       for (i = 0; i < row - 1; i++)
       {
	      for (j = 0; j < row - i - 1; j++)
	      {
		     if (a[j][arr[j]] > a[j + 1][arr[j + 1]])
		     {
 			    float *temp = a[j];
			    a[j] = a[j + 1];
			    a[j + 1] = temp;
			    
			    int temp1 = arr[j];
			    arr[j] = arr[j + 1];
			    arr[j + 1] = temp1;
		     }
	      }
       }
       
       //display sorted 
       printf("After sorting output is:\n");
       for (i = 0; i < row; i++)
       {
	      for (j = 0; j < arr[i] + 1; j++)
	      {
		     printf("%f ", a[i][j]);
	      }
	      printf("\n");
       }
}
