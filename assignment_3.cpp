#include <stdio.h>
#include <stdlib.h>  // includes definition of rand function
#include <limits.h>  //used to define the min and max values of characters
#include <time.h>  // contains definitions of functions to get and manipulate date and time information


   int calculate_base(char* str) 

    {
       int max = INT_MIN;

               while (*str != '\0') 
               {
        
                char last_char = str[0];

               if (last_char >= 'A' && last_char <= 'F') 
               {
                     int value = (last_char - 'A') + 10;
                            if (value > max) 
                            {
                               max = value;
                            }
               } 
              
              else if (last_char >= '0' && last_char <= '9') 
           
           {
                 int value = (last_char - '0');
                 if (value > max) 
            {
                max = value;
            }
           }

                                        // Moves the pointer to  next character in the string
                str++;
           }

           return (max + 1);
}

char int_to_char(int num) 
{
    if (num >= 0 && num <= 9) 
    {
        return num + '0';
    } 
    
    else if (num >= 10 && num <= 15) 
    
    {
        return ('A' + (num - 10));
    }
                                                       // Handles the case when number is not in the range of 0 to 15.
    return '\0';
}

int main() 
{
    int length;
    printf("Enter length " ); //inputs length of string
    scanf("%d", &length);

    char* str = (char*)malloc((length + 1) * sizeof(char));

    
    
    srand((unsigned int)time(NULL));                        // Seeds the random number generator with current time

    
   
        for (int i = 0; i < length; i++) 
           {
                       int random_value = rand() % 15;
                    int corresponding_character = int_to_char(random_value);
                     str[i] = corresponding_character;
           }

    
         str[length] = '\0';

         printf("Given string: %s\n", str);

            int base = calculate_base(str);

          printf("Base: %d\n", base);

          free(str);

          return 0;
}