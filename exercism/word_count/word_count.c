#include "word_count.h"
#include <string.h>

/*
    word_count: returns the full number of words in the input_text,
                otherwise an error code: (see below)

    error codes: EXCESSIVE_LENGTH_WORD     -1
                 EXCESSIVE_NUMBER_OF_WORDS -2

    The function manipulates the given structure of type word_count_word_t
    After that process the member count contains the number of occures.
*/
int word_count(const char *input_text, word_count_word_t *words)
{
    char word_list[MAX_WORDS][MAX_WORD_LENGTH];
    char input[1000];
    strcpy(input, input_text);
    char *p_str = input;

    /* index for iteration over input string */
    int index = 0;

    /* index for word_list */
    int index_list = 0;

    /* counts all words */
    int count_all = 0;

    /* for controlling the while loop */
    int loop = 1;

    /* for the for-loop */
    int i = 0;

    /* collects all words in the word_list */
    while (input[index] && loop)
    {
        if (input[index] == ' ')
        {
            input[index] = '\0';
            if (strlen(p_str) <= MAX_WORD_LENGTH)
            {
                if (index_list <= MAX_WORDS)
                {
                    strcpy(word_list[index_list], p_str);

                    /* sets pointer to the next position */
                    p_str = input + index + 1;
                    index_list++;

                    /* counts the word */
                    count_all++;
                }
                else /* error case too many words */
                {
                    count_all = EXCESSIVE_NUMBER_OF_WORDS;
                    loop = 0;
                }
            }
            else /* error case: word is too long */
            {
                count_all = EXCESSIVE_LENGTH_WORD;
                loop = 0;
            }
        }

        index++;
    }

    words->count = 0;

    /* make sure none error is occurred */
    if (loop)
    {
        /* collects the last word up to the \0-character. and counts it.*/
        strcpy(word_list[index_list], p_str);
        count_all++;

        for (i = 0; i <= index_list; i++)
        {
            if (strcmp(word_list[i], words->text) == 0)
            {
                words->count++;
            }
        }
    }

    /* returns the number of words or an error code */
    return count_all;
}
