#include "list.c"

int main(){
    List l;
    list_init(&l);
    list_append(&l,10);
    list_append(&l,20);
    list_insert(&l,1,15); // 10 15 20
    list_delete(&l,0);    // 15 20
    list_print(&l);
    list_free(&l);
    return 0;
}
