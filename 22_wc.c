/*
Name : Suraj Roy
Date : 02/07/2022
Description : WAP to count no. of characters, words and lines, entered through stdin
Sample Input :
 Hello World
welcome		world  
Bye 

Sample Output : 
Character count : 33
Line count : 2
Word count : 5
*/

#include<stdio.h>

int main()
{
       /*declaration of variable and  initialize*/
       int char_count =0, word_count = 0, line_count = 0;
       char ch, ch1;

       /*take character one by one from user input*/
       while((ch = getchar()) != EOF)
       {
       
	      /*increement character count*/
	      char_count++;

	      /*increement line count*/
	      if(ch == '\n')
	      {
		     line_count++;
	      }
	      
	      /*increement word count*/
	      if((ch == ' ' || ch == '\t' || ch =='\n') && char_count != 1)
	      { 
		     if(ch1 != ' ' && ch1 != '\t' && ch1 != '\n')
		     {
		     word_count++;
		     }
	      }	
	      ch1 = ch;	    
		    	    
       }

       /* if program is end without space,tab and newline*/
       if (ch == EOF && ch1 != ' ' && ch1 != '\t' && ch1 != '\n' && char_count != 0)
       {
       word_count++;
       }
       /*displaying output*/
       printf("\nCharacter count : %d\nLine count : %d\nWord count : %d\n", char_count, line_count, word_count);
       return 0;
}
