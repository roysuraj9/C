/*
Name : Suraj Roy
Date :19/05/2022
Description : 
Sample Input : Enter a number: 150
Sample Output : 0,1,1,2,3,5,8,13,21,34,55,89,144
*/
#include<stdio.h>

int main()
{

       int first = 0, second = 1,limit, next = 0;           //initailazation all value

       printf("Enter a number: ");                         //read user input
       scanf("%d", &limit);

       if ( limit == 0 )
       {
	      printf("0\n");
       }
       
       else if( limit > 0 )                               //check user integer is positive or not
       {
	      
	      printf("%d,%d", first ,second);            //display 0 and 1
	      next = first + second;                    //sum two old output
	      
	      while ( next <= limit )			//use looop
	      {
		     
		     printf(",%d",next);
		     first = second;                    //swap value
		     second = next;
		     next = first +  second;
	      }
	      printf("\n");
       }
       else
       {
	      printf("Invalid input\n");
       }
       return 0;
}
