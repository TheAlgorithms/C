#ifndef STRING_H
#define STRING_H

#include <ctype.h>
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// String declaration.
typedef char* STRING;

// Returns true(1) if value is null or only whitespace, returns false(0) if not.
int isNullOrWhitespace(char* val);

// Remove spaces at start and end.
char* trim(char* val);

// Remove spaces at start.
char* trimStart(char* val);

// Remove spaces at end.
char* trimEnd(char* val);

// Substring with start index and count.
char* substr(char* val, int start, int count);

// Substring with start index.
char* substrf(char* val, int start);

// Substrig with seperator.
char* substrsep(char* val, char* sep);

// Contcat strings.
char* concat(char* val1, char* val2);

// Concat string and char.
char* concatc(char* val1, char ch);

// Clone string.
char* clonestr(char* val);

// Returns true(1) if success, returns false(0) if not.
int startsWith(char* val, char* startval);

// Returns true(1) if success, returns false(0) if not.
int endsWith(char* val, char* endval);

// Convert to string.
char* toStr(char* format, void* val);

#endif  // STRING_H
