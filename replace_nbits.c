/*
Name : Suraj Roy
Date : 11-06-2022
Description : WAP to replace 'n' bits of a given number
Sample Input : 
Enter the number : 15 
Enter number of bits: 2
Enter the value: 1

Sample Output : Result = 13
*/

#include<stdio.h>

int replace_nbits(int num, int n, int val)
{
       int res;
       
       //using bitwise operation
       res = val & ((1 << n) -1 ) | num & (1 - (1 << n));

       //return value of res to main 
       return res;
}

int main()
{
       //declaring variables
       int num ,n ,val ,res = 0;

       //display and take value of num and n from user
       printf("Enter the number : ");
       scanf("%d", &num);
       printf("Enter number of bits: ");
       scanf("%d", &n);
       printf("Enter the value: ");
       scanf("%d", &val);
       
       res = replace_nbits(num ,n ,val);

       //display number set bit
       printf("Result = %d\n", res);

       return 0;
}
