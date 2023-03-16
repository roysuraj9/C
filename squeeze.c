/*
Name : Suraj Roy
Date :08/07/2022
Description : Squeeze the character in s1 that matches any character in the string s2
Sample Input : 
Enter string1 : hello world
Enter string2 : lo
Sample Output :
After squeeze s1 : he wrd
*/

#include <stdio.h>

//function pre declaration
void squeeze(char *str1, char *str2);

int main()
{
       //declaration character array
       char str1[100], str2[100];

       //reading user input String 1 and String 2
       printf("Enter string1 : ");
       scanf("%[^\n]", str1);
    
       printf("Enter string2 : ");
       scanf("%s", str2);

       //function call
       squeeze(str1, str2);
    
       //display output
       printf("After squeeze s1 : %s\n", str1);
    
}
//function
void squeeze(char *str1, char *str2)
{
       //declaration variable
       int i, j, k;

       //string 2 loop
       for(i = 0; str2[i] != '\0' ; i++)
       {
	      //string 1 loop
	      for(j = 0; str1[j] != '\0'; j++)
	      {
		     //compare string 1 and string 2 if both equal then swap/change string1 character with upcoming character of string1
		     while(str2[i] == str1[j])
		     {
			    for(k = j; str1[k] != '\0'; k++)
			    {
              
				   str1[k] = str1[k + 1];
			    }
		     }
	      }
       }
}
