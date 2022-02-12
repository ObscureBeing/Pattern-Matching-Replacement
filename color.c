/*******************************************************************************
* Name: color.c                                                                *
* Author: Muskan vig                                                           *
* Date created: 19 September 2020                                              *
* Date modified:                                                               *
* Purpose: Deals with keeping track of colours to embed in different strings.  * 
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "replacement.h"

/************************************************************************************
* Name: checkColour
* Imports: colour(char*)
* Export: colour(char*)
* Purpose: returns a string with ansi escape codes for underlined coloured text
           according to user input(command line argument). Defining using 
           preprocessors in color.h.
************************************************************************************/

char* checkColour(char* colour)
{ 
    if(stringCompare(colour, "red") == 0)
        strcpy(colour, URED);
    else if (stringCompare(colour, "green") == 0)
        strcpy(colour, UGREEN);
    else if (stringCompare(colour, "blue") == 0)
        strcpy(colour, UBLUE);
    else if (stringCompare(colour, "yellow") == 0)
        strcpy(colour, UYELLOW);
    else if (stringCompare(colour, "magenta") == 0)
        strcpy(colour, UMAGENTA);
    else if (stringCompare(colour, "cyan") == 0)
        strcpy(colour, UCYAN);
    return colour;
} /*END checkColour*/

/*************************************************************************************************
* Name: background
* Imports: colour(char*)
* Export: colour(char*)
* Purpose: returns a string with ansi escape codes for highlighted (background) coloured text
           according to user input(command line argument). Defining using 
           preprocessors in color.h.
**************************************************************************************************/

char* background(char* colour)
{ 
    if(stringCompare(colour, "red") == 0)
        strcpy(colour, HRED);
    else if (stringCompare(colour, "green") == 0)
        strcpy(colour, HGREEN);
    else if (stringCompare(colour, "blue") == 0)
        strcpy(colour, HBLUE);
    else if (stringCompare(colour, "yellow") == 0)
        strcpy(colour, HYELLOW);
    else if (stringCompare(colour, "magenta") == 0)
        strcpy(colour, HMAGENTA);
    else if (stringCompare(colour, "cyan") == 0)
        strcpy(colour, HCYAN);
    return colour;
} /*End background*/

/*****************************************************************************
* Name: textColour
* Imports: colour(char*)
* Export: colour(char*)
* Purpose: returns a string with ansi escape codes for coloured text
           according to user input(command line argument). Defining using 
           preprocessors in color.h.
******************************************************************************/

char* textColour(char* colour)
{ 
    if(stringCompare(colour, "red") == 0)
        strcpy(colour, RED);
    else if (stringCompare(colour, "green") == 0)
        strcpy(colour, GREEN);
    else if (stringCompare(colour, "blue") == 0)
        strcpy(colour, BLUE);
    else if (stringCompare(colour, "yellow") == 0)
        strcpy(colour, YELLOW);
    else if (stringCompare(colour, "magenta") == 0)
        strcpy(colour, MAGENTA);
    else if (stringCompare(colour, "cyan") == 0)
        strcpy(colour, CYAN);
    return colour;
} /*EEnd textColour*/
