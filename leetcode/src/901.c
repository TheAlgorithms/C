// Use monotonic stack.
// Keep the stack of monotonically increasing price and index.

// Runtime: O(n)
// Space: O(n)
typedef struct stack{
    int price;
    int index;
    struct stack* previous;
} Stack;


typedef struct {
    int index;
    Stack* stackPointer;
    Stack* sentry;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    Stack* sentry = (Stack *)malloc(sizeof(Stack));
    StockSpanner* result = (StockSpanner *)malloc(sizeof(StockSpanner));
    result->index = 0;
    result->sentry = sentry;
    result->stackPointer = sentry;
    return result;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    while(obj->stackPointer != obj->sentry && obj->stackPointer->price <= price){
        Stack* currStackPointer = obj->stackPointer;
        obj->stackPointer = obj->stackPointer->previous;
        free(currStackPointer);
    }
    
    obj->index += 1;
    int result = obj->index;
    if (obj->stackPointer != obj->sentry){
        result -= obj->stackPointer->index;
    }
    
    Stack* newStackItem = (Stack *)malloc(sizeof(Stack));
    newStackItem->index = obj->index;
    newStackItem->price = price;
    newStackItem->previous = obj->stackPointer;
    obj->stackPointer = newStackItem;
    
    return result;
}

void stockSpannerFree(StockSpanner* obj) {
    while(obj->stackPointer != obj->sentry){
        Stack* currStackPointer = obj->stackPointer;
        obj->stackPointer = obj->stackPointer->previous;
        free(currStackPointer);
    }

    free(obj->sentry);
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
 */
