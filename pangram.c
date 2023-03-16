/*
Name  : Suraj Roy
Date : 07/07/22
Description : WAP to check given string is Pangram or not
Sample Input : Enter the string: The quick brown fox jumps over the lazy dog

Sample Output : The Entered String is a Pangram String
*/

#include <stdio.h>

//function pre declaration
int pangram(char *str);

int main()
{
       //declaring variable and array
       char str[100];   
       int count;
       
       //reading user input
       printf("Enter the string: ");
       scanf("%[^\n]", str);
       
       //function call
       count = pangram(str);
       
       //condition check
       if(count == 26)
       {
   	      printf("The Entered String is a Pangram String\n");
       }
       else
       {
   	      printf("The Entered String is not a Pangram String\n");
       }

       return 0;

}
//function 
int pangram(char *str)
{
       //declaration of variable and array
       int i, pan[26] = {0} , count = 0;

       //run loop untill null character if character alphabet present then array element at alphabet position is 1 else 0
       for(i = 0; str[i] != '\0'; i++)
       {
	      if('a' <= str[i] && str[i] <= 'z')
	      {
		     pan[str[i] - 'a'] = 1;
	      }
	      else if('A' <= str[i] && str[i] <= 'Z')
	      {
		     pan[str[i] - 'A'] = 1;
	      }
       }

       //counting number alphabet present is array
       for(i = 0; i < 26; i++)
       {
	      if(pan[i] == 1)
	      {
		     count++;
	      }
       }
       //return count to main
       return count;
}
