/*
Name : Suraj Roy
Date : 11-06-2022
Description : WAP to get 'n' bits of a given number
Sample Input : 
Enter the number : 12
Enter number of bits: 3

Sample Output : Result = 4
*/

#include<stdio.h>

int get_nbits(int num, int n)
{
       int res;
       
       //1 left bitwise n time then substract with 1 then AND with num
       res = num & ((1 << n) - 1);

       //return value of res to main 
       return res;
}

int main()
{
       //declaring variables
       int num ,n ,res;

       //display and take value of num and n from user
       printf("Enter the number : ");
       scanf("%d", &num);
       printf("Enter number of bits: ");
       scanf("%d", &n);
       
       res = get_nbits(num,n );

       //display number set bit
       printf("Result = %d\n", res);

       return 0;
}
