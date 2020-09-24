#include "string.h"

int isNullOrWhitespace(char* val)
{
    if (val == NULL)  // If "val" is null
        return 1;     // Return true

    char* cpy = calloc(strlen(val),
                       sizeof(char));  // New char* instance by "val" size
    strcpy(cpy, val);                  // Copy "val" to "cpy"
    int result = strtok(cpy, " ") ==
                 NULL;  // Set 1 if "cpy" is not only whitespace, set 0 if not
    free(cpy);          // Free "cpy"
    return result;      // Return result
}

char* substr(char* val, int start, int count)
{
    if (count < 1)  // If character limit lower then 1
        return "";  // Return empty string

    char* dest = "";                   // Sub value
    int counter = 0;                   // Counter for character limit
    for (int index = start;; index++)  // Start for loop from start index
    {
        dest = concatc(dest,
                       val[index]);  // Concatenate sub value with current char
        counter++;                   // Increase "counter"
        if (counter == count)        // If counter equals to character limit
            break;                   // break for loop
    }
    return dest;  // Return subbed value
}

char* substrf(char* val, int start)
{
    int len = strlen(val);  // Get length of "val"
    if (len - 1 < start)    // If maximum index lower then start index
        return NULL;        // Return NULL

    int count = len - start;  // Get character length
    char* destination = calloc(
        count,
        sizeof(char*));  // Create new char* instance sized by character count
    strncpy(destination, val + start,
            count);      // Copy value after start index value to "destination""
    return destination;  // Return subbed value
}

char* substrsep(char* val, char* sep)
{
    for (int index = 0; index < strlen(val); index++)
        if (startsWith(substrf(val, index), sep) ==
            1)  // If "value" starts with "sep" after index
            return substr(
                val, 0,
                index);  // Get range(first character:index as count) from "val"
    return val;          // Return value
}

char* trimStart(char* val)
{
    for (int index = 0; index < strlen(val); index++)
    {
        char ch = val[index];  // Get current char
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\v' && ch != '\f' &&
            ch != '\r')  // Current char is not equals to any seperator
            return substrf(val, index);  // Return value after this index
    }
    return val;  // Return trimmed value
}

char* trimEnd(char* val)
{
    char* seps = "\t\n\v\f\r ";  // Seperators
    int i = strlen(val) - 1;     // Get maximum index of "val"
    while (i >= 0 && strchr(seps, val[i]) !=
                         NULL)  // Return loop if index bigger or equal to zero
                                // and current char is seperator char
    {
        val[i] = '\0';  // Set empty char to i. index of "val"
        i--;            // Decrease "i"
    }
    return val;  // Return trimmed value
}

char* trim(char* val)
{
    return trimStart(trimEnd(val));  // Return the value whose beginning and end
                                     // has been subjected to the trim function
}

char* concat(char* val1, char* val2)
{
    char* result =
        calloc(strlen(val1) + strlen(val2),
               (strlen(val1) + strlen(val2)) *
                   sizeof(char));  // Create new char* instance sized
                                   // by sum of "val1" and "val2" lengths
    strcpy(result, val1);          // Copy value of "val1" to "result"
    strcat(result, val2);          // Concatenate value of "val2" to "result"
    return result;                 // Return concatenated value
}

char* concatc(char* val1, char ch)
{
    char* result = calloc(strlen(val1) + 1, sizeof(char));
    char* cht = &ch;       // Get memory address of "ch"
    strcpy(result, val1);  // Copy value of "val1" to "result"
    char chr[2] = {ch, 0};
    strcat(result, chr);  // Concatenate "result" with "chr"
    return result;        // Return concatenated value
}

char* clonestr(char* val)
{
    char* value = calloc(
        strlen(val),
        sizeof(char));   // Create new char* instance sized by length of "val"
    strcpy(value, val);  // Copy value of "val" to "value"
    return value;        // Return clone
}

int startsWith(char* val, char* startval)
{
    int length = strlen(startval);  // Get length of "startval"
    for (int index = 0; index < length; index++)
    {
        if (val[index] != startval[index])  // If current char is not equals to
                                            // current char of "startval"
            return 0;                       // Return false
    }
    return 1;  // Return true
}

int endsWith(char* val, char* endval)
{
    int vallength = strlen(val);  // Get length of "val"
    int length = strlen(endval);  // Get length of "endval"
    char* result = substr(val, vallength - length,
                          length);  // Get end of "val" by "endval" length
    int state = strcmp(result, endval) == __STR_FULLMATCH__
                    ? 1
                    : 0;  // Set 1(true) if "result" equals to "endval", set
                          // 0(false) if not
    return state;         // Return state(0/1)
}

char* toStr(char* format, void* val)
{
    char* str = calloc(
        sizeof(val),
        sizeof(char));  // Create new char* instance sized by length of "val"
    sprintf(str, format, val);  // Copy value to "str" from "val" by format
    return str;                 // Return string
}
