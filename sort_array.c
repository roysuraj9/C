/*
Name : Suraj Roy
Date : 29/06/2022
Description : Print the values in sorted order without modifying or copying array
Sample Input :
Enter the size of the array : 5   
Enter the 5 elements
7 8 5 2 4        

Sample Output :
After sorting: 2 4 5 7 8 
Original array values 7 8 5 2 4
*/

#include <stdio.h>

//pre declaration function
void print_sort(int *arr, int size);

int main()
{
       //declacing variable
       int size, iter;
       
       printf("Enter the size of the array : ");
       scanf("%d", &size);
    
       //initailize array
       int arr[size];
    
       printf("Enter the %d elements\n", size);
       for (iter = 0; iter < size; iter++)
       {
	      scanf("%d", &arr[iter]);
       }
       
       //function call
       print_sort(arr, size);
       
       return 0;
}

//function
void print_sort(int *arr, int size)
{
 
       //declare and initailize variable
       int iter, j,k, second_smallest, smallest = arr[0], largest = arr[0];
 
       //finding smallest and largest value
       for(iter = 0; iter < size; iter++)
       {
	 
	      if(largest < arr[iter])
	      {
		     largest = arr[iter];
	      }
	      if(smallest > arr[iter])
	      {
		     smallest = arr[iter];
	      }
       }
       
       
       //logic for sorting array and print    
       printf("After sorting: ");
       
       for (j = 0; j < size; j++)
       {
       
  	      second_smallest = largest;
  	      
  	    
	      for(iter = 0; iter < size; iter++)
	      {

       		     //finding second_smallest
		     if(arr[iter] < second_smallest && arr[iter] > smallest && arr[iter] != smallest)
		     {
			    second_smallest = arr[iter];

		     }
		     else {  second_smallest = arr[iter];}
		       
		        

	      }
			     
	      printf("%d ", smallest);
	      smallest = second_smallest;
       }
       
       //printing old array values
       printf("\nOriginal array values ");
       for(iter = 0; iter < size; iter++)
       {
	      printf("%d ", arr[iter]);
       }
       printf("\n");
             
}
