/*********************************************************
* Name: pattern.c                                        *
* Author: Muskan vig                                     *
* Date created: 19 September 2020                        *
* Date modified:                                         *
* Purpose: Deals with pattern and string manipulations   *.
**********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_strstr.h"
#include "pattern.h"
#include "color.h"

/**************************************************************************************
* Name: countPattern
* Imports: str(char*), subStr(char*)
* Exports: count(int)
* Purpose: counts how many times pattern occurs and returns the count so that memory 
           can be malloced for other strings in main.
***************************************************************************************/

int countPattern(char* str, char* subStr)
{
    int i;
    int count = 0;
    
    for (i = 0; str[i] != '\0'; i++) 
    { 
         /*check for substring starting from the address where it isn't found yet */

        if(myStrStr(str+i, subStr) == str+i)
        { 
            count++; 

            /*Conditional compilation statements*/
            #ifdef DEBUG
            sleep(1);
            printf("\x1b[900D\x1b[2K(Occurence: %d) - Found at index: %d (gets updated after 1 sec)", count, i); 
            fflush(stdout);
            #endif

            i = i + strlen(subStr) - 1;
        }
    }
    printf("\n");

   return count;
} /*END countPattern*/

/***************************************************************************
* Name: colourStr
* Imports: inString(char*), findStr(char*), newStr(char*), cols(char*)
* Export: newStr(char*)
* Purpose: Returns string with colours embedded in it.
****************************************************************************/

char* colourStr(char* inString, char* findStr, char* newStr, char* colS)
{

    int i = 0;
    int l = strlen(findStr);
   
    while(*inString)
    {
         if (myStrStr(inString, findStr) == inString)
        { 
            strcat(newStr+i, colS);
            i += 7; /*7 is the size of escape code's string so jump 7 indexes*/
            strcpy(newStr+i, findStr);
            i += l; /*jumps length of findStr after copying word*/
            strcat(newStr+i, RESET);
            i += 4;   /*4 is the size of escape code to reset colour*/         
            inString += l; 
        } 
        else
            newStr[i++] = *inString++; 
    }

    newStr[i] = '\0';

    return newStr;
} /*END colourStr*/
