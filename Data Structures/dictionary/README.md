## Dictionary 

This is simple and generic dictionary. You can instantiate multiple dictionaries with
the constructor. See interface below.

Each dictionary has space for 1000 elements. 

You need add the files **dic.c** and **dic.h** in your project directory.
After that you include dic.h

### Overview about functions

``` c
Dictionary * create_dict(void);
```
create_dict: is a simple constructor for creating 
             a dictionary and setting up the 
             member field 'number_of_elements'
             and prepares the inner array 'elements'

``` c
int add_item_label(Dictionary *,char label[],void *);
```
add_item_label: adds item (void*) to the dictionary at given label 
                returns 0 if adding was sucessful otherwise -1


``` c
int add_item_index(Dictionary *, int index, void *);
```
 add_item_index: adds item (void*) to the dictionary at given index (int) 
                returns 0 if adding was sucessful otherwise -1

``` c
void * get_element_label(Dictionary *, char []);
```
get_element: returns the element at given label 


``` c
void * get_element_index(Dictionary *, int);
```
get_element: returns the element at given index 


``` c
void destroy(Dictionary *);
```
simple destructor function for avoiding memory leaks.