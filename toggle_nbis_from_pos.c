/*
Name : Suraj Roy
Date : 13-06-2022
Description : WAP to toggle 'n' bits from given position of a number
Sample Input : 
Enter the number : 13
Enter number of bits: 2
Enter the pos: 4

Sample Output : Result = 21
*/

#include<stdio.h>

int toggle_nbits_from_pos(int num, int n, int pos)
{
       int res;
       
       //bitwise operation
       res =(num ^ ((1 << n) - 1) << (pos - n + 1));
       

       //return value of res to main 
       return res;
}

int main()
{
       //declaring variables
       int num, n, res, pos;

       //display and take value of num,pos and n from user
       printf("Enter the number : ");
       scanf("%d", &num);
       printf("Enter number of bits: ");
       scanf("%d", &n);
       printf("Enter the pos: ");
       scanf("%d", &pos);
       
       res = toggle_nbits_from_pos(num, n, pos);

       //display number set bit
       printf("Result = %d\n", res);

       return 0;
}
