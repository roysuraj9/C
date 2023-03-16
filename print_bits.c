/*
Name : Suraj Roy
Date : 13-06-2022
Description : WAP to print 'n' bits from LSB of a number
Sample Input : 
Enter the number : 23
Enter number of bits: 10

Sample Output : Binary form of 23: 0 0 0 0 0 1 0 1 1 1
*/

#include<stdio.h>

//function
int print_bits(int num, int n)
{
       int res, i;
       //if n is greater than 32
       if(n > 32)
       {
	      n = 32;
       }
       //print bits
       for (i = n - 1; i >= 0; i--)
       {
	      if( num & (1 << i))
	      {
		     res = 1;
	      }
	      else
	      {
		     res = 0;
	      }
	     
	      printf(" %d", res); 
       }

       //return value of res to main 
       return res;
}

int main()
{
       //declaring variables
       int num, n, res;

       //display and take value of num and n from user
       printf("Enter the number : ");
       scanf("%d", &num);
       printf("Enter number of bits: ");
       scanf("%d", &n);

       printf("Binary form of %d:", num);
      
       //function call
       res = print_bits(num, n);	       

       printf("\n");

       return 0;
}
