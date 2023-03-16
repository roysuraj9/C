/*
Name : Suraj Roy
Date : 04/07/2022
Description : WAP to implement getword function
Sample Input : Enter the string : Bye Hello
Sample Output : You entered Bye and the length is 3
 */
#include <stdio.h>
//declaring function parameter
int getword(char *str);

int main()
{
       //declaring variable and string
       int len;
       char str[100];

       //reading input from user
       printf("Enter the string : ");
       scanf(" %[^\n]", str);

       //calling function
       len = getword(str);

       //displaying output
       printf("You entered %s and the length is %d\n", str, len);
       return 0;
}
//function
int getword(char *str)
{
       //declaring variable
       int len = 0;
  
       //for counting length of first word of string 
       while(*str != ' ' && *str != '\t' && *str != '\0')
       {
	      //increement length and string position till condition true
	      len++;
	      str++;
       
       }
       //convert space and tab to NULL
       *str = '\0';
       //return value to main
       return len;       
}
