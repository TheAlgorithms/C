#include <list/sqlist.h>

void test_insert()
{
    sqlist sl;
    sqlist_init(&sl);
    // insert 1,2,3,4,5
    char* predicted = "1 2 3 4 5\n";
    sqlist_insert(&sl, 1, 1);
    sqlist_insert(&sl, 2, 2);
    sqlist_insert(&sl, 3, 3);
    sqlist_insert(&sl, 4, 4);
    sqlist_insert(&sl, 5, 5);
    Assert(strcmp(sqlist_to_string(&sl), predicted) == 0, "INSERT FAILED!");
    LOG("INSERT PASSED!\n");
}

void test_delete()
{
    int e;
    sqlist sl;
    sqlist_init(&sl);
    // insert 1,2,3,4,5
    sqlist_insert(&sl, 1, 1);
    sqlist_insert(&sl, 2, 2);
    sqlist_insert(&sl, 3, 3);
    sqlist_insert(&sl, 4, 4);
    sqlist_insert(&sl, 5, 5);

    char* predicted = "2 4\n";
    sqlist_delete(&sl, 1, &e);
    Assert(e == 1, "DELETE 1 FAILED!");
    sqlist_delete(&sl, 2, &e);  // delete 3
    Assert(e == 3, "DELETE 3 FAILED!");
    sqlist_delete(&sl, 3, &e);  // delete 5
    Assert(e == 5, "DELETE 5 FAILED!");
    Assert(strcmp(sqlist_to_string(&sl), predicted) == 0, "DELETE FAILED!");
    LOG("DELETE PASSED!\n");
}

void test_search()
{
    int e;
    int* locate;
    sqlist sl;
    sqlist_init(&sl);
    // insert 1,2,3,4,5
    sqlist_insert(&sl, 1, 1);
    sqlist_insert(&sl, 2, 2);
    sqlist_insert(&sl, 3, 3);
    sqlist_insert(&sl, 4, 4);
    sqlist_insert(&sl, 5, 5);

    sqlist_search(&sl, 1, &e);
    Assert(e == 1, "SEARCH 1 FAILED!");
    sqlist_search(&sl, 2, &e);
    Assert(e == 2, "SEARCH 2 FAILED!");
    sqlist_search(&sl, 5, &e);
    Assert(e == 5, "SEARCH 5 FAILED!");
    LOG("SEARCH PASSED!\n");

    sqlist_insert(&sl, 6, 2);
    // now: 1 2 3 4 5 2
    locate = sqlist_locate(&sl, 2, compare);
    Assert(locate[0] == 2 && locate[1] == 6, "LOCATE FAILED!");

    locate = sqlist_locate(&sl, 1, compare);
    Assert(locate[0] == 1, "LOCATE FAILED!");

    locate = sqlist_locate(&sl, 7, compare);
    Assert(locate == NULL, "LOCATE FAILED!");
    LOG("LOCATE PASSED!\n");
}

void test_all()
{
    int e;
    sqlist sl;
    sqlist_init(&sl);
    sqlist_create(&sl, 1);
    // insert 2,3,2
    sqlist_insert(&sl, 1, 2);
    sqlist_insert(&sl, 2, 3);
    sqlist_insert(&sl, 3, 2);
    // now it is 2 3 2 $random
    // delete $random
    sqlist_delete(&sl, 4, &e);
    // now: 2 3 2
    Assert(strcmp(sqlist_to_string(&sl), "2 3 2\n") == 0, "DELETE FAILED!");
    // search the first and last
    sqlist_search(&sl, 1, &e);
    Assert(e == 2, "SEARCH 2 FAILED!");
    sqlist_search(&sl, 3, &e);
    Assert(e == 2, "SEARCH 3 FAILED!");

    // locate 2
    int* locate = sqlist_locate(&sl, 2, compare);
    Assert(locate[0] == 1 && locate[1] == 3, "LOCATE FAILED!");
    LOG("ALL PASSED!\n");
}

int main()
{
    test_insert();
    test_delete();
    test_search();
    test_all();
    return 0;
}
