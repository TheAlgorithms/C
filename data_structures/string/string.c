#include "string.h"

int isNullOrWhitespace(char* val)
{
    if (val == NULL)
        return 1;

    char* cpy = malloc(strlen(val));
    strcpy(cpy, val);
    int result = strtok(cpy, " ") == NULL;
    free(cpy);
    return result;
}

char* substr(char* val, int start, int count)
{
    char* dest = "";
    int counter = 0;
    for (int index = start;; index++)
    {
        dest = concatc(dest, val[index]);
        counter++;
        if (counter == count)
            break;
    }
    return dest;
}

char* substrf(char* val, int start)
{
    int len = strlen(val);
    if (len - 1 < start)
        return NULL;

    int count = len - start;
    char* destination = calloc(count, sizeof(char*));
    strncpy(destination, val + start, count);
    return destination;
}

char* substrsep(char* val, char* sep)
{
    for (int index = 0; index < strlen(val); index++)
        if (startsWith(substrf(val, index), sep))
            return substr(val, 0, index);
    return val;
}

char* trimStart(char* val)
{
    for (int index = 0; index < strlen(val); index++)
    {
        char ch = val[index];
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\v' && ch != '\f' &&
            ch != '\r')
            return substrf(val, index);
    }
    return val;
}

char* trimEnd(char* val)
{
    char* seps = "\t\n\v\f\r ";
    int i = strlen(val) - 1;
    while (i >= 0 && strchr(seps, val[i]) != NULL)
    {
        val[i] = '\0';
        i--;
    }
    return val;
}

char* trim(char* val) { return trimStart(trimEnd(val)); }

char* concat(char* val1, char* val2)
{
    char* result = malloc(strlen(val1) + strlen(val2 + 1));
    strcpy(result, val1);
    strcat(result, val2);
    return result;
}

char* concatc(char* val1, char ch)
{
    char* result = malloc(strlen(val1) + 1);
    char* cht = &ch;
    strcpy(result, val1);
    char chr[2] = {ch, 0};
    strcat(result, chr);
    return result;
}

char* clonestr(char* val)
{
    char* value = malloc(strlen(val));
    strcpy(value, val);
    return value;
}

int startsWith(char* val, char* startval)
{
    int length = strlen(startval);
    for (int index = 0; index < length; index++)
    {
        if (val[index] != startval[index])
            return 0;
    }
    return 1;
}

int endsWith(char* val, char* endval)
{
    int vallength = strlen(val);
    int length = strlen(endval);
    char* result = substr(val, vallength - length, length);
    int state = strcmp(result, endval) == 0 ? 1 : 0;
    return state;
}

char* toStr(char* format, void* val)
{
    char* str = malloc(sizeof(val) * sizeof(char));
    sprintf(str, format, val);
    return str;
}
