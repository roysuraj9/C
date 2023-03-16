/*
Name : Suraj Roy
Date : 14-06-2022
Description : WAP to implement Circular left shift
Sample Input : 
<pre>Enter the number : 15
Enter number of bits: 31
Sample Output :
Result in Binary: 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1
*/

#include<stdio.h>

//function call for circular left shift
int circular_left(unsigned int num, int n)
{
       int ret;
       ret = ((num & (((1 << n) - 1) << (32 - n))) >> (32 - n)) | (num << n);
       
       return ret;
}

//function call for printing bits
int print_bits(int ret)
{
       int i, res;

       printf("Result in Binary:");
       for (i = 31; i >= 0 ; i--)
       {
	      if( ret & (1 << i) )
	      {
		     res = 1;
	      }
	      else
	      {
		     res = 0;
	      }


       printf(" %d", res);
       }
       return res;
}

int main()
{
       //declaring variables
       unsigned int num;
       int n, res, ret;

       //display and take value of num and n from user
       printf("Enter the number : ");
       scanf("%d", &num);
       printf("Enter number of bits: ");
       scanf("%d", &n);

       //calling function first ret then res
       ret = circular_left(num, n);
       res = print_bits(ret);

       printf("\n");

       return 0;
}
