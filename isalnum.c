/*
NAme : Suraj Roy
Date : 15/06/2022
Description : WAP to implement your own isalnum() function
Sample Input : Enter the character: t
Sample Output : Entered character is alphanumeric character
*/

#include<stdio.h>

//function
int my_isalnum(int ch)
{
       int ret;
       //checking condition
       if( ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57)
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
       ret = my_isalnum(ch);

       //condition check on the based of return
       if ( ret )
	 
       {
	      printf("Entered character is alphanumeric character\n");
       }
       else
       {
	      printf("Entered character is not alphanumeric character\n");
       }
       return 0;
}
