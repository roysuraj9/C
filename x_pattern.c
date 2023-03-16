/*
Name : Suraj Roy
Date : 21/05/2022
Description : WAP to print the numbers in X format as shown below
Sample Input : Enter the number: 6
Sample Output : 
1    6
 2  5
  34
  34
 2  5
1    6
*/
#include<stdio.h>

int main()
{
       int n,i,j;                                   //declare variable

       printf("Enter the number: ");
       scanf("%d", &n);

       for(i = 1; i <= n; i++)                      //for loop for row
       {
	      for(j = 1; j <= n; j++)               //for loop for column
	      {
		     
		     if ( i == j )                  // checking condition and printing values
		     {
			    printf("%d", i);
		     }

		     else if ( i + j == n + 1 )
		     {
			    printf("%d", j);
		     }

		     else
		     {
			    printf(" ");
		     }
	      }

	      printf("\n");                        //print new line
       }
       return 0;

}
