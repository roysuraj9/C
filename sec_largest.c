/*
NAme : Suraj Roy
Date : 21/06/2022
Description : WAP to find 2nd largest element in an array
Sample Input : 
Enter the size of the array : 5
Enter the elements into the array: 12 3 65 33 32

Samople Output : Second largest element of the array is 33
*/

#include <stdio.h>

//pre declaration function
int sec_largest(int *arr, int size);

int main()
{
       //decalring variables
       int size, ret, i;
       //Read size from the user
       printf("Enter the size of the array : ");
       scanf("%d", &size);
       
       //declaring array
       int arr[size];

       //Read elements into the array
       printf("Enter the elements into the array: ");
       for(i = 0 ; i < size; i++)
       {
	      scanf("%d", &arr[i]);
       }

       //funtion call
       ret = sec_largest(arr, size);
       
       printf("Second largest element of the array is %d\n", ret);
}

int sec_largest(int *arr, int size)
{
       //declare value
       int ret, i , first = arr[0], second;
       
       for (i = 0; i < size ; i++)
       {
	      //first largest element
	      if (arr[i] > first)
	      {
	   	     first = arr[i];
	      }
       }
       
       //second largest element
       for (i = 0; i < size ; i++)
       {
	      if( arr[i] < first && arr[i] > second)
	      {      
		     second = arr[i];
		     ret = second;
	      }
       }
       //return value to main
       return ret;
}
