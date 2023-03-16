/*
Name : Suraj Roy
Date : 10/07/2022
Description : WAP to implement strtok function
Sample Input : 
Enter the string  : hello;world::;to';the;;'the[]'';''world
Enter the delimeter : ;'[]:
Sample Output :
Tokens :
hello
world
to
the
the
world 
*/

#include <stdio.h>

char *my_strtok(char *str, const char *delim);

int main()
{

       //declaration of two character array
       char str[50], delim[50];
    
       //reading string and delimiter from the user 
       //printf("Enter the string  : ");
       scanf("%s", str);
    
       //printf("Enter the delimeter : ");
       scanf("\n%s", delim);
    
       //function call
       char *token = my_strtok(str, delim);
       printf("Tokens :\n");
    
       //calling function again and again untill token not to null
       while (token)
       {
	      printf("%s\n", token);
	      token = my_strtok(NULL, delim);
       }
       return 0;
}
//function
char *my_strtok(char *str, const char *delim)
{
       //declaring variable
       static int i;
       static char *str1;	
       int  j, start = i;

       //copying str in str1
       if(str!=NULL)
       {
      	      str1 = str;
       }

       //comparing str to delim till string not equalto null
       while(str1[i] != '\0')
       {
	      j = 0;	
	      while(delim[j] != '\0')
	      {		
		     //string character equal to delim change the character to null
		     if(str1[i] == delim[j])
		     {
			    str1[i] = '\0';
			    i = i+1;

			    if(str1[start] != '\0')
			    {
				   return (&str1[start]);
			    }
		    	    else
	    		    {
				   //move to next string after the delimiter
   				   start = i;
				   i--;
				   break;
			    }
		     }
		     j++;
	      }
	      i++;		
       }
       //terminate while loop
       str1[i] = '\0';
       if(str1[start] == '\0')
       {
		return NULL;
       }

       else
       {
      	      return &str1[start];
       }    
}
