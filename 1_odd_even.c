/*
Name : Suraj Roy
Date 19/05/2022
Description : WAP to check if number is odd or even
Sample Input : Enter the value of 'n' : 34
Sample Output : 34 is positive even number
 */

#include<stdio.h>

int main()

{
       int n;
       printf("Enter the value of 'n' : ");
       scanf("%d", &n);                            //read user input
    
       if ( n > 0 )                                //check for positve integer
       {

	      if( n % 2 )                          //check for odd and even
	      {
		     printf("%d is positive odd number\n",n);
	      }
	      else
	      {
		     printf("%d is positive even number\n",n);
	      }
       }
       
       
       else if ( n < 0 )                          //check for negative integer
       {

	      if( n % 2 )                         //check for odd and even
	      {
		     printf("%d is negative odd number\n",n);
	      }
	      else
	      {
		     printf("%d is negative even number\n",n);
	      }
       }
       
       else                                      //if integer is 0
       {
              printf("%d is neither odd nor even\n",n);
       }

}
