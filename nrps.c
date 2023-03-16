/*
Name : Suraj Roy
Date : 16/07/2022
Description : Generate consecutive NRPS of length n using k distinct character
Sample Input : 
Enter the number characters C : 3
Enter the Length of the string N : 21
Enter 3 distinct characters : bye

Sample Output :
Possible NRPS is byeyebebybyeyebebybye
*/

#include <stdio.h>

//function protype
void nrps(char *str, int size, int len);

int main()
{
       //declaration of variables
       int j, i, size, len;

    
       //read the input from the user
       printf("Enter the number characters C : ");
       scanf("%d", &size);
       printf("Enter the Length of the string N : ");
       scanf("%d", &len);

       //character array
       char str[size];
       
       //read input from user
       printf("Enter %d distinct characters : ", size);
      
       for (i = 0; i < size; i++)
       {
	      scanf("\n%c", &str[i]);
       }
    
       // check for distinct characters
       for (i = 0; i < size; i++)
       {
      	      for (j = i + 1; j < size; j++)
	      {
		     if(str[j] == str[i] )
		     {
			    printf("Error: values are not distinct.\n");
			    return 1;
		     }
	      }
       }
       
       printf("Possible NRPS is ");
       //function call
       nrps(str, size, len);
       printf("\n");
       return 0;
}

//function
void nrps(char *str , int size, int len)
{
       //delclaring variables
       int i, count = 0; 
    
       //condition for making not repeat series
       for (i = 0; i < len; i++)
       {
	      if(i % size == 0 && i != 0)
      	      {
		     count++;
	      }
      	      printf("%c", *(str + ((i + count) % size)));
       }
}
