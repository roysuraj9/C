/*
Name : Suraj Roy
Date : 01-06-2022
Description : WAP to count number of set bits in a given number and print parity
Sample Input : Enter the number : 8
Sample Output : 
Number of set bits = 1
Bit parity is Odd
*/

#include<stdio.h>

int main()
{
       int num ,i ,count=0;                                                          //declaring variables
       
       printf("Enter the number : ");                                                //display and take value of num from user
       scanf("%d", &num);

       for (i =0 ;i < 32 ;i++)                                                       //for loop for to move in 32 bits
       {
	     if ( num & (1 << i) )                                                   //AND num to check each bits and if bit is 1 increase count
	     {
		    count ++;
	     }
       }
       
       printf("Number of set bits = %d\n", count);                                 //display number set bit

       count & 1 ? printf("Bit parity is Odd\n"):printf("Bit parity is Even\n");   //comparing count AND with 1 , if lsb is 0 even else odd

       return 0;
}
