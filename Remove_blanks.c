/*
Name : Suraj Roy
Date : 30/06/2022
Description : WAP to replace each string of one or more blanks by a single blank
Sample Input :
Enter the string with more spaces in between two words
             hi   hello 		welcome

Sample Output : 
hi hello welcome
*/
#include <stdio.h>

//pre declace function
void replace_blank(char *str);

int main()
{
       //declaration
       char str[100];
       
       //reading input from user
       //printf("Enter the string with more spaces in between two words\n");
       scanf("%[^\n]", str);

       //function call
       replace_blank(str);
       
       printf("%s\n",str);

       return 0;
}

//function
void replace_blank(char *str)
{

       //variable declaration 
       int i,j;

       //compare each character one by one
       for (i = 0;i < 100; i++)
       {
	      //replace extra/multiply untill single blank  
	      while(str[i - 1] == ' ' && str[i] == ' ' || str[i - 1] == ' ' && str[i] == '\t' || str[i - 1] == '\t' && str[i] == '\t' || str[i - 1] == '\t' && str[i] == ' ' )
	      {
       		     //convert previous tab character to space 
       		     if(str[i - 1] =='\t')
		     {
       			    str[i - 1] = ' ';
		     
		     }
		     //if new and previous character are blank
		     if( str [i -1] == ' ' && str[i] == ' ' || str [i - 1] == ' ' && str[i] == '\t' )
		     {
			    //replace extra blank character with forward character
			    for (j = i; j < 100; j++)
			    {
				   str[j] = str[j + 1];
			    }
		     }
		     
	      }     
 	      //if index 0 is blank character remove it by replace with forward character
		    
	      if (str[0] == ' ' || str[0] == '\t')
	      {
		     for (j = 0; j < 100; j++)
		     {
			    str[j] = str[j + 1];
		     }
	     
	      }
       }
       
}
