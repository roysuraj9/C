/*
NAme : Suraj Roy
Date : 15/06/2022
Description : WAP to implement your own ispunct() function
Sample Input : Enter the character: +
Sample Output : Entered character is punctuation character
*/

#include<stdio.h>

//function
int my_ispunct(int ch)
{
       int ret;
       //checking condition
       if( ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57 || ch >= 0 && ch <= 31 || ch ==127 || ch == 9 || ch == 32)
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
       ret = my_ispunct(ch);

       //condition check on the based of return
       if ( ret )
	 
       {
	      printf("Entered character is not punctuation character\n");
       }
       else
       {
	      printf("Entered character is punctuation character\n");
       }
       return 0;
}
