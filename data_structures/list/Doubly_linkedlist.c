#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

// Insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", data);
}

// Delete a node by value
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;

    // Traverse to find the node
    while (temp != NULL && temp->data != data)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", data);
        return;
    }

    // Adjust pointers
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; // deleting head

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted node with value %d.\n", data);
}

// Display the list forward
void displayForward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display the list backward
void displayBackward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;

    printf("List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, data;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display Forward\n");
        printf("5. Display Backward\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                displayForward();
                break;
            case 5:
                displayBackward();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
