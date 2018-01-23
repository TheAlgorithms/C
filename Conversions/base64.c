#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char enc_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};
static char dec_table[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
static char mod_table[] = {0, 2, 1};

char *base64_encode(const char *string) {
    size_t dec_length = strlen(string);
    size_t enc_length = ((dec_length + 2) / 3) << 2;

    char *out = malloc((enc_length + 1) * sizeof(char));
    if (out == NULL)
        return NULL;
    out[enc_length] = '\0';

    for (int i = 0, j = 0; i < dec_length; ) {
        uint32_t octet_a = i < dec_length ? (unsigned char) string[i++] : 0;
        uint32_t octet_b = i < dec_length ? (unsigned char) string[i++] : 0;
        uint32_t octet_c = i < dec_length ? (unsigned char) string[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        out[j++] = enc_table[(triple >> 3 * 6) & 0x3F];
        out[j++] = enc_table[(triple >> 2 * 6) & 0x3F];
        out[j++] = enc_table[(triple >> 1 * 6) & 0x3F];
        out[j++] = enc_table[(triple >> 0 * 6) & 0x3F];
    }

    for (int i = 0; i < mod_table[dec_length % 3]; ++i)
        out[enc_length - 1 - i] = '=';

    return out;
}

char *base64_decode(const char *string) {
    size_t enc_length = strlen(string);
    size_t dec_length = ((enc_length * 3) >> 2) - (string[enc_length - 2] == '=' ? 2 : (string[enc_length - 1] == '=' ? 1 : 0));

    if (enc_length % 4 != 0)
        return NULL;

    char *out = malloc((dec_length + 1) * sizeof(char));
    if (out == NULL)
        return NULL;
    out[dec_length] = '\0';

    for (int i = 0, j = 0; i < enc_length; ) {
        uint32_t sextet_a = dec_table[string[i++]];
        uint32_t sextet_b = dec_table[string[i++]];
        uint32_t sextet_c = string[i] == '=' ? 0 & i++ : dec_table[string[i++]];
        uint32_t sextet_d = string[i] == '=' ? 0 & i++ : dec_table[string[i++]];
        
        uint32_t triple = (sextet_a << 18) + (sextet_b << 12) + (sextet_c << 6) + sextet_d;
        
        if (j < dec_length)
            out[j++] = (triple >> 16) & 0xFF;
        if (j < dec_length)
            out[j++] = (triple >> 8) & 0xFF;
        if (j < dec_length)
            out[j++] = triple & 0xFF;
    }

    return out;
}

int main(int argc, char *argv[]) {
    char string[] = "Hello World";

    char *enc = base64_encode(string);
    printf("%s\n", enc);  // SGVsbG8gV29ybGQ=

    char *dec = base64_decode(enc);
    printf("%s\n", dec);  // Hello World

    return 0;
}
