/*
Name : Suraj Roy
Date :13/08/2022
Description : WAP to Implement the student record using array of structures
Sample Input :
Enter no.of students : 1
Enter no.of subjects : 2
Enter the name of subject 1 : english
Enter the name of subject 2 : maths
----------Enter the student datails-------------
Enter the student Roll no. : 1
Enter the student 1 name : gohan
Enter english mark : 69
Enter maths mark : 32
----Display Menu----
1. All student details
2. Particular student details
Enter your choice : 1

Sample Output : 
All student details

Rollno    Name                          english   maths     Average        Grade
1         gohan                         69        32        50.500000      C
*/

#include<stdio.h>
#include <stdlib.h>
//define struct and it's member
struct student_record
{
       char name[30];
       int roll_no;
       int marks[20];
};
//function
void grade(float avg);
int main()
{
       //declare variable
       int std, n_sub, i, j, choice1, choice2, sum=0;
       float avg=0;
       
       //reading user input
       printf("Enter no.of students : ");
       scanf("%d", &std);
       printf("Enter no.of subjects : ");
       scanf("%d", &n_sub);
       char opt = 'y';

       struct student_record s[std];
       //allocated memory
       char **sub = (char **)malloc(sizeof(char *)*n_sub*30);
       
       //read user for subject name
       for(i = 0; i < n_sub; i++)
       {
	      *(sub + i) = (char *)malloc(sizeof(char)*30);
	      printf("Enter the name of subject %d : ", i + 1);
	      scanf("%s", *(sub + i));
       }
       
       //reading student details
       for(i = 0; i < std; i++)
       {
	      printf("----------Enter the student datails-------------\n");
	      printf("Enter the student Roll no. : ");
	      scanf("%d", &s[i].roll_no);
	      printf("Enter the student %d name : ", s[i].roll_no);
	      scanf("%s", s[i].name);
       
	      for(int j = 0; j < n_sub; j++)
	      {
		     printf("Enter %s mark : ", sub[j]);
		     scanf("%d", &s[i].marks[j]);
	      }
       }
       
       //do while
       do
       {
     
	      //display menu and read choice
	      printf("----Display Menu----\n1. All student details\n2. Particular student details\nEnter your choice : ");
	      scanf("%d", &choice1);
	      switch(choice1)
	      {
		     //for all student details
		     case 1:
			    //display column name
	 		    printf("\nAll student details\n");
			    
			    printf("\n%-10s%-30s","Rollno","Name");						
			    for(j = 0; j < n_sub; j++)
			    {
				   printf("%-10s", sub[j]);								
			    }
			    printf("%-15sGrade", "Average");						
			    
			    //display student details
		       	    for(i = 0; i < std; i++)
			    {
				   sum=0;
				   avg=0;
				   printf("\n%-10d%-30s",s[i].roll_no,s[i].name);	
				   //display marks and calcuted average
				   for(j = 0; j < n_sub; j++)								
				   {
					  printf("%-10d", s[i].marks[j]);
					  sum = sum + s[i].marks[j];	
				   }
				   //average
				   avg = (float)sum / n_sub;
				   printf("%-15f", avg);
				   //call function grade
				   grade(avg);
			    }
			    break;
		     
		     case 2:
			    printf("\n----Menu for Particular student----\n1. Name.\n2. Roll no.\nEnter you choice : ");
			    scanf("%d", &choice2);
			    
			    switch(choice2)
			    {
				   //on base of student name display output
				   case 1 :
				       	  {
						 //declare array
						 char s_name[30];
						 int pos = 0, flag = 0;
						 //read student name
						 printf("Enter the name of the student : ");
						 scanf("%s", s_name);
		       				 
						 //compare user input to list of student in struct
						 for(i = 0; i < std; i++)
						 {
							j=0;
						       	while(s_name[j] == s[i].name[j] && s[i].name[j] != '\0' && s_name[j] != '\0')
							{
							       s[i].name[j++];
							       s_name[j++];
							}
						       	if(s[i].name[j] == s_name[j])
							{
							       printf("%d  khk",i);
							       flag = 1;
							       pos = i;
							}
						 }
						 if(flag == 0)
						 {
							printf("\nERROR : Enter correct name");
							break;
						 }
						 //display detail of student
						 sum = 0;
						 avg = 0;
						 printf("\n%-10s%-30s","Rollno","Name");						
				       		 
						 for(j = 0;j < n_sub; j++)
				       		 {
				       			printf("%-10s", sub[j]);								
						 }
						 printf("%-15sGrade", "Average");						
			      
						 printf("\n%-10d%-30s", s[pos].roll_no, s[pos].name);	
						 for(j = 0; j < n_sub; j++)								
						 {
						       	printf("%-10d", s[pos].marks[j]);
							sum = sum + s[pos].marks[j];	
						 }
						 avg = (float)sum / n_sub;
						 printf("%-15f", avg);
						 grade(avg);
						 break;
					  }   
					  //on base of roll no of student
				   case 2 :
					  {
				   
						 int rollno, pos = 0, flag = 0;
						 //read student roll no
						 printf("Enter the roll no of the student : ");
						 scanf("%d", &rollno);
						 
						 //compare student roll no
						 for(i = 0; i < std; i++)
						 {
							if(rollno == s[i].roll_no)
							{
							       flag = 1;
							       break;
							}
						 }
						 pos = i;
				       		 if(flag == 0)
				       		 {
				       			printf("\nERROR : Enter correct roll no");
				       			break;
				       		 }
				       		 //display student deltail
				       		 sum=0;
				       		 avg=0;
				       		 printf("\n%-10s%-30s", "Rollno", "Name");						
						 for(j = 0; j < n_sub; j++)
						 {
							printf("%-10s", sub[j]);								
						 }
						 printf("%-15sGrade", "Average");						
						 
						 printf("\n%-10d%-30s", s[pos].roll_no, s[pos].name);	
						 for(j = 0; j < n_sub; j++)								
			       			 {
			       				printf("%-10d", s[pos].marks[j]);
				       			sum = sum + s[pos].marks[j];	
						 }
						 avg = (float)sum / n_sub;
						 printf("%-15f", avg);
					       	 grade(avg);
						 break;
					  }
				   default:
					  printf("Invalid Option");
			    }
			    break;
			    
		     default:
			    printf("Invalid Option");
	      }
	      printf("\n\nDo you want to continue to display(Y/y) : ");
	      getchar();
	      scanf("%c", &opt);
       }
       while(opt == 'y' || opt == 'Y');      
}
//function grade       
void grade(float avg)
{
	
       if(avg>=80)
       {
	      printf("A");
       }
       else if(avg < 80 && avg >= 60)
       {
	      printf("B");
       }
       else if(avg < 60 && avg >= 40)
       {
	      printf("C");
       }
       else if(avg < 40 && avg >= 20)
       {
	      printf("D");	
       }
       else
       {
	      printf("E");
       }
}
