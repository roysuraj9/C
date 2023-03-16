/*
Name : Suraj Roy
Date : 05/08/2022
Description : WAP to define a macro SIZEOF(x), without using sizeof operator
Sample Input : ./a.out
Sample Output : 
Size of int : 4 bytes
Size of char : 1 bytes
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes
Size of short int : 2 bytes
Size of long long int : 8 bytes
Size of signed int : 4 bytes
Size of unsigned char : 1 bytes

*/

#include<stdio.h>
//macro defination
#define SIZEOF(x)      ((char*)(&x + 1) - (char*)&x)

int main()
{
       //declare variable
       int num;
       float f_num;
       char ch;
       double d_num;
       short int sh_num;
       long int l_num;
       long long int ll_num;
       unsigned int u_num;
       signed int s_num;
       unsigned char c;
       
       //macro call and display output
       printf("Size of int : %ld bytes\n", SIZEOF(num));
       printf("Size of char : %ld bytes\n", SIZEOF(ch));
       printf("Size of float : %ld bytes\n", SIZEOF(f_num));
       printf("Size of double : %ld bytes\n", SIZEOF(d_num));
       printf("Size of unsigned int : %ld bytes\n", SIZEOF(u_num));
       printf("Size of long int : %ld bytes\n", SIZEOF(l_num));
       printf("Size of short int : %ld bytes\n", SIZEOF(sh_num));
       printf("Size of long long int : %ld bytes\n", SIZEOF(ll_num));
       printf("Size of signed int : %ld bytes\n", SIZEOF(s_num));
       printf("Size of unsigned char : %ld bytes\n", SIZEOF(c));
       
       return 0;
}
