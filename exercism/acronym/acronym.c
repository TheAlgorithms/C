#include <string.h>
#include <stdio.h>
#include <ctype.h>

char *abbreviate(const char *phrase)
{
    char str[80];
    strcpy(str, phrase);
    char *p_str = str;
    static char acr[80];
    strcpy(acr, "");

    /* for counting the words */
    int counter = 0;

    /* for position the words */
    int index = 0;

    /* for -loop variable */
    int i = 0;

    /* 
        counts the empty-characters. 
        for determine the number of words
    */
    while (p_str && (i < 80))
    {
        if (*p_str == ' ')
        {
            counter++;
        }
        if (i < 80)
        {
            p_str++;
            i++;
        }
    }

    i = 0;
    counter++;
    char words[counter][80];

    /* initalizes words-array with empty strings */
    for (i = 0; i < counter; i++)
    {
        strcpy(words[i],"");
    }

    /* rewind string */
    p_str = str;

    char *p_start = p_str;

    /* collects each word in array 'words' */
    while (p_str && (i <= 80))
    {
        if (*p_str == ' ')
        {
            *p_str = '\0';
            strncat(words[index], p_start, 80);
            index++;
            p_start = p_str + 1;
        }

        if (i <= 80)
        {
            p_str++;
            i++;
        }
    }

    /* adds the last word */
    *p_str = '\0';
    strncat(words[index], p_start, 80);
    index++;

    /* builds the actual acronym */
    for (i = 0; i < index; i++)
    {
        /* capitalize the first character */
        words[i][0] = toupper(words[i][0]);
        words[i][1] = '\0';
        strcat(acr, words[i]);
    }

    return acr;
}