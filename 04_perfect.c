/*
Name : Suraj Roy
Date : 20/05/2022
Description : WAP to check if number is perfect or not
Sample Input : Enter a number: 8128
Sample Output : Yes, entered number is perfect number
*/

#include<stdio.h>

int main()
{

       int  N,i,sum=1;                                                        //intailization/declare value

       printf("Enter a number: ");
       scanf("%d", &N);

       if ( N > 0 )                                                         //check user input is positive or not 
       {

	      for (i = 2; i < N; i++)                                         //using for loop to find num factor
	      {
		     if ( N % i == 0)
		     {
			    sum = sum + i;
		     }
	      }
	      
	      
	      if ( sum != N || sum == 1 )                                     //check is sum equal num or not
	      {
		     printf("No, entered number is not a perfect number\n");
	      }
	      
	      else
	      {
	      
		     printf("Yes, entered number is perfect number\n");
	      }
       }
       
       else
       {
	      printf("Error : Invalid Input, Enter only positive number\n");
       }
       return 0;
}
