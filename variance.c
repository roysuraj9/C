/*
Name : Suraj Roy
Date : 16/07/2022
Description : Variance calculation with dynamic arrays
Sample Input : 
Enter the no.of elements : 6
Enter the 6 elements:
46 69 32 60 52 41

Sample Output : varince 147.666672
 */

#include <stdio.h>
#include<stdlib.h>

//function protype
float variance(int *arr, int n);

int main()
{

       //declaring variables
       int n, i;
       float var;

       //reading user input
       printf("Enter the no.of elements : ");
       scanf("%d", &n);
       printf("Enter the %d elements:\n", n);

       //declaring array dynamic
       int *arr = malloc(n * sizeof(int));

       //read element of array from user
       for(i = 0; i < n; i++)
       {
	      scanf("%d", &arr[i]);
       }

       //calling function
       var = variance(arr, n);
       //display output
       printf("Variance is  %f\n", var);
       
       return 0;       
}
//function
float variance (int *arr ,int n)
{
       //decaring variable
       int i, sum = 0, mean, sum1 = 0;
       
       //summing up all the value of array
       for(i = 0; i < n; i++)
       {
	      sum = sum + arr[i];
       }

       //finding mean by dividing sum by no of elements
       mean = sum / n;

       //finding deviation from the mean
       for(i = 0; i < n; i++)
       {
	      arr[i] = arr[i] - mean;
       }
       //finding squared deviations 
       for(i = 0; i < n; i++)
       {
	      arr[i] = arr[i] * arr[i];
       }
       //finding sum of squares
       for(i = 0; i < n; i++)
       {
	      sum1 = sum1 + arr[i];
       }
       //finding variance and returning to main
       return ((float) sum1) / n;
}
