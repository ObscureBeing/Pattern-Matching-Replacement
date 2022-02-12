/****************************************************
* Name: my_strstr.c                                 *
* Author: Muskan vig                                *
* Date created: 18 September 2020                   *
* Date modified:                                    *
* Purpose: Check if there is a substring in string. *
*****************************************************/

#include <stdio.h>
#include <ctype.h>
#include "my_strstr.h"

/*******************************************************
* Name: myStrStr
* Imports: string(char*), subString(char*)
* Exports: result(char*)
* Purpose: Returns memory address of found substring.
********************************************************/

char* myStrStr(char* string, char* subString)
{
    char* result = NULL; /* returns NULL if substring not found */

    while (*string) 
    {
        char* begin = string;
        char* pattern = subString;
            
        /*First character of sting matches, enter the loop*/

        while (*string && *pattern && (toupper(*string)) == toupper(*pattern))        
        {
            string++;
            pattern++;
        }
    
        if (!*pattern)  /* sub string found, store the address */
        {
            result = begin;
            string = " ";
        } 
        else 
        {                 
            string = begin + 1;
        }
    
    }

     /* retuns memory address where substring is found */

    return result;

} /*END myStrStr*/
