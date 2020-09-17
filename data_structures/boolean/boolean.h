#ifndef BOOLEAN_H
#define BOOLEAN_H

// Boolean declaration.
typedef int BOOLEAN;

#define true 1
#define false 0

/*
Represents 1 when the Boolean data type is true and 0 when it is false.
Imagine it as binary, true is 1 and false is 0.

Conditions work this way. If it returns 1 from all conditioning, then condition
is satisfied, 0 means not.

The boolean here only contributes to readability. You can do the same using any
numeric type.

Example Code:

BOOLEAN isHello(char* str)
{
    return str == "Hello";
}

int main()
{
    if(isHello("Hello"))
    {
        printf("Is 'Hello'!");
    }
    else
    {
        printf("Is not 'Hello'!");
    }
}

*/

#endif  // BOOLEAN_H
