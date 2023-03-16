/*
Name : Suraj Roy
Date : 02/08/2022
Description : Read n & n person names of maxlen 32. Sort and print the names 
Sample Input :
Enter number of strings : 4
Enter the 4 names of length max 32 characters in each
ironman
spiderman
hulk
captain
Sample Output :
The sorted names are:
captain
hulk
ironman
spiderman


*/
#include <stdio.h>
#include <stdlib.h>

//declaring functions
void sorting(char (*name)[32], int);
void my_strcpy(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);

int main()
{


	//declaring variables 
       int row, i;

       //reading user input
       printf("Enter number of strings : ");
       scanf("%d", &row);

       //declaring array of string
       char (*name)[32];
       name= malloc(sizeof(*name) * 32);
       //reading array element by user 
       printf("Enter the %d names of length max 32 characters in each\n", row);
       for(i = 0; i < row; i++)
       {
	      scanf("%s", *(name + i));
       }
       
       //calling sorting function
       sorting(name, row);
	
       //printing the names after sorting
       printf("The sorted names are:\n");
       for(i = 0; i < row; i++)
       {
	      printf("%s\n", *(name + i));	
       }
		
       free(name);
		
       return 0;
}

//sorting function
void sorting(char (*name)[32], int row)
{
       int i, j;
       char temp[32];
       for (i = 0; i < row; i++)
       {
	      for (j = i + 1; j < row; j++)
	      {
		     //comapring each string
		     if (my_strcmp(name[i], name[j]) > 0)
		     {
			    //swapping
			    my_strcpy(temp, name[i]);
			    my_strcpy(name[i], name[j]);
			    my_strcpy(name[j], temp);
		     }
	      }
       }
}
//my_strcpy function 
void my_strcpy(char *str1, char *str2)
{
       char temp[32] = {'\0'};
       int i = 0;
	
       //copying character by character
       while (str2[i] != '\0')
       {
	      str1[i] = str2[i];
	      i++;
       }
       str1[i] = '\0';
}

//my_strcmp function
int my_strcmp(char *str1, char *str2)
{
       while( (*str1 != '\0' && *str2 != '\0' ) && *str1 == *str2)
       {
	      str1++;
	      str2++;
       }

       //if string character are same
       if(*str1 == *str2)
       {
	      return 0;
       }

       //if string character are different 
       else
       {
	      return *str1 - *str2;
       }
}
