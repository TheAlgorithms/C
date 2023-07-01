/**
 * @file sqlist.h
 * @brief Implementation of sequential list with basic operations and algorithms
 * @details
 * @author danielhu19 (shady030314@gmail.com)
 * @see  Wikipedia: https://en.wikipedia.org/wiki/List_(abstract_data_type))
 *
 */

#include <list/sqlist.h>

char* sqlist_to_string(sqlist* sl)
{
    // Abort program if SqLIst is NOT INIT
    Assert(sl, "NOT INIT");

    char* str = malloc(sizeof(char) * 100);
    int clock = 0;
    while (clock < (*sl).length - 1)
    {
        sprintf(str, "%s%d ", str, (*sl).data[clock]);
        ++clock;
    }
    sprintf(str, "%s%d\n", str, (*sl).data[sl->length - 1]);

    return str;
}

/**
 * @brief  Create a null sqlist with:
 * `LISTINIT` size of data array, 0 current length and `LISTINIT` maximize size
 * @param sl sqlist pointer
 */
void sqlist_init(sqlist* sl)
{
    (*sl).data = (ElemType*)malloc(LISTINIT * sizeof(ElemType));
    Assert((sl)->data, "MALLOC FAILED!");
    (*sl).length = 0;
    (*sl).size = LISTINIT;
}

/* testing whether or not a list is empty */
bool is_sqlist_empty(sqlist* sl)
{
    Assert(sl, "NOT INIT");
    return sl->length == 0;
}

/* Create a sqlist which contains $num(<=size) random elements */
int sqlist_create(sqlist* sl, int num)
{
    Assert(sl, "NOT INIT");
    Assert(num <= sl->size, "OVERFLOW");
    /* `man srand` */
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        int r = rand();
        (*sl).data[i] = r;
        ++(*sl).length;
    }

    return 1;
}

/**
 * @brief Insert `e` into the `i` th spot of sqlist
 *
 * @param sl sqlist pointer
 * @param ith spot(not array index) to be inserted: `1 <= i <= length + 1`
 * @param e element to insert
 * @return 1 if succeed
 */
int sqlist_insert(sqlist* sl, int ith, ElemType e)
{
    // Assert if sqlist is not initialized or invalid insertion
    Assert(sl, "NOT INIT");
    Assert(ith >= 1 && ith <= (*sl).length + 1, "INVALID INSERTION REQUEST");

    // re-allocate(double) space if sqlist is full
    if ((*sl).length == (*sl).size)
    {
        sl->data = (ElemType*)realloc(
            (*sl).data, ((*sl).size + LISTINIT) * sizeof(ElemType));
        Assert(sl->data, "RE-ALLOCATION FAILED");
        (*sl).size += LISTINIT;
    }

    // move elements backward for insertion
    for (int j = sl->length; j >= ith; j--)
    {
        sl->data[j] = sl->data[j - 1];
    }
    sl->data[ith - 1] = e;
    sl->length++;

    return 1;
}

/**
 * @brief Delete the `ith` element in sqlist, and return the deleted to `e`
 *
 * @param sl sqlist pointer
 * @param ith spot(not array index) to be deleted: `1 <= i <= length`
 * @param e pointer to store the deleted element
 * @return 1 if succeed
 */
int sqlist_delete(sqlist* sl, int ith, ElemType* e)
{
    // Assert if sqlist is not initialized or invalid deletion
    Assert(sl, "NOT INIT");
    Assert(ith >= 1 && ith <= sl->length, "INVALID DELETION");

    *e = sl->data[ith - 1];  // store the deleted element

    // move elements forward
    for (int j = ith; j < sl->length; j++)
    {
        sl->data[j - 1] = sl->data[j];
    }
    sl->length--;

    return 1;
}

/**
 * @brief Search the `ith` element in sqlist, and return the founded to `e`
 *
 * @param sl sqlist pointer
 * @param ith spot(not array index) to be searched: `1 <= i <= length`
 * @param e pointer to store the founded element
 * @return 1 if succeed
 */
int sqlist_search(sqlist* sl, int ith, ElemType* e)
{
    // Assert if sqlist is not initialized or invalid search
    Assert(sl, "NOT INIT");
    Assert(ith >= 1 && ith <= sl->length, "INVALID SEARCH");

    // store the founded element
    *e = sl->data[ith - 1];

    return 1;
}

// auxiliary function for sqlist_locate
int compare(ElemType x, ElemType y) { return x == y; }

/**
 * @brief Locate the satisfied spot to `ith`(including mutiple occurs)
 *
 * @param sl sqlist pointer
 * @param e element to be searched
 * @param compare function pointer to compare two elements
 * @return int *: satisfied spot array or NULL if not found
 */
int* sqlist_locate(sqlist* sl, ElemType e, int (*compare)(ElemType, ElemType))
{
    Assert(sl, "NOT INIT");

    int* ith = malloc(sizeof(int) * sl->length);
    int cnt = 0;        // denotes how many times occurs
    bool flag = false;  // denotes if target is found or not

    for (int i = 0; i < sl->length; i++)
    {
        if (compare(sl->data[i], e))
        {
            flag = true;
            ith[cnt] = i + 1;  // ith stores spot, not array index
            cnt++;
        }
    }
    ith[cnt] = '\0';
    if (!flag)
    {
        // ELEMENT NOT FOUND!
        return NULL;
    }

    return ith;
}
