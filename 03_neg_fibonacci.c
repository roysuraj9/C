/*
Name : Suraj Roy
Date :27/05/2022
Description : WAP to generate negative Fibonacci numbers
Sample Input : Enter a number: 150
Sample Output : 0,1,-1,2,-3,5,-8,13,-21,34,-55,89,-144
*/

#include<stdio.h>

int main()
{

       int first = 0, second = 1,limit , next = 0,nextneg = -1;           //declaring variable

       printf("Enter a number: ");                         //read user input
       scanf("%d", &limit);

       if ( limit == 0 )
       {
	      printf("0\n");
       }
       
       else if( limit < 0 )                               //check user integer is negative or not
       {
	      
	      printf("%d,%d", first ,second);            //display 0 and 1
	      next = first - second;                    //subtracting 
	      
	      
	      while ( nextneg >= limit )			//use looop
	      {
	
		     printf(",%d", next);
		     first = second;                    //swap value
		     second = next;
		     
		     next = first -  second;
		     
		     if (next > 0)                        
		     {
			    nextneg = next*-1 ;
		     }
		      else
		     {
			    nextneg = next;
		     }
	      }
	      printf("\n");
       
	      
       }
       else
       {
	      printf("Invalid input\n");
       }
       return 0;       
}
