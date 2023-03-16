/*
Name : Suraj Roy
Date : 15/07/2022
Description : WAP to print all possible combinations of given string.
Sample Input : 
Enter a string: bye

Sample Output : 
All possible combinations of given string :bye
bye
bey
ybe
yeb
eyb
eby
*/

#include<stdio.h> 
//function protype
void combination(char *str, int first, int len);

int my_strlen(char *str);

int main()

{
       //declaring the array and variable
       char str[100];
       int n, i, j;
    
       //read user input
       printf("Enter a string: ");
       scanf("%100[^\n]", str);
        
        
       //calling function my_strlen   
       n = my_strlen(str);
        
       //checking user enter same charcter
       for (i = 0; i < n; i++)
       {
	      for (j = i + 1; j < n; j++)
	      {
		     if(str[j] == str[i] )
		     {
			    printf("Error: please enter distinct characters.\n");
			    return 1;   
		     }
	      }
       }

       printf("All possible combinations of given string :%s\n", str);
       
       //calling function  combination
       combination(str, 0, n - 1); 
     
       return 0;
}
//function to find the length of the string
int my_strlen(char *str)
{
       char *ptr = str;
       while(*str++);
       return str - ptr - 1;
}

//funtion for from new combination
void combination(char *str, int first, int len)
{

       //declare variable
       int i;

       //logic for make combination
       if(first == len)
       {
	      printf("%s\n",str);
       }
       else
       {
	      for(i = first; i <= len; i++)
	      {
		     //declare temp as char for swap
		     char temp;

		     //swapping operation
		     temp = str[first];
		     str[first] = str[i];
		     str[i] = temp;

	     	     //calling the function recursively and increase first by 1 
     		     combination(str, first + 1, len);
		   
		     temp = str[first];
		     str[first] = str[i];
		     str[i] = temp;	
	      }
       }
}
