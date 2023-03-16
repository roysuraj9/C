/*
Name : Suraj Roy
Date : 25/05/2022
Description : WAP to generate AP, GP, HP series

Sample Input : Enter the number: 
Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 4
Enter the number of terms 'N': 9

Sample Output :
AP = 2, 6, 10, 14, 18, 22, 26, 30, 34
GP = 2, 8, 32, 128, 512, 2048, 8192, 32768, 131072
HP = 0.500000, 0.166667, 0.100000, 0.071429, 0.055556, 0.045455, 0.038462, 0.033333, 0.029412

*/

#include<stdio.h>

int main()
{
       int n ,i ,j ,count=0 ,A , R ,N ,ap ,gp , hp;                                   //declare variable
       float d ,s;
                                                                              //displaying and taking input from user
       printf("Enter the First Number 'A': ");
       scanf("%d", &A);
       
       printf("Enter the Common Difference / Ratio 'R': ");
       scanf("%d", &R);
       
       printf("Enter the number of terms 'N': ");
       scanf("%d", &N);
       
       if ( N >= 1)                                                                  //check number of term is value
       {
       
       ap = A ; gp = A ; hp = A ;
       
       printf("AP = %d",A);                                                          //printing first term of AP
       for(i = 1; i < N; i++)                                                        //for loop to excute untill N value
       {
	      ap = ap + R;                                                           //adding values

	  printf(", %d", ap);	                                                     //print new AP
	
       }
       printf("\n");                                                                 //print new line
       
       
       printf("GP = %d", A);

       for (i = 1 ; i < N; i++)
       {
	      gp = gp * R;                                                         //multiple operation from GP
	      printf(", %d", gp);
       }
       printf("\n");

       s = (float) 1 / hp;                                                        //doing type casting

       printf("HP = %f",s);

       for (i = 1 ; i < N; i++)
       {
              hp = hp + R;
	      d = (float) 1 / hp;
              printf(", %f", d);
       }
       printf("\n");
       }
       
       else
       {
	      printf("Invalid input\n");
       }


}
