/*
    author: Christian Bender
    This is a simple test program for the dictionary.
*/

#include <stdio.h>

/* includes the dictionary */
#include "dict.h"

int main(void)
{
    Dictionary *testObj1;
    Dictionary *testObj2;

    int value = 28;

    testObj1 = create_dict();
    testObj2 = create_dict();

    add_item_label(testObj1, "age", &value);
    add_item_label(testObj2, "name", "Christian");

    /*
        test for function add_item_label

        attention:
        The void* pointer must be convert into an int* pointer.
        After that you can dereference it.
    */
    printf("My age is %d\n", *((int *)get_element_label(testObj1, "age")));
    printf("My name is %s\n", get_element_label(testObj2, "name"));

    /* test for function add_item_index */
    if (!add_item_index(testObj1, 0, &value))
    {
        printf("My age at index %d is %d\n", 0,
               *((int *)get_element_index(testObj1, 0)));
    }

    /* error scenario */
    /* get_element_label(testObj,"none"); */

    /* tidy up */
    destroy(testObj1);
    destroy(testObj2);

    return 0;
}