#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

void print_list(char **array) {
    int i;
    for( i = 0; array[i]; i++)
        printf("%s", array[i]);
    printf("\n");
}

int main() {
    List_T list1, list2, list3;
    char **str1 = (char **)malloc(100* sizeof(char *));

    list1 = List_init();
    list1 = List_push(list1, "Dang ");
    list1 = List_push(list1, "Hoang ");
    list1 = List_push(list1, "Hai ");
    printf("List 1: ");
    str1 = (char **)List_toArray(list1);
    print_list(str1);

    list2 = List_init();
    list2 = List_list(list2, "Mentor ", "Graphics ", "Siemens", NULL);
    printf("List 2: ");
    print_list((char **)List_toArray(list2));

    list3 = List_append(list1, list2);
    printf("Test append list2 into list1: ");
    print_list((char **)List_toArray(list3));

    return 0;
}
