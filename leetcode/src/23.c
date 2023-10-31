/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
if(listsSize > 1 ){
    
    struct ListNode *p1 = lists[0];
    struct ListNode *p2 = NULL;
    struct ListNode *third = NULL,*last = NULL;
    for(int i=1;i<listsSize;i++)
{   
        p2 = lists[i];
        if(p2 && p1)
   {     if (p1->val < p2->val){
        third = last = p1;
        p1=p1->next;
        last->next = NULL;
    }else{
        third = last = p2;
        p2=p2->next;
        last->next = NULL;
    }
    while(p1 != NULL && p2!= NULL){
        if(p1->val <p2->val){
            last ->next = p1;
            last = p1;
            p1=p1->next;
            last->next = NULL;
        }else{
            last ->next = p2;
            last = p2;
            p2=p2->next;
            last->next = NULL;
        }
    }
    
    if (p1 ==NULL){
        last ->next = p2;
    }else{
        last ->next=p1;
    }
 p1=third;
    }
    else if (p1==NULL){
        p1=p2;
    }}
     return p1;
}else{
    return (listsSize == 0)?NULL:lists[0];
}
   
}