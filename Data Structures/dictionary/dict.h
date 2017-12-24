/*
    author: Christian Bender
    public interface for the dictionary. 

    The dictionary prepares space for 1000 elements.
*/

#ifndef __DICT__H
#define __DICT__H

#define MAXELEMENTS 1000

/*
    special data type called 'Dictionary'
    for generic use
*/
typedef struct Dict 
{
    /* 
        void* array for generic use of the dictionary.
        there actual saves the entries.
    */
    void * elements[MAXELEMENTS];

    /* contains the number of elements in this dictionary */
    int number_of_elements;

} Dictionary;

/*
    create_dict: is a simple constructor for creating 
                a dictionary and setting up the 
                member field 'number_of_elements'
                and prepares the inner array 'elements'
*/
Dictionary * create_dict(void);

/* 
    add_item_label: adds item (void*) to the dictionary at given label 
    returns 0 if adding was sucessful otherwise -1
*/
int add_item_label(Dictionary *,char label[],void *);

/* 
    add_item_index: adds item (void*) to the dictionary at given index (int) 
    returns 0 if adding was sucessful otherwise -1
*/
int add_item_index(Dictionary *, int index, void *);


/*
    get_element: returns the element at given label 
*/
void * get_element_label(Dictionary *, char []);


/*
    get_element: returns the element at given index 
*/
void * get_element_index(Dictionary *, int );

/* 
    simple destrcutor function
*/
void destroy(Dictionary *);


#endif