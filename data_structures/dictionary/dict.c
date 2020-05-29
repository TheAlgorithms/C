#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

/* simple constructor */
Dictionary *create_dict(void)
{
    Dictionary *p_dic = malloc(sizeof(Dictionary));
    if (p_dic)
    {
        p_dic->number_of_elements = 0;

        /* initializes the elemens of the array with NULL-pointer */
        for (int i = 0; i < MAXELEMENTS; i++)
        {
            p_dic->elements[i] = NULL;
        }

        return p_dic;
    }
    else
    {
        printf("unable to create a dictionary\n");
        return NULL;
    }
}

/*
    utility function
    sdbm hash algorithm
    returns a hashcode for the given string 's'
*/
int get_hash(char s[])
{
    unsigned int hash_code = 0;

    /* iterates over string at each character */
    for (int counter = 0; s[counter] != '\0'; counter++)
    {
        /* actual computing of the hash code */
        hash_code =
            s[counter] + (hash_code << 6) + (hash_code << 16) - hash_code;
    }

    /* % modulo is for fitting the index in array. */
    return hash_code % MAXELEMENTS;
}

int add_item_label(Dictionary *dic, char label[], void *item)
{
    unsigned int index = get_hash(label);

    /* make sure index is fitting */
    if (index < MAXELEMENTS)
    {
        dic->elements[index] = item;
        return 0;
    }

    /* error case */
    return -1;
}

int add_item_index(Dictionary *dic, int index, void *item)
{
    /* make sure whether this place is already given */
    if (!dic->elements[index])
    {
        dic->elements[index] = item;
        return 0;
    }

    /* error case */
    return -1;
}

void *get_element_label(Dictionary *dict, char s[])
{
    int index = get_hash(s);
    if (dict->elements[index])
    {
        return dict->elements[index];
    }

    printf("None entry at given label\n");
    return NULL;
}

void *get_element_index(Dictionary *dict, int index)
{
    if (index >= 0 && index < MAXELEMENTS)
    {
        return dict->elements[index];
    }

    printf("index out of bounds!\n");
    return NULL;
}

void destroy(Dictionary *dict) { free(dict); }