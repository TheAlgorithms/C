#include <stdio.h> /* printf() */
#include <stdlib.h> /* size_t, calloc() */
#include <stdint.h> /* uint32_t */
#include <math.h> /* ceil() */
#include <string.h> /* strlen(), strchr() */

static char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const char *string) {
    size_t plain_length = strlen(string);
    size_t block_count = (int)ceil(plain_length/3.0); /* count how many 3 byte blocks (or shorter for the last) exist */
    size_t encoded_length = block_count * 4; /* each block, once encoded occupies 4 bytes */

    char *out = calloc((encoded_length + 1) * sizeof(char), sizeof(char));
    if (out == NULL)
        return NULL;
        
    out[encoded_length] = '\0';

    /* the real meat - take 3 bytes (8-bit chunks) and interpret as 4 6-bit chunks */
    for (int i = 0, j = 0; i < plain_length; ) {
        uint32_t octet_a = i < plain_length ? (unsigned char) string[i++] : 0;
        uint32_t octet_b = i < plain_length ? (unsigned char) string[i++] : 0;
        uint32_t octet_c = i < plain_length ? (unsigned char) string[i++] : 0;

        uint32_t block  = (octet_a << 16) | (octet_b << 8) | (octet_c);

        /* a "byte" in base64 is 6 bits long */
        out[j++] = table[(block >> 18) & 0x3F];
        out[j++] = table[(block >> 12) & 0x3F];
        out[j++] = table[(block >> 6) & 0x3F];
        out[j++] = table[(block >> 0) & 0x3F];
    }

    /* getting the padding right if input wasn't evenly divisible by 3 */
    int padding_length = plain_length % 3;
    if(padding_length != 0) 
        padding_length = 3 - padding_length;
        
    for(int i = padding_length; i>0; i--)
        out[encoded_length - i] = '=';
        
    return out;
}

char* base64_decode(const char *string) {
    size_t encoded_length = strlen(string);
    size_t decoded_length = (int)(encoded_length * (0.75)) + 1;

    /* improper length - Invalid */
    if (encoded_length % 4)
        return NULL;

    char *out = calloc((decoded_length + 1) * sizeof(char), sizeof(char));
    if (out == NULL)
        return NULL;

    /* the meat - actual decoding happens in this block */
    int string_counter = 0;
    for(int i = 0; i < decoded_length;)
    {
        uint32_t block = 0;
        for(int j = 0; j<4; j++)
        {
            //fprintf(stderr, "%d + %d = %d\n", i,j, i+j+temp_fix);
            char b64_chr = string[string_counter++];
            if(b64_chr == '=')
            {
                block <<= 6;
                continue;
            }
            
            char* b64_index = strchr(table, b64_chr);
            if(b64_index == NULL)
            {
                free(out);
                out = NULL;
                fprintf(stderr, "(%d)[%c] %d- %s\n", b64_chr, b64_chr, block, out);
                return NULL;
            }
            uint32_t difference = b64_index - table;
            block = (block << 6);
            block |= (difference & 0x3F);
        }
        out[i++] = (char)(block >> 16) & 0xFF;
        out[i++] = (char)(block >> 8) & 0xFF;
        out[i++] = (char)(block >> 0) & 0xFF;
    }

    return out;
}

int main(int argc, char *argv[]) {
    char string[] = "Hello World";

    char *enc = base64_encode(string);
    printf("%s\n", enc);  // SGVsbG8gV29ybGQ=
    
    char *dec = base64_decode(enc);
    //char *dec = base64_decode(b64_test);
    printf("%s\n", dec);  // Hello World

    return 0;
}