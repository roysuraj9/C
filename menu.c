/*
Name : Suraj Roy 
Date : 04/08/2022
Description: Provide a menu to manipulate or display the value of variable of type t
Sample Input and Sample output :
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. char
2. short
3. int
4. float
5. double
1
Enter the char : a
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
[0] -> a(char)

*/

#include<stdio.h>
#include<stdlib.h>
//function defination
void add_element(int choice2 ,void *ptr);
void display(void *ptr);
void remov(void *ptr, int index);
//declare static variable
static int ch1_flag = 0, ch2_flag = 0, short_flag = 0, int_flag = 0, float_flag = 0, double_flag = 0; 

int main()
{
       //allocated memory
       void *ptr = malloc(8);
       //declare variable
       int choice, choice2, q = 1, index;
       
       //do loop
       do
       {
	      //reading user input
	      printf("Menu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n");
	      printf("Choice ---> ");
	      scanf("%d",&choice);
	      //base on user input switch 
	      switch(choice)
	      {
		     case 1:
			    //read user input
			    printf("Enter the type you have to insert:\n1. char\n2. short\n3. int\n4. float\n5. double\n");
			    scanf("%d", &choice2);
		
			    //function call
			    add_element(choice2 ,ptr);
			    break;
			    
		     case 2:
			    //function call to display output
			    display(ptr);
			    //read user input to delete element
			    printf("Enter the index value to be deleted : ");
			    scanf("%d", &index);
			    printf("index %d successfully deleted.\n", index);
			    
			    //call fuction to remove element
			    remov(ptr, index);
			    break;
			    
		     case 3:
			    //function call to display output
			    display(ptr);
			    break;;
		     case 4:
			    //to exit the loop to terminate program
			    q = 0;
			    break;
			    
		     default:
			    printf("Invalid Option\n"); 

	      }

       }
       while(q == 1);
       return 0;

}
//function add_element
void add_element( int choice2, void *ptr)
{
       switch(choice2)
       {
	      case 1:
		     //first check in flag value then read user input
		     if(ch1_flag == 0 && double_flag == 0)
		     {
			    printf("Enter the char : ");
			    scanf(" %c" , &*((char*)ptr + 0 * sizeof(char)));
			    //change flag value from 0 to 1
			    ch1_flag = 1;
		     }
					  
		     else if(ch1_flag == 1 && ch2_flag == 0 && double_flag == 0)
		     {
			    printf("Enter the char : ");
			    scanf(" %c" , &*((char*)ptr + 1 * sizeof(char)));
			    ch2_flag = 1;
		     }
		     //error if memory already occupied
		     else
		     {
			    printf("Error : Can't allocated memory\n");
		     }
		     break;
	      case 2:
		     if(short_flag == 0 && double_flag == 0)
		     {
			    printf("Enter the short : ");
			    scanf("%hd" , &*((short*)ptr + 1 * sizeof(short)));
			    short_flag = 1;
		     }
		     else
		     {
			    printf("Error : Can't allocated memory\n");
		     }
		     break;
	      case 3:
		     if(int_flag == 0 && float_flag == 0 && double_flag == 0)
		     {
			    printf("Enter the int : ");
			    scanf("%d" , &*((int*)ptr + 1 * sizeof(int)));
			    int_flag = 1;
		     }
		     else
		     {
			    printf("Error : Can't allocated memory\n");
		     }
		     break;
	      case 4:
		     if(int_flag == 0 && float_flag == 0 && double_flag == 0)
		     {
			    printf("Enter the float : ");
			    scanf("%f", &*((float*)ptr + 1 * sizeof(float)));
			    float_flag = 1;
		     }
		     else
		     {
			    printf("Error : Can't allocated memory\n");
		     }
		     break;
	      case 5:
		     if(ch1_flag == 0 && short_flag == 0 && int_flag == 0 && float_flag == 0 && double_flag == 0)
		     {
			    printf("Enter the double : ");
			    scanf("%lf" , &*((double*)ptr));
			    double_flag = 1;
		     }
		     else
		     {
			    printf("Error : Can't allocated memory\n");
		     }
		     break;

	      default:
		     printf("Invalid Option");
       }
}

void remov(void *ptr, int index)
{      		    
       int pos = 0;
       
       //first check flag value is 1 then compare index to pos and increement pos value
       if(ch1_flag == 1)
       { 
	      if (index == pos++)
	      {
		     //convert flag value to 0
		     ch1_flag = 0;
	      }   
       }
	     
       if(ch2_flag == 1)
       {
	      if (index == pos++)
	      {
		     ch2_flag = 0;
	      }  
       }
       if(short_flag == 1)
       {
	      if (index == pos++)
	      {
		     short_flag = 0;
	      } 
       }
       if(int_flag == 1)
       {
	      if (index == pos++)
	      {
		     int_flag = 0;
	      }
       }
       if(float_flag == 1)
       {
	      if(index == pos++)
	      {
		     float_flag = 0;
	      }
       }
	      
       if(double_flag == 1)
       {
	      if (index == pos++)
	      {
		     double_flag = 0;
	      } 
       }
}

//function to display element
void display(void *ptr)
{
       int pos = 0;
       //if flag is 1 then display value with index pos of element
       if(ch1_flag == 1)
       {
	      printf("[%d] -> %c(char)\n", pos++, *((char*)ptr + 0 * sizeof(char)));
       }	     

       if(ch2_flag == 1)
       {
	      printf("[%d] -> %c(char)\n", pos++, *((char*)ptr + 1 * sizeof(char)));
       }
       
       if(short_flag == 1)
       {
	      printf("[%d] -> %hd(short)\n" , pos++, *((short*)ptr + 1 * sizeof(short)));
       }	   
       
       if(int_flag == 1)
       {  
	      printf("[%d] -> %d(int)\n" , pos++, *((int*)ptr + 1 * sizeof(int)));
       }	      

       if(float_flag == 1)
       {
	      printf("[%d] -> %f(float)\n" , pos++, *((float*)ptr + 1 * sizeof(float)));
       }	        
       if(double_flag==1)
       {
	      printf("[%d] -> %lf(double)\n" , pos, *((double*)ptr));
       }
}
