#include <stdbool.h>
#include <string.h>

/*
    is_isogram: returns true if the given string a isogram, otherwise false.
*/
bool is_isogram(const char phrase[]) 
{

    /* use 'unsigned' because of the function strlen(...) */
    unsigned int i = 0;
    unsigned int j = 0;

    /* the current read character in the first for-loop */
    char current_char = ' ';

    /* return status */
    bool status = true;

    /* contains the length of the given string */
    unsigned int len_phrase = strlen(phrase);

    for (i = 0; i < len_phrase; i++ ) 
    {
        current_char = phrase[i];

        /* makes sure the current character has no repetition */
        for (j = i+1; j < len_phrase; j++)
        {
            if (current_char == phrase[j])
            {
                status = false;

                /* 
                    because the given string is none isogram.
                    that means we can exit the nested for-loop.
                */
                goto end;
            }
        }
    }

    /* exit label */
    end:
        return status;
}