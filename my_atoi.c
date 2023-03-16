/*
Name : Suraj Roy
Date : 05/07/2022
Description : WAP to implement atoi function
Sample Input : Enter a numeric string : 4567asdcv
Sample Output : String to integer is 4567
*/
#include <stdio.h>

//declare function parameter
int my_atoi(const char *);

int main()
{
       char str[20];
    
       //reading input from user as character
       printf("Enter a numeric string : ");
       scanf("%s", str);
    
       //display integer value 
       printf("String to integer is %d\n", my_atoi(str));
       return 0;
}
//function
int my_atoi(const char *str)
{
       //initialize variables
       int i = 0 ,res = 0, sign = 1;
  
       // checking string is negative
       if (str[0] == 45)
       {
	      sign = -1; 
       }
       //is string positive
       else if(str[0] == 43) 
       { 
	      sign = 1;
       }
       // string start with numbers
       else if(str[0] >= 48 && str[0] <= 58)
       {
	      res = res * 10 + str[i] - 48;
       }
    
       //is string start with other then number,positive or negative sign
       else
       {
	      sign =0; 
       }
 
 
       for (i=1; str[i] != '\0'; i++)
       {
	      //if second position start with other number  
	      if(str[i] < 48 || str[i] > 58)
	      {
		     break;
	      }
	      res = res * 10 + str[i] - 48;
       }
  
       //return values to main
       return sign * res;
}
