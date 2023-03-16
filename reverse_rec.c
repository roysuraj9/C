/*
Name : Suraj Roy
Date : 07/07/2022
Description : WAP to reverse the given string using recursive method
Sample Input : Enter any string : Enter any string : Chingu Pingu
Sample Output : Reversed string is ugniP ugnihC : gnirts yna retnE
*/

#include <stdio.h>
//function pre declaration
void reverse_recursive(char *str, int ind, int len);

int main()
{

       //variable declare and initialize
       int len=0, ind=0, i=0;
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
       reverse_recursive(str, ind, len);
    
       //display output
       printf("Reversed string is %s\n", str);
       return 0;
}

//function
void reverse_recursive(char *str, int ind, int len)
{
       //variable declaration
       int temp;

       //swapping character
       if( len - ind > 0 )
       {
                 len=len - 1;
	      temp = str[ind];
	      str[ind] = str[len];
	      str[len] = temp;
	      ind++;
	      //return value back to function call
	      reverse_recursive(str, ind, len);
       }
}
