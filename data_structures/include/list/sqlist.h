#ifndef sqlist_h_
#define sqlist_h_

#define LISTINIT 10   // initial size of sequential list
#define ElemType int  // Element type

#include <forehead/forehead.h>

/* @Obsolete: static allocation */
// #define MAX 50
// typedef struct{
//   ElemType data[MAX];
//   int length;
// }sqlist;

/**
 * @brief Sequential list structure
 */
typedef struct
{
    ElemType *data;  // data array
    int length;      // current length
    int size;        // maximum size
} sqlist;

/* Operations */
extern char *sqlist_to_string(sqlist *sl);
extern void sqlist_init(sqlist *sl);
extern int sqlist_create(sqlist *sl, int num);
extern int sqlist_insert(sqlist *sl, int ith, ElemType e);
extern int sqlist_delete(sqlist *sl, int ith, ElemType *e);
extern int *sqlist_locate(sqlist *sl, ElemType e,
                          int (*compare)(ElemType, ElemType));
extern int sqlist_search(sqlist *sl, int ith, ElemType *e);
extern int compare(ElemType x, ElemType y);

/* TODO:algorithms of sqlist */

#endif
