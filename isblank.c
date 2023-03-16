/*
Name : Suraj Roy
Date : 15/06/2022
Description : WAP to implement your own isblank() function
Sample Input : Enter the character: e
Sample Output : Entered character is not blank character

*/

#include<stdio.h>

//function
int my_isblank(int ch)
{
       int ret;
       //checking condition
       if( ch == 32 || ch == 9 )
       {
	      ret = 1;
       }
       else
       {
	      ret = 0;
       }
//return the value to main
return (ret);
}

int main()
{
       //declaring variables
       char ch ;
       int ret;
       //taking value from user
       printf("Enter the character: ");
       scanf("%c", &ch);
       
       //function call
       ret = my_isblank(ch);

       //condition check on the based of return
       if ( ret )
	 
       {
	      printf("Entered character is a blank character\n");
       }
       else
       {
	      printf("Entered character is not blank character\n");
       }
       return 0;
}
