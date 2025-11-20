#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;

void create() {
    int n, i;
    struct node *pnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter data of each node:\n");
    for (i = 0; i < n; i++) {
        pnode = (struct node*)malloc(sizeof(struct node));
        if (!pnode) {
            printf("Memory Allocation Failed\n");
            return;
        }

        scanf("%d", &pnode->data);

        if (first == NULL) {
            first = last = pnode;
        } else {
            last->next = pnode;
            last = pnode;
        }
        last->next = first;
    }
}

void deletenode(int k) {
    if (first == NULL) {
        printf("List Empty\n");
        return;
    }

    struct node *p = first, *prev = last;

    do {
        if (p->data == k)
            break;
        prev = p;
        p = p->next;
    } while (p != first);

    if (p->data != k) {
        printf("Node not found\n");
        return;
    }

    if (first == last && p == first) {
        first = last = NULL;
    } else if (p == first) {
        first = first->next;
        last->next = first;
    } else if (p == last) {
        last = prev;
        last->next = first;
    } else {
        prev->next = p->next;
    }

    free(p);
    printf("Node Deleted\n");
}

void traverse() {
    if (first == NULL) {
        printf("List Empty\n");
        return;
    }

    printf("Circular Linked List: ");
    struct node *p = first;

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);

    printf("\n");
}

int main() {
    int ch, k;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Delete Node\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &k);
                deletenode(k);
                break;

            case 3:
                traverse();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
