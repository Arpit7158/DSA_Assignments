#include<stdio.h> 
#include<stdlib.h>  // header file which includes rand() function  


                 char arpit(int num)  
                       {
                         if( 0<= num  && num<=9)
                          {
                              return  '0' + num;   
                          }

                                               else if( num <=15)     //condition which converts integers from 10 to 15 into hexadecimal system using asci numbers
                                            {
                                              return 'A' + (num -10 ); 
                                            }

                                               else
                                               {
                                                 printf("Enter a valid number");
                                               }
                        }

    


      int main()
    {
       int num;
             int length;  
                        printf("Enter the length of string-");  //taking input of length of string
                                      scanf("%d", &length); 

    char temp[length+1];                  // created an array temp of size length+1

    for(int i =0 ; i< length ; i++)       //loop to generate  string of desired length 
    {
     num = rand() % 15; 
    temp[i] = arpit(num); //storing the generated character in temp array
     
    }

    temp[length] = '\0'; //null character of an array

int j = 0;
    while(temp[j]!= '\0')     //condition which prints string until null character is not reached
    {
        printf("%c",temp[j]); 
        j++;
    }
    return 0;
}