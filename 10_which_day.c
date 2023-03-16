/*
Name : Suraj Roy
Date : 25/05/2022
Description : WAP to find which day of the year
Sample Input : 
Enter the value of 'n' : 253
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 3

Sample Output : The day is Saturday
*/

#include<stdio.h>

int main()
{

       int n,s,val;           //initailazation all value

       printf("Enter the value of 'n' : ");                         //read user input
       scanf("%d", &n);

       if ( n > 0 && n <= 365 )
       {
	      printf("Choose First Day :\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");    //display menu to user
	      printf("Enter the option to set the first day : ");                                                                     //user enter the choice
	      scanf("%d",&s);
	      
	      if ( s <= 7 && s !=0 )                                                                                                           //check user enter valid input
	      {
		     
		     val=( n + s - 1 ) % 7;                                                                                          //finding the day of number
		     
		     switch(val)
		     {
			    case 1:
				   printf("The day is Sunday\n");
				   break;
			    case 2:
				   printf("The day is Monday\n");
				   break;
			    case 3:
				   printf("The day is Tuesday\n");
				   break;
			    case 4:
				   printf("The day is Wednesday\n");
				   break;
			    case 5:
				   printf("The day is Thursday\n");
				   break;
			    case 6:
				   printf("The day is Friday\n");
				   break;
			    case 0:
				   printf("The day is Saturday\n");
				   break;
		     }
	      }
	      
	      else
	      {
		     printf("Error: Invalid input, first day should be > 0 and <= 7\n");                                      //error display
	      }


       }

       else
       {
	      printf("Error: Invalid Input, n value should be > 0 and <= 365\n");                                          //error display
       }
       return 0;
}
