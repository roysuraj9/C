/*
Name : Suraj Roy
Date : 21/05/2022
Description : WAP to print pyramid pattern
Sample Input : Enter the number: 3
Sample Output : 
3
23
123
23
3
*/

#include<stdio.h>

int main()
{
       int n ,i ,j ,count=0;                                   //declare variable

       printf("Enter the number: ");
       scanf("%d", &n);

       for(i = 1; i < n*2; i++)                      //for loop for row
       {
	
	      if ( i < n + 1 )
	      {
		     count++;                         //increement count
	      }
	      else
	      {
		     count--;                          //decreement count
	      }
	      
	
	      for( j = 1; j <= n; j++ )               //for loop for column
	      {
	
		     if (j >= (( n + 1 ) - count ))
		     {
			    printf(" %d", j);
		     }
	      }
		     
	      printf("\n");                        //print new line
       }
       return 0;

}
