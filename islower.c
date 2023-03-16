/*
NAme : Suraj Roy
Date : 15/06/2022
Description : WAP to implement your own islower() function
Sample Input : Enter the character: g
Sample Output : Entered character is lower case alphabet
*/

#include<stdio.h>

//function
int my_islower(int ch)
{
       int ret;
       //checking condition
       if( ch >= 97 && ch <= 122 )
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
       ret = my_islower(ch);

       //condition check on the based of return
       if ( ret )
	 
       {
	      printf("Entered character is lower case alphabet\n");
       }
       else
       {
	      printf("Entered character is not lower case alphabet\n");
       }
       return 0;
}
