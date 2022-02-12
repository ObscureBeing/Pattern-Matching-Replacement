/*********************************************************************************************
* Name: pattern_matching_replacement.c                                                       *
* Author: Muskan vig                                                                         *
* Date created: 17 September 2020                                                            *
* Date modified:                                                                             *
* Purpose: Takes command line arguments to find and replace strings with desired colours     *
* and shows the working.                                                                     *
**********************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "pattern.h"
#include "replacement.h"
#include "color.h"
#include "visualized.h"

int main(int argc, char** argv)
{ 
    int len = strlen(argv[1]);
    int subLen = strlen(argv[2]);
    int replacementLen = strlen(argv[3]);
    int count;
 
   /* X sizeof(char) omiited as it always 1*/
   
    char* str = (char*)malloc(len + 1); 
    char* subStr = (char*)malloc(subLen + 1);
    char* replacement = (char*)malloc(replacementLen + 1);

    char* ofCol = (char*)malloc(7 + 1);         /* +1 is for '\0' null character */
    char* HCol = (char*)malloc(7  + 1);        /* 7 for colour ansi escape codes length */ 
    char* byCol = (char*)malloc(7 + 1);
    char* col = (char*)malloc(7 + 1);
    char* col2 = (char*)malloc(7 + 1);
    char* col3 = (char*)malloc(7 + 1);

    char* noMatchCol = (char*)malloc(7 + 1);
    char* replacedCol = (char*)malloc(7 + 1);
 
    char* replacedString;
    char* newStrC;

    system("clear");

    strcpy(str,argv[1]);
    strcpy(subStr,argv[2]);
    strcpy(replacement,argv[3]);
    strcpy(ofCol, argv[4]);
    strcpy(noMatchCol, argv[4]);
    strcpy(replacedCol, argv[5]);
    strcpy(byCol, argv[5]);
    strcpy(HCol, argv[5]);

    count = countPattern(str, subStr); /* get the count of pattern's occurence */

    /* - (count) * subLen as n substrngs will be replaced
       + (count) * replacementLen as n replacement strings will be there
       + 11 because 7 is string length of colour ansi escape codes
                and 4 is length of resetting the colour escape code. */ 

    replacedString = (char*)calloc(len - (count * subLen) + (count * replacementLen) + 11 + 1, sizeof(char*));
    newStrC = (char*)calloc(len + 11 + 1, sizeof(char*));

    /*Calls required funcions: working(), background(), testcolour() for visualized working*/
    
    strcpy(col, background(HCol));
    strcpy(col2, textColour(noMatchCol));
    strcpy(col3, textColour(replacedCol));
    working(str, subStr, replacement, count, col, col2, col3);
    
    /*Calls checkColour(), colourStr() and newString() to display the initial and final string
      with embedded colours.*/

    /*FINAL DISPLAY*/
    strcpy(col, checkColour(ofCol));
    colourStr(str, subStr, newStrC, col);

    strcpy(col, checkColour(byCol));
    newString(str, subStr, replacement, replacedString, col);
    
    system("clear");

    /* prints conditional printing indexes */
    count = countPattern(str, subStr);

    /* prints strings with embedded colours */

    printf("\n%s\n", newStrC); 
    printf("%s\n", replacedString);
  
    /* free memory to avoid memory leakage */   

    free(str);
    free(subStr);
    free(replacement);
    free(replacedString);
    free(newStrC);
    free(ofCol);
    free(byCol);
    free(HCol);
    free(col);
    free(col2);
    free(col3);
    free(noMatchCol);
    free(replacedCol);

    /* point freed memory to NULL, just a good practice */

    str = NULL;
    subStr = NULL;
    replacement = NULL;
    replacedString = NULL;
    newStrC = NULL;
    ofCol = NULL;
    byCol = NULL;
    HCol = NULL;
    col = NULL;
    col2 = NULL;
    col3 = NULL;
    noMatchCol = NULL;
    replacedCol = NULL;
   
    return 0;
}/*End main*/

