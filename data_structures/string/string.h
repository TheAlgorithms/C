#ifndef STRING_H
#define STRING_H

#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Full match state of string compare result
 */
#define __STR_FULLMATCH__ 0

/**
 * @brief char* delegate
 */
typedef char* STRING;

/**
 * @brief Check if the string is empty or not
 * @param val Value to check
 * @return True if value is null or only whitespace, returns false if not
 */
int isNullOrWhitespace(char* val);

/**
 * @brief Remove spaces at both
 * @param val Value to trim
 * @return Trimmed value
 */
char* trim(char* val);

/**
 * @brief Remove spaces at start
 * @param val Value to trim
 * @return Trimmed value
 */
char* trimStart(char* val);

/**
 * @brief Remove spaces at end
 * @param val Value to trim
 * @return Trimmed value
 */
char* trimEnd(char* val);

/**
 * @brief Substring with start index and count
 * @param val Value to sub
 * @param start Index of start
 * @param count Count of taken chars
 * @return Subbed value
 */
char* substr(char* val, int start, int count);

/**
 * @brief Substring with start index
 * @param val Value to sub
 * @param start Index of start
 * @return Subbed value
 */
char* substrf(char* val, int start);

/**
 * @brief Substrig with seperator
 * @param val Value to sub
 * @param sep Seperator
 * @return Subbed value
 */
char* substrsep(char* val, char* sep);

/**
 * @brief Concatenate strings
 * @param val1 Base value
 * @param val2 Secondary value
 * @return Concatenated value
 */
char* concat(char* val1, char* val2);

/**
 * @brief Concat string and char
 * @param val1 Base value
 * @param ch Char
 * @return Concatenated value
 */
char* concatc(char* val1, char ch);

/**
 * @brief Clone string
 * @param val Value to clone
 * @return Clonned string
 */
char* clonestr(char* val);

/**
 * @brief Check value if starts with or not
 * @param val Value to check
 * @param startval Check value
 * @return True if success, returns false if not
 */
int startsWith(char* val, char* startval);

/**
 * @brief Check value if ends with or not
 * @param val Value to check
 * @param endval Check value
 * @return True if success, returns false if not
 */
int endsWith(char* val, char* endval);

/**
 * @brief Convert to string
 * @param format Value format(see: printf)
 * @param val Value to convert
 * @return char* value of val
 */
char* toStr(char* format, void* val);

#endif  // STRING_H
