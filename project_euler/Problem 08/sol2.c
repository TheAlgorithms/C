#include <stdio.h>
#include <stdlib.h>
#include <string.h>     /* for memmove */

int main(int argc, char* argv[])
{
    int position = 0, num_bad_chars = 0;
    int num_digits = 4;
    char ch;
    uint8_t num, num_prev;
    uint8_t *buffer = NULL;
    int64_t prod = 1, max_prod = 0;

    /* if second command-line argument is given,
     * use it as the number of digits to compute 
     * successive product for
     */
    if (argc == 2)
        num_digits = atoi(argv[1]);
   
    /* allocate memory to store past values */
    buffer = calloc(num_digits, sizeof(uint8_t));
    if(!buffer)
    {
        perror("Unable to allocate memory for buffer");
        return -1;
    }

    /* open file to read digits from */
    FILE *fp = fopen("digits.txt", "rt");
    if (!fp)
    {
        perror("Unable to open file");
        free(buffer);   /* free allocated memory */
        return -1;
    }

    /* loop through all digits in the file */
    do 
    {
        /* get character from file */
        ch = getc(fp);

        /* the ASCII codes of digits is between 0x30 and 0x39. 
         * any character not in this range implies an invalid character
         */
        if (ch < 0x30 || ch > 0x39)
        {
            num_bad_chars ++;   /* this is used to get the bad characters in the sequence of 13 characters */
            continue;
        } else if (num_bad_chars > 0)
            num_bad_chars --;
        
        num = ch - 0x30;         /* convert character digit to number */
        num_prev = buffer[0];    /* previous n^th digit */

        /* left shift the buffer -
         *  using a for loop or a faster memory move
         */
        memmove(buffer, buffer+1, num_digits-1);
        /*
        for (int i = 1; i < num_digits; i++)
            buffer[i-1] = buffer[i];
        */

        buffer[num_digits-1] = num; /* save the latest number in buffer */

        if (num_prev != 0)
        {
            /* since product is accumulated, the new product can be obtained by simply 
             * multiplying the new digit and dividing with the oldest digit
             */
            prod /= num_prev;   /* divide first to avoid over-flows */
            prod *= num;
        }
        else
        {
            prod = 1;
            for(int i = 0; i < num_digits; i++)
            {
                if(buffer[i] == 0)
                {
                    prod = 0;
                    break;      /* break innermost for-loop */
                }
                prod *= buffer[i];
            }
        }

        /* check if a new maxima was found */
        if (prod > max_prod)
        {
            max_prod = prod;
            position = ftell(fp) - num_bad_chars - num_digits - 1;
        }
    } while(!feof(fp));      /* loop till end of file is reached */
    
    printf("Maximum product: %lld\t Location: %d^th position\n\t", max_prod, position);
    fseek(fp, position, SEEK_SET);  /* move cursor to identified position in file */
    /* loop through all digits */
    for (; num_digits > 0; num_digits--)
    {
        char ch = getc(fp);     /* get character */
        /* skip invalid character */
        if (ch < 0x30 || ch > 0x39)
            continue;
        if (num_digits > 1)
            printf("%c x ", ch);
        else
            printf("%c = %lld\n", ch, max_prod);
    }

    fclose(fp);     /* close file */
    free(buffer);   /* free allocated memory */

    return 0;
}
