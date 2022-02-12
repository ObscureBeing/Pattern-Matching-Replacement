/****************************************************
* Name: visualized.c                                *
* Author: Muskan vig                                *
* Date created: 20 September 2020                   *
* Date modified:                                    *
* Purpose: Show the visualized working of project.  *
*****************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_strstr.h"
#include "visualized.h"
#include "color.h"

/****************************************************************************************************************************
* Name: working
* Imports: finalStr(char*), replacedStr(char*), replacement(char*), n(int), highlight(char*), color1(char*), color2(char*)
* Export: none
* Purpose: Shows the visualied working with coloured string by clearing screen with ansi escape codes.
*****************************************************************************************************************************/

void working(char* finalStr, char* replacedStr, char* replacement, int n, char* highlight, char* color1, char* color2)
{
    char* cstr = (char*)calloc((n * 11) + strlen(finalStr) + (n * strlen(replacement)), sizeof(char*));
    char* initialStr = (char*)malloc(strlen(finalStr)+1);
    char* spaces = (char*)calloc(strlen(finalStr) + 1, sizeof(char*));
    char* spaces2 = (char*)calloc(strlen(finalStr) + 1, sizeof(char*));
    

    int i, check, j;

    /* + 11 for (7+4) size of colours and reset escape codes
       + 10 is size of "^ no Match" and "^ replaced"   
       + 1 for null character '\0' */

    char* noMatch = (char*)calloc(11 + 10 + 1, sizeof(char*)); 
    char* replaced = (char*)calloc(11 + 10 + 1, sizeof(char*));

    strcat(noMatch, color1);
    strcat(noMatch,"^ no match");
    strcat(noMatch, RESET);

    strcat(replaced, color2);
    strcat(replaced,"^ replaced");
    strcat(replaced, RESET);
 
    i = 0;
    check = 0;

    
    strcpy(initialStr, finalStr);
    printf("\nreplace: %s -> %s\n", replacedStr, replacement);
    printf("\n%s\n", finalStr);

    while(*finalStr)
    { 
        if (myStrStr(finalStr, replacedStr) == finalStr)
        {            
            strcat(cstr+i, highlight);
            i += 7;
            strcpy(cstr+i, replacement);
            i += strlen(replacement);
            strcat(cstr+i, RESET);
            i += 4;        
            finalStr += strlen(replacedStr); 

            strcat(cstr+i, finalStr);

            /*check to display strings by clear */

            if(check == 0)
            {
                sleep(1);
                printf("%s%s",CSIF, cstr);

               
                strcat(spaces2, spaces);
                printf("\n%s%s", spaces2, replaced);
                fflush(stdout);

                for(j = 0;j < strlen(replacement); j++)
                {
                    strcat(spaces, " ");
                }
            }
            else
            {

                sleep(1);
                printf("%s\x1b[1F%s",CSIK, cstr);

               
                strcat(spaces2, spaces);                
                printf("\n%s%s", spaces2, replaced);
                fflush(stdout);

                for(j = 0;j < strlen(replacement); j++)
                {
                    strcat(spaces, " ");
                }
 
            }/*Ends inner if*/

            check++;
        }
        else    
        {
            cstr[i++] = *finalStr++;
        
            sleep(1);
            printf("\x1b[900D\x1b[2K%s%s",spaces, noMatch);
            fflush(stdout);
           
            strcat(spaces, " ");
                      
        }/*Ends if*/
        cstr[i] = '\0';   

        sleep(1);
       
    }/*Ends while*/

    /*Freememory*/
    sleep(1); 
    free(cstr);
    free(initialStr);
    free(spaces);
    free(spaces2);
    free(noMatch);
    free(replaced);

    /*Pints freed memory to NULL*/
    cstr = NULL;
    initialStr = NULL;
    spaces = NULL;
    spaces2 = NULL;
    noMatch = NULL;
    replaced = NULL;
}/*End working*/

