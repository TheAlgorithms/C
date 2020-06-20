#include<stdio.h>
#include<stdlib.h>
#define NUM_KEYS 10


enum NodeType {
	ROOT,
	INTERNAL,
	LEAF
};

typedef struct _BTreeNode{

	enum NodeType type;
    int Tindex;
    long long keys[NUM_KEYS];
	struct _BTreeNode* child[NUM_KEYS+1];

} BTreeNode;


typedef struct _BStack{
    BTreeNode* bstack[1000];
	int bstack_c[1000];
	int top;
	int top_c;
} BStack;


typedef struct _BTree{
    BTreeNode* root;
    int only_root_flag;
    int count;

} BTree;


BTreeNode* findValue_ins(BTree* btree, BStack* search_stack, long long value);
void push(BStack* stackb, BTreeNode* ptr);
BTreeNode* pop(BStack* stackb);
int pop_c(BStack* stackb);
void insertKey(BTreeNode* node, int index, long long value);
void deleteKey(BTreeNode* node, int index);
void insert(BTree* btree, long long value);
void insert_in_leaf(BTree* btree, BTreeNode* ins_Node, long long value);
void insert_in_parent(BTree* btree, BTreeNode* ins_Node, BStack* search_Stack, long long value, BTreeNode* made_Node);
void trip(BTree* btree);
void inorder(BTree* btree, BTreeNode* cur, int height);


void push(BStack* stackb, BTreeNode* ptr){
    stackb->top++;
    stackb->bstack[stackb->top] = ptr;

}
BTreeNode* pop(BStack* stackb){
    stackb->top--;
    return stackb->bstack[stackb->top+1]; 
}
void push_c(BStack* stackb, int c_index){
    stackb->top_c++;
    stackb->bstack_c[stackb->top_c] = c_index;

}
int pop_c(BStack* stackb){
    stackb->top_c--;
    return stackb->bstack_c[stackb->top_c+1]; 
}
void insertKey(BTreeNode* node, int index, long long value){
    if(index == -1){
        for(int i=node->Tindex;i>0;i--){
            node->keys[i] = node->keys[i-1];
        }
        for(int i=node->Tindex;i>=0;i--){
            node->child[i+1] = node->child[i];
        }
        node->keys[0] = value;
        node->Tindex++;
        return;
    }
    for(int i=node->Tindex;i>index;i--){
        node->keys[i] = node->keys[i-1];
        node->child[i+1] = node->child[i];
    }
    node->keys[index] = value;
    node->Tindex++;
}
void deleteKey(BTreeNode* node, int index){

    if(index == -1){
        for(int i=0;i<node->Tindex;i++){
            node->child[i] = node->child[i+1];
        }
        for(int i=0;i<node->Tindex-1;i++){
            node->keys[i] = node->keys[i+1];
        }
        node->child[node->Tindex] = NULL;
        node->Tindex--;
        return;
    }


    if(index == node->Tindex - 1){
        node->child[node->Tindex] = NULL;
        node->Tindex--;
        return;
    }
    for(int i=index;i<node->Tindex - 1;i++){
        node->keys[i] = node->keys[i+1];
        node->child[i+1] = node->child[i+2];
    }
    node->child[node->Tindex] = NULL;
    node->Tindex--;



}

void insert(BTree* btree, long long value){

    BTreeNode* ins_Node;
    BTreeNode* new_Node;
    long long temp_keys[NUM_KEYS + 1];
	BTreeNode* temp_child[NUM_KEYS + 2];
    long long smst;
    int flagy = 0;

    BStack* search_Stack = (BStack*)malloc(sizeof(BStack));
    search_Stack->top = -1;
    search_Stack->top_c = -1;

    if(btree->root == NULL){
        new_Node = (BTreeNode*)malloc(sizeof(BTreeNode));
        new_Node->Tindex = 0;
        new_Node->type = ROOT;
        insert_in_leaf(btree, new_Node, value);
        btree->root = new_Node;
        btree->only_root_flag = 1;
        btree->count++;
        return;
    }

    ins_Node = findValue_ins(btree, search_Stack, value);

    if(ins_Node->Tindex < NUM_KEYS){
        insert_in_leaf(btree, ins_Node, value);
        return;
    }

    new_Node = (BTreeNode*)malloc(sizeof(BTreeNode));
    new_Node->type = LEAF;
    new_Node->Tindex = 0;

    for(int i=0;i<NUM_KEYS;i++){
        temp_keys[i] = ins_Node->keys[i];
    }
    flagy = 0;
    for(int i=0;i<NUM_KEYS;i++){
        if(temp_keys[i] > value){
            for(int j=NUM_KEYS;j>i;j--){
                temp_keys[j] = temp_keys[j-1];
            }
            temp_keys[i] = value;
            flagy = 1;
            break;
        }

    }
    if(flagy == 0){
        temp_keys[NUM_KEYS] = value;
    }

    new_Node->child[NUM_KEYS] = ins_Node->child[NUM_KEYS];
    ins_Node->child[NUM_KEYS] = new_Node;

    for(int i=0;i<=(NUM_KEYS/2) + (NUM_KEYS%2);i++){
        ins_Node->keys[i] = temp_keys[i];
    }
    ins_Node->Tindex = (NUM_KEYS/2) + (NUM_KEYS%2) + 1;
    for(int i=(NUM_KEYS/2) + (NUM_KEYS%2) + 1;i<=NUM_KEYS;i++){
        insertKey(new_Node ,i - ((NUM_KEYS/2) + (NUM_KEYS%2) + 1), temp_keys[i]);

    }
    smst = new_Node->keys[0];
    insert_in_parent(btree, ins_Node, search_Stack, smst, new_Node);


}

void insert_in_leaf(BTree* btree, BTreeNode* ins_Node, long long value){
    for(int i=0;i<ins_Node->Tindex;i++){
        if(value < ins_Node->keys[i]){
            insertKey(ins_Node, i, value);
            return;
        }
    }
    insertKey(ins_Node, ins_Node->Tindex, value);
    
}

void insert_in_parent(BTree* btree, BTreeNode* ins_Node, BStack* search_Stack, long long value, BTreeNode* made_Node){
    BTreeNode* new_Node;
    BTreeNode* par_Node;
    long long temp_keys[NUM_KEYS + 1];
	BTreeNode* temp_child[NUM_KEYS + 2];
    int par_c;
    long long new_val;
    int flagy;
    if(ins_Node->type == ROOT){
        new_Node = (BTreeNode*)malloc(sizeof(BTreeNode));
        new_Node->type = ROOT;
        new_Node->Tindex = 0;

        insertKey(new_Node, 0, value);
        new_Node->child[0] = ins_Node;
        new_Node->child[1] = made_Node;
        
        if(made_Node->type == LEAF){
            ins_Node->type = LEAF;
        }
        else{
            ins_Node->type = INTERNAL;
        }
        btree->root = new_Node;
        btree->only_root_flag = 0;
        return;

    }
    par_Node = pop(search_Stack);
    par_c = pop_c(search_Stack);

    if(par_Node->Tindex < NUM_KEYS){
        insertKey(par_Node, par_c, value);
        par_Node->child[par_c+1] = made_Node;

    }
    else{

        for(int i=0;i<NUM_KEYS;i++){
            temp_keys[i] = par_Node->keys[i];
        }
        for(int i=0;i<NUM_KEYS+1;i++){
            temp_child[i] = par_Node->child[i];
        }


        flagy = 0;
        for(int i=0;i<NUM_KEYS;i++){
            if(temp_keys[i] > value){
                for(int j=NUM_KEYS;j>i;j--){
                    temp_keys[j] = temp_keys[j-1];
                    temp_child[j+1] = temp_child[j];
                }
                temp_keys[i] = value;
                temp_child[i+1] = made_Node;
                flagy = 1;
                break;
            }

        }
        if(flagy == 0){
            temp_keys[NUM_KEYS] = value;
            temp_child[NUM_KEYS+1] = made_Node;

        }

        new_Node = (BTreeNode*)malloc(sizeof(BTreeNode));
        new_Node->type = INTERNAL;
        new_Node->Tindex = 0;



        for(int i=0;i<=(NUM_KEYS/2) + (NUM_KEYS%2);i++){
            par_Node->keys[i] =  temp_keys[i];
        }
        for(int i=0;i<=(NUM_KEYS/2) + (NUM_KEYS%2) + 1;i++){
            par_Node->child[i] =  temp_child[i];
        }


        par_Node->Tindex = (NUM_KEYS/2) + (NUM_KEYS%2) + 1;


        new_val = temp_keys[(NUM_KEYS/2) + (NUM_KEYS%2) + 1];

        for(int i=(NUM_KEYS/2) + (NUM_KEYS%2) + 2;i<=NUM_KEYS;i++){
            insertKey(new_Node, i - ((NUM_KEYS/2) + (NUM_KEYS%2) + 2), temp_keys[i]);

        }
        for(int i=(NUM_KEYS/2) + (NUM_KEYS%2) + 2;i<=NUM_KEYS+1;i++){
            new_Node->child[i - ((NUM_KEYS/2) + (NUM_KEYS%2) + 2)] = temp_child[i];

        }
        insert_in_parent(btree, par_Node, search_Stack, new_val, new_Node);

    }




}

BTreeNode* findValue_ins(BTree* btree, BStack* search_stack, long long value){
    BTreeNode* cur_Node = btree->root;
    int flagy;
    if(btree->only_root_flag == 1){
        return cur_Node;
    }
    while(1){
        if(cur_Node->type == LEAF){
            return cur_Node;

        }
        flagy = 0;
        for(int i=0;i<cur_Node->Tindex;i++){
            if(cur_Node->keys[i] > value){
                push(search_stack, cur_Node);
                push_c(search_stack, i);
                cur_Node = cur_Node->child[i];
                flagy = 1;
                break;
            }
        }
        if(flagy == 0){

            push(search_stack, cur_Node);
            push_c(search_stack, cur_Node->Tindex);
            cur_Node = cur_Node->child[search_stack, cur_Node->Tindex];
        }


    }
}


void trip(BTree* btree){

    int height = 120;
    BTreeNode* cur;
    inorder(btree, btree->root, height);

}
void inorder(BTree* btree, BTreeNode* cur, int height){
    if(cur == NULL) return;
    if(cur->type == ROOT && btree->only_root_flag == 1){
         for(int j=0;j<cur->Tindex;j++){
            for(int i=0;i<height;i++) printf(" ");
            printf("%lld\n", cur->keys[j]);
        
        } 
    }
    else if(cur->type == INTERNAL || cur->type == ROOT){
        int newh = height - 5;
        for(int j=0;j<cur->Tindex;j++){

            inorder(btree, cur->child[j], newh);

            for(int i=0;i<height;i++) printf(" ");

            printf("%lld\n", cur->keys[j]);
        
        }

        inorder(btree, cur->child[cur->Tindex], newh);
    }

    else if(cur->type == LEAF){
        for(int i=0;i<height-50;i++){
            printf(" ");
        }
        for(int i=0;i<cur->Tindex;i++){
            printf("%lld", cur->keys[i]);
            printf(" ");
        }
        printf("\n");
        return;
    }



}
