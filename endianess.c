/*
Name : Suraj  Roy
Date : 21/07/2022
Description : WAP to convert Little Endian data to Big Endian
Sample Input : 
Enter the size: 4   
Enter any number in Hexadecimal: 78563412

Sample Output :
After conversion 12345678
*/

#include<stdio.h> 
int main()
{

       //declaration variables
       int size ; 
       
       //reading user input
       printf("Enter the size: ");
       scanf("%d", &size);
       
       //checking size user input
       if(size == 2)
       {
	      //declaration of variable
	      short int num, temp;

	      //reading user input 
	      printf("Enter any number in Hexadecimal: ");
	      scanf("%hx", &num);

	      //in pointer ptr store address of num
  	      char *ptr = &num;
	    
	      //performing swapping
	      temp = *ptr;
	      *ptr = *(ptr + 1) ;
	      *(ptr + 1) = temp;
	      
	      //display output
	      printf("After conversion %hx\n", num);
       }

       else if (size == 4)
       {
	      int num, temp, i;

	      //reading user input
	      printf("Enter any number in Hexadecimal: ");
	      scanf("%x", &num);

	      //in pointer ptr store address of num
	      char *ptr = &num;
	    
	      //performing swapping
 	      for(i = 0; i < size / 2; i++)
	      {
	      temp = *(ptr + i);
	      *(ptr + i) = *(ptr + size - i - 1) ;
	      *(ptr + size - i - 1) = temp;
	      }
	      
	      //display output
	      printf("After conversion %x\n", num);
       }
}
