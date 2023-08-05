#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>                                                           //contains definition of bool function
#include<time.h>                                           // used to seed rand function with time to generate unique number everytime
#include<ctype.h>
#include<string.h>

int high_base(char*);                        //declaring the function to calculate highest base

int high_base(char *c)
{
	int max=0;                                                       //  initializing max as 0
	while(*c!='\0')                                                     // making loop
	{
		char chr=c[0];
	if(isdigit(chr))                                             //condition to check if character is digit or alphabet
	{
		int ans=chr-'0';
		if(ans>max)
		max=ans;
	}
	else if(isalpha(chr))
	{
		int ans=chr-'A'+10;
		if(ans>max)
		max=ans;
	}
	c++;
}
	return max+1;                                                      //adding 1 to the maximum digit in a string to find base
}



void generate_string(char*,int);                                      //declared  function with void return type

void generate_string(char str[],int num)
   {                                                                //defining the function and taking a string and number as arguments
	bool toss;                                                             // used to  generate a boolean value
	
	    for(int i=0;i<num;i++)
	  {
		toss= rand()%2;
	    if(toss==true)
	     str[i]= rand() % (70-65+1) + 65;
	    else
	     str[i]= rand() % (57-48+1) + 48;
      }
         str[num]=0;                                                      //returning a string taking initial value as 0
    }	

                      int main(void)
                {
                   srand(time(NULL));                                              // use the  time seed in our main function
                    char characters[11];                                               //declared an array of string data type
                     int n;
                     
                      for(int i=0;i<50;i++)                                            //for loop for run this process 50 times
	                   {
                        n=rand()%((10-3)+1)+3; 
                         generate_string(characters, n);                                          //calling  function
                          int base_of_str=high_base(characters);                                     //calling function 
                           printf("the highest base of %s is %d \n", characters, base_of_str);           //printing the highest base
                       }
     
                           return 0;
                }