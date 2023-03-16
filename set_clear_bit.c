/*
Name : Suraj Roy
Date : 01-06-2022
Description : WAP to check N th bit is set or not, If yes, clear the M th bit
Sample Input : 
Enter the number: 7
Enter 'N': 1
Enter 'M': 2

Sample Output : Updated value of num is 3
 */

#include<stdio.h>

int main()
{
       int num,n,i,m,new;                                           //declare variable

       printf("Enter the number: ");                               //display and taking value from user
       scanf("%d", &num);
       printf("Enter 'N': ");
       scanf("%d", &n);
       printf("Enter 'M': ");
       scanf("%d", &m);
       
	      
       if (num & 1 << n)                                          //check Nth bit have 1(set)  
       {
	      new = num & ~((1 << m ));                          //clear Mth bit
	      printf("Updated value of num is %d\n", new);
       }

       else
       {
	      printf("Updated value of num is %d\n", num);
       }

       return 0;
}
