/*
Name : Suraj Roy
Date : 23/06/2022
Description : WAP to remove duplicate elements in a given array
Sample Input : 
Enter the size of the array : 5
Enter the elements into the array: 12 3 65 33 3

Samople Output : After removing duplicates: 12 3 65 33
*/

#include <stdio.h>

//pre declaration function
void fun(int *arr1, int size, int *arr2, int *new_size);

int main()
{
       //decalring variables
       int size, i;
       //Read size from the user
       printf("Enter the size of the array : ");
       scanf("%d", &size);
       
       //declaring array and initialization new_size
       int arr1[size], new_size = size;
       int arr2[new_size];
       

       //Read elements into the array
       printf("Enter the elements into the array: ");
       for(i = 0 ; i < size; i++)
       {
	      scanf("%d", &arr1[i]);
       }
       
       //funtion call
       fun(arr1, size, arr2, &new_size);
        
       return 0;
}
//function
void fun(int *arr1, int size, int *arr2, int *new_size)
{
       //declare variable
       int i, j, k;
       
       for(i = 0; i < size; i++)
       {
	      for(j = i + 1; j < size; j++)
	      {
		     //finding duplicate
		     if(arr1[i] == arr1[j])
		     {
			    for(k = j; k < size; k++)
			    {
				   arr1[k] = arr1[k + 1];
			    }
			    // decrement new_size ,size and j
			    (*new_size)--;
			    size--;
			    j--;
		     }
		     
	      }
       }
       //storing element in arr2 after remove duplicate element
       for(i = 0; i < *new_size; i++)
       {
	      arr2[i] = arr1[i];
       }
       //display output
       printf("After removing duplicates: "); 

       for(i = 0; i < *new_size; i++)
       {
	      printf("%d ", arr2[i]);
       }
       printf("\n");
}   
