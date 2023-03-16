/*
Name : Suraj Roy
Date : 13-06-2022
Description : WAP to get 'n' bits from given position of a number
Sample Input : 
Enter the number : 18
Enter number of bits: 3
Enter the pos: 5

Sample Output : Result = 2
*/

#include<stdio.h>

//function call
int get_nbits_from_pos(int num, int n, int pos)
{
       int res;
       //using bitwise operation
       res = (num & (((1 << pos) - 1) << 1)) >> (pos - n + 1);
       
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
       
       res = get_nbits_from_pos(num, n, pos);

       //display number set bit
       printf("Result = %d\n", res);

       return 0;
}
