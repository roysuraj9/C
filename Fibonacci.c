/*
Name : Suraj Roy
Date : 24/06/2022
Description : WAP to generate fibbonacci numbers using recursion
Sample Input :
Enter the limit : 55
Sample Output : 
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
*/

#include<stdio.h>

//pre declare function
void positive_fibonacci(int limit, int first, int second, int next);

int main()
{
       //declare variable
       int limit ,first = 0, second = 1 ,next = 0;

       //read limit from user 
       printf("Enter the limit : ");
       scanf("%d", &limit);

       //function call
       positive_fibonacci(limit, first, second, next);
}
//function
void positive_fibonacci(int limit, int first, int second, int next)
{
       //conditon check limit is not negative integer
       if(limit >= 0)
       {
      
	      while( limit >= next )
	      {
		     printf("%d, ", next);
		     //swapping
		     first = second;
		     second = next;
		     //sum 
		     next = first + second;
	      }
	      printf("\n");
       }

       else
       {
	      printf("Invalid input\n");
       }
}
