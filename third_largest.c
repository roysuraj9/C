/*
Name : Suraj Roy
Date : 22/06/2022
Description : WAP to find 3rd largest element in an array
Sample Input : 
Enter the size of the array : 5
Enter the elements into the array: 3 2 5 7 8 4

Sample Output : Third largest element of the array is 5

*/
#include <stdio.h>
//function pre declaration
int third_largest(int *arr, int size);

int main()
{
       //decalring variables
       int size, ret, i;
       
       //Read size from the user
       printf("Enter the size of the array : ");
       scanf("%d", &size);
       
       int arr[size];

       //Read elements into the array
       printf("Enter the elements into the array: ");
       for(i = 0 ; i < size; i++)
       {
	      scanf("%d", &arr[i]);
       }

       //funtion call
       ret = third_largest(arr, size);
       
       printf("Third largest element of the array is %d\n", ret);
}
//function
int third_largest(int *arr, int size)
{
       //declare value
       int ret, i , first = arr[0], second, third;
       
       for ( i = 0; i < size ; i++)
       {
	      //first largest element
	      if (arr[i] > first)
	      {
	   	     first = arr[i];
	      }
       }
       //second largest element
       for (i= 0; i < size; i++)
       {	    
	      if( arr[i] < first && arr[i] > second)
	      {      
		     second = arr[i];
	      }
       }
       //third largest element
       for( i = 0; i < size; i++)
       { 
	      if (arr[i] < first && arr[i] < second && arr[i] > third)
	      {
		     third = arr[i];
		     ret = third;
	      }
       }
       //return value to main
       return ret;
}
