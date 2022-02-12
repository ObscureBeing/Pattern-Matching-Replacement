/***************************************************************************************
* Name: replacement.c                                                                  *
* Author: Muskan vig                                                                   *
* Date created: 19 September 2020                                                      *
* Date modified:                                                                       *
* Purpose: Manipulates strings to embed colours and compares strings case insensitive  *
****************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_strstr.h"
#include "replacement.h"
#include "color.h"

/**********************************************************************************************
* Name: newString
* Imports: fullstr(char*), toRep(char*), byRep(char*), replacedString(char*), byC(char*)
* Exports: replacedString(char*)
* Purpose: Takes calloced string with required memory space
*          and keeps populating it by copying and concatinating 
*          with embedded colours.
***********************************************************************************************/

char* newString(char* fullstr, char* toRep, char* byRep, char* replacedString, char* byC)
{
    int l2 = strlen(toRep);
    int l3 = strlen(byRep);
    int i = 0;
    while (*fullstr) 
    { 
        /* Embeds colours in the new replaced string around replacements words */

        if (myStrStr(fullstr, toRep) == fullstr)
        { 
            strcat(replacedString+i, byC);
            i += 7; /*size of byC is 7 so jump 7 indexs*/
            strcpy(replacedString+i, byRep);
            i += l3; /*size of byRep is l3 so jump l3 indexes*/
            strcat(replacedString+i, RESET);
            i += 4; /*size of RESEST(defined in "color.h" is 4 so jump 4 indexs*/           
            fullstr += l2; 
        } 
        else
            replacedString[i++] = *fullstr++; 
    } 
  
    replacedString[i] = '\0'; /*initialises last character as null character*/

    return replacedString;
    
} /*END newString*/

/***************************************************************
* Name: stringCompare
* Imports: str1(char*), str2(char*)
* Exports: true(int)
* Purpose: Checks if two strings are equal, case insensitive.
*****************************************************************/

int stringCompare(char* str1, char* str2)
{
      int true = -1;

      /*checks each character of the strings */

      while (toupper(*str1) == toupper(*str2) && *str1 != '\0')
      {
          str1++;
          str2++;
      }

     /* If strings are equal then their address will point to null character \0 after while loop */

      if(*str1 == '\0' && *str2 == '\0')     
      {
          true = 0;
      }
 
      return true;

} /*END stringCompare */   
