/*
Name : Suraj Roy
Date : 24/06/2022
Description : WAP to generate negative fibbonacci numbers using recursion
Sample Input :
Enter the limit : -30
Sample Output : 
0, 1, -1, 2, -3, 5, -8, 13, -21
 */
#include<stdio.h>

//pre declare function
void negative_fibonacci(int limit, int first, int second, int next);

int main()
{
       //declare variable
       int limit ,first = 0, second = 1 ,next = 0;

       //read limit from user 
       printf("Enter the limit : ");
       scanf("%d", &limit);

       //function call
       negative_fibonacci(limit, first, second, next);
}
//function
void negative_fibonacci(int limit, int first, int second, int next)
{
       //initailization
       int nextneg = -1;
       
       //conditon check limit is zero,positive integer or negative
       if(limit == 0)
       {
	      printf("0\n");
       }
       else if(limit < 0)
       {
      
	      while( limit <= nextneg )
	      {
		     printf("%d, ", next);
		     //swapping
		     first = second;
		     second = next;
		     //subtraction
		     next = first - second;

		     if (next > 0)
		     {
			    nextneg = next * - 1;
		     }
		     else
		     {
			    nextneg = next;
		     }
	      }
	      printf("\n");
       }

       else
       {
	      printf("Invalid input\n");
       }
}
