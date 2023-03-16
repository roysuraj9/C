/*
Name : Suraj Roy
Date : 05/08/2022
Description : WAP to define a macro swap (t, x, y) that swaps 2 arguments of type t
Sample Input :
1. Int
2. Char
3. Short
4. Float
5. Double
6. String
Enter you choice : 5
Enter the d_num1 : 2.3
Enter the d_num2 : 4

Sample Output :
After Swapping :
d_num1 : 4.000000
d_num2 : 2.300000
*/

#include<stdio.h>
#include <stdlib.h>
//MACRO defination 
#define SWAP(t, x, y)   \
{                       \
       t temp = x;      \
       x = y;           \
       y = temp;        \
}

int main()
{
       //declare variable
       int num1, num2, choice;
       char ch1, ch2, *str1, *str2;
       float f_num1, f_num2;
       short s_num1, s_num2;
       double d_num1, d_num2;
       //menu reading user input
       printf("1. Int\n2. Char\n3. Short\n4. Float\n5. Double\n6. String\nEnter you choice : ");
       scanf("%d", &choice);
       switch(choice)
       {
	      case 1:      
		     //read user input
		     printf("Enter the num1 : ");
		     scanf("%d", &num1);
		     printf("Enter the num2 : ");
		     scanf("%d", &num2);
		     //call MACRO
		     SWAP(int, num1, num2);
		     //display output
		     printf("After Swapping :\nnum1 : %d\nnum2 : %d\n", num1, num2);
		     break;
	       
	      case 2:      
		     printf("Enter the ch1 : ");
		     scanf(" %c", &ch1);
		     printf("Enter the ch2 : ");
		     scanf(" %c", &ch2);
		      
		     SWAP(char, ch1, ch2);
		     printf("After Swapping :\nch1 : %c\nch2 : %c\n", ch1, ch2);
		     break;		      
	       
	      case 3:		      
		     printf("Enter the f_num1 : ");
		     scanf("%f", &f_num1);
		     printf("Enter the f_num2 : ");
		     scanf("%f", &f_num2);
		      
		     SWAP(float, f_num1, f_num2);
		     printf("After Swapping :\nf_num1 : %f\nf_num2 : %f\n", f_num1, f_num2);
		     break;

	      case 4:    
		     printf("Enter the s_num1 : ");
		     scanf("%hd", &s_num1);
		     printf("Enter the s_num2 : ");
		     scanf("%hd", &s_num2);
		      
		     SWAP(short, s_num1, num2);
		     printf("After Swapping :\ns_num1 : %hd\ns_num2 : %hd\n", s_num1, s_num2);
		     break;
	       
	      case 5:    
		     printf("Enter the d_num1 : ");
		     scanf("%lf", &d_num1);
		     printf("Enter the d_num2 : ");
		     scanf("%lf", &d_num2);

		     SWAP(double, d_num1, d_num2);
		     printf("After Swapping :\nd_num1 : %lf\nd_num2 : %lf\n", d_num1, d_num2);
		     break;
		      
	      case 6:   
		     //dynamic memory allocation
		     str1 = malloc(100);
		     str2 = malloc(100);
		     printf("Enter the string1 : ");
		     scanf("%s", &*str1);
		     printf("Enter the string2 : ");
		     scanf("%s", &*str2);
		      
		     SWAP(char *, str1, str2);
		     printf("After Swapping :\nstr1 : %s\nstr2 : %s\n", str1, str2);
		     //free both memory
		     free(str1);
		     free(str2);
		     break;

	      default:
		     printf("Invalid Option");     		                 
       }
       return 0;
}
