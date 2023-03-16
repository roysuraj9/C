/*
Name : Suraj Roy
Date : 07/07/2022
Description : WAP to reverse the given string using iterative method
Sample Input : Enter any string : Enter any string : Chingu Pingu
Sample Output : Reversed string is ugniP ugnihC : gnirts yna retnE
*/

#include <stdio.h>
//function pre declaration
void reverse_iterative(char *str,int first , int len);

int main()
{

       //variable declare and initialize
       int len=0, ind=0, i;
       char str[30];
    
       //reading user input
       printf("Enter any string : ");
       scanf("%[^\n]", str);
       
       //find length of string
       for (i = 0; str[i] != '\0'; i++)
       {
	      len++;
       }
  
       //function call
       reverse_iterative(str, ind, len);
    
       //display output
       printf("Reversed string is %s\n", str);
}
//function
void reverse_iterative(char *str, int ind, int len)
{
       //variable declaration
       int i, temp;

       //swapping character
       for(i = 0; i < len / 2; i++)
       {
	      temp = str[i];
	      str[i] = str[len - i - 1];
	      str[len - i - 1] = temp;
       }
}
