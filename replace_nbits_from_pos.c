/*
Name : Suraj Roy
Date : 14-06-2022
Description : WAP to put the (b-a+1) lsb’s of num into val[b:a]
Sample Input : 
Enter the value of 'num' : 15
Enter the value of 'a' : 2
Enter the value of 'b' : 5
Enter the value of 'val': 174

Sample Output : Result : 190
*/

#include<stdio.h>

//function call
int replace_nbits_from_pos(int num, int a, int b, int val)
{
       int res, get, clear, n;

       //performing given equation
       n = b -a + 1;
       
       //extract n bits from num
       get=(num & ((1 << n) - 1)) << (b - n + 1);
       
       //clear n bits from position b
       clear=(val & ~(((1 << n) - 1) << (b - n + 1)));

       //merging get and clear
       res= get | clear;

       //return value of res to main 
       return res;
}

int main()
{
       //declaring variables
       int num, val, a, b, res = 0;

       //display and take value of num,a,b and val from user
       printf("Enter the value of 'num' : ");
       scanf("%d", &num);
       printf("Enter the value of 'a' : ");
       scanf("%d", &a);
       printf("Enter the value of 'b' : ");
       scanf("%d", &b);
       printf("Enter the value of 'val': ");
       scanf("%d", &val);
       
       res = replace_nbits_from_pos(num, a, b, val);

       //display number set bit
       printf("Result : %d\n", res);

       return 0;
}
