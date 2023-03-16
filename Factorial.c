/*
Name : Suraj Roy
Date : 24/06/2022
Description : WAP to find factorial of given number using recursion
Sample Input :Enter the value of N : 6
Sample Output : Factorial of the given number is 720


*/

#include <stdio.h>

int main()
{
       //declaring variable
       static int num;
       static unsigned long long int fact = 1;
       static int y = 1;
       
       // read input from user one time
       if (y ==1)
       {
	      printf("Enter the value of N : ");
	      scanf("%d", &num);
       }
       y--;

       //condition check only positive input should pass
       if (num > 0)
       {
	      //factorial logic
	      fact = fact * num--;
	      //display output once 
	      if(num < 1)
	      {
		     printf("Factorial of the given number is %llu\n",fact);
	      }
       }
       //when input is zero
       else if (num == 0)
       {
	      printf("Factorial of the given number is 1\n");
       }
       //negative input error
       else
       {
	      printf("Invalid Input\n");
       }
       //condition for main() function call and terminate
       if(num > 0 )
       {
	      main();
       }
       return 0;
}
