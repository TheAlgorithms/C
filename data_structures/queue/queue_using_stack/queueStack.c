#include <stdio.h>

#define MAX 50 // max size of the queue

/* One stack as the queue and other as temporary storage */
int stack1[MAX];
int stack2[MAX];

int top1 = -1; // Top pointer for the main stack
int top2 = -1; // Top pointer for the temp stack
int count = 0; // Variable to keep track of the number of elements in the queue

// Push an element onto the main stack
void push1(int data){
    if(top1 == MAX - 1){
        printf("Error: Overflow\n");
    } else {
        stack1[++top1] = data; // Increment top pointer and add the element to the main queue
        count++; // Increment the count of elements in the queue
    }
}

// pop an element from the main stack
int pop1(){
    if(top1 == -1){
        printf("Error: Uderflow\n");
        return -1;
    } else {
        return stack1[top1--]; // Decrement top pointer and return the popped element
    }
}

// Function to push an element onto the temporary stack
void push2(int data){
    if(top2 == MAX - 1){
        printf("Error: Overflow\n");
    } else {
        stack2[++top2] = data; // Increment top pointer and add the element to the temporary stack
    }
}

// pop an element from the temporary stack
int pop2(){
    if(top2 == -1){
        printf("Error: Uderflow\n");
        return -1;
    } else {
        return stack2[top2--]; // Decrement top pointer and return the popped element from the temporary stack
    }
}

// enqueue an element into the queue
void enqueue(int data){
    push1(data); // Call push1 function to enqueue the element into the queue
}

// dequeue an element from the queue
int dequeue(){
    if(count == 0){
        printf("Queue is empty\n");
        return -1;
    }
    // Transfer elements from the main stack to the temporary stack
    while (top1 >= 0) {
        int val = pop1(); 
        push2(val);
    }
    
    int value = pop2(); // Pop the front element from the temporary stack
    count--; // Decrement the count of elements in the queue    
    
    // Transfer elements back from the temporary stack to the main queue
    while (top2 >= 0) {
        int temp = pop2();
        push1(temp);
    }
    
    return value; // Return the dequeued element

}

// Function to display the elements of the queue
void display(){
    if(top1 == -1){
        printf("Queue is empty\n");
    } else {
        for(int i = 0; i <= top1; i++){
            printf("%d ", stack1[i]);
        }
    }
}

int main(){

    /* enqueue and dequeue some demo elements to the queue*/
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    printf("Dequeued element: %d", dequeue());
    printf("\n");

    display();
}
