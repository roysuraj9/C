/*
Name : Suraj Roy
Date : 08/07/2022
Description : WAP to implement itoa function
Sample Input : Enter the number : +7689
Sample Output : Integer to string is 7689
*/

#include <stdio.h>

//prefunction declaration
void itoa(int num, char *str);

int main()
{
       //declaration of variables
       int num, temp, t, rev = 0;
       char str[10];
    
       //reading input from user
       printf("Enter the number:");
       scanf("%d", &num);
       printf("%d\n", num);

       if(num >= 2222)
       {
	      num = 0;
       }

       //initailize temp to num
       temp = num;

       //reversing number
       while(temp != 0)
       {
	      t= temp %10;
	      temp = temp / 10;
	      rev = 10 * rev + t;
       }
       num = rev;
      
       //function call 
       itoa(num, str);
    
       //display output
       printf("Integer to string is %s\n", str);
}
void itoa(int num, char *str)
{
       //declaration variable
       int r;

       //for negative number
       if (num < 0)
       {

	      num = num * -1;
	      *str++ = '-';
       }

       // for zero number
       if(num == 0)
       {
	      *str++ = '0';
       }

       //store integer value one by one in string array
       while( num != 0)
       {
	      r = num % 10;
	      num = num / 10;
	      *str++ = 48 + r;
       }
       *str = '\0';
}			
