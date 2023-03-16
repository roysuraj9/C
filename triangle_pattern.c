/*
Name : Suraj Roy
Date : 21/05/2022
Description : WAP to print triangle pattern
Sample Input : Enter the number: 6
Sample Output : 
1 2 3 4 5 6
7       8
9     10
11   12
13 14
15
*/

#include<stdio.h>

int main()
{
       int n ,i ,j ,count=0;                                   //declare variable

       printf("Enter the number: ");
       scanf("%d", &n);

       for(i = 1; i <= n; i++)                      //for loop for row
       {
	
	
	      for( j = i; j <= n; j++ )               //for loop for column
	      {
	
		     if (i == 1 || j == i || j == n )       //condition check for print value
		     {
			    count++;                        //increement count value
			    printf("%d ", count);
		     }

		     else
		     {
			    printf("  ");
		     }
	      }
		     
	      printf("\n");                        //print new line
       }
       return 0;

}
