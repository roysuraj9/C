/*
Name : Suraj Roy
Date 02/06/2022
Description : WAP to find the median of two unsorted arrays
Sample Input :
Enter the 'n' value for Array A: 6
Enter the 'n' value for Array B: 5
Enter the elements one by one for Array A: 4 3 7 5 6 2
Enter the elements one by one for Array B: 9 1 8 11 13

Sample Output : 
Median of array1 : 4.5
Median of array2 : 9
Median of both arrays : 6.75

 */

#include<stdio.h>

int main()

{
       //declaring variables
       int n ,m ,i ,j ,lo ,up ,temp;
       float median ,med1 ,med2 ;

       //displaying text and taking user input

       printf("Enter the 'n' value for Array A: ");
       scanf("%d", &m);                            
       printf("Enter the 'n' value for Array B: ");
       scanf("%d", &n);
       
       //declaring two array
       int arr1[m] ,arr2[n];

       //taking element of both array by user
       printf("Enter the elements one by one for Array A: ");

       for( i = 0 ;i < m ;i++)
       {
	      scanf("%d", &arr1[i]);
       }
       printf("Enter the elements one by one for Array B: ");

       for( i=0 ;i < n ;i++)
       {
              scanf("%d", &arr2[i]);
       }

       //bubble sorting array1
       for(i = 0 ;i < m ;i++)
       {
	      for (j = 0;j < m - i - 1 ;j++)
	      {
		     if(arr1[j] > arr1[j + 1])
		     {
			    temp = arr1[j];
			    arr1[j] = arr1[j + 1];
			    arr1[j + 1] = temp;
		     }
	      
	      
	      }
       }
       
       
       //bubble sorting array2   
       for(i = 0 ;i < n ;i++)
       {
              for (j = 0 ;j < n - i - 1; j++)
              {
                     if(arr2[j] > arr2[j + 1])
                     {
                            temp = arr2[j];
                            arr2[j] = arr2[j + 1];
                            arr2[j + 1] = temp;
                     }


              }
       }


       //for first array
       //first check array length is odd or even 
       if (m % 2)
       {
	      med1 = arr1[(m - 1) / 2];
	      printf("Median of array1 : %g\n", med1);
       }
       
       //if array length is even then take to two median and divide it by 2
       else
       {
	      lo = arr1[m / 2 - 1] ;
	      up = arr1[m / 2];

	      med1= ((float) lo + up) / 2;	
	      printf("Median of array1 : %g\n", med1);
       }



       //for second array
       if (n % 2 )     
       {
                  
	      med2 = arr2[(n - 1) / 2];
	      printf("Median of array2 : %g\n", med2);
                  
       }

       else
       {
	      lo = arr2[n / 2 - 1] ;
	      up = arr2[n / 2];

	      med2 = ((float)lo +up)/2;
	      printf("Median of array2 : %g\n", med2);
       }

       //print median of both array
       median = ((float) med1 + med2) / 2;
       printf("Median of both arrays : %g\n", median);

}
