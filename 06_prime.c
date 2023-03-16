/*
Name : Suraj Roy
Date : 05-06-2022
Description : WAP to print all primes using Sieve of Eratosthenes method
Sample Input : Enter the value of 'n' : 30
Sample Output : The primes less than or equal to 20 are : The primes less than or equal to 30 are : 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
 */

#include <stdio.h>

int main()
{
       //declare variables
       int i ,num ,j = 2;

       //taking user input
       printf("Enter the value of 'n' : ");
       scanf("%d", &num);

       //check condition
       if( num > 1 )
       {
	      //declare array
	      int arr[num];
	      
	      //storing element in form 2 to num value
	      for(i=2 ;i <= num ;i++)
	      {
		     arr[i] = 0;
	      }

	      //finding prime number in array
	  
	      while( i*i >= j)
	      {
		     for (i = 2; num>= j*i  ;i++)
		     {
			    arr[i* j] = 1;
		     }
		     j++;
	      
	      }
       
	      //displaying prime number arrray
	      printf("The primes less than or equal to %d are : 2", num );
	      for(i =3; i <= num ; i++)
	      {
		     if(arr[i] == 0)
			    printf(", %d",i);
	      }
	      printf("\n");
       }
       
       //display error
       else
       {
	      printf("Please enter a positive number which is > 1\n");
       }

	return 0;
}
