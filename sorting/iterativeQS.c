int partition(void **A, int n, void *pivot){
    void * temp;
    int left = 0,j = 0;
    int right = n-1;
    int i = left;
    for (j=left;j<right;j++){
        if ((long)A[j] < (long)pivot){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[right] = A[i+1];
    A[i+1] = temp;
    return i+1;
}
void myQuicksort(void **A, int n) {
    Stack *s = stack_new();     /*making new stack and allocating memory*/
    stack_push(s,(int*)0);      /*pushing left and then right*/
    stack_push(s,(int*)(n-1));
    while (!stack_isEmpty(s)){
        int right = (int)stack_pop(s);  /*poping return right then left*/
        int left = (int)stack_pop(s);
        if (right-left >=1){
            int pivot = (right+left)/2;  /* taking middle element as pivot */
            int p = partition(A+left , right-left+1 , A[pivot]);/*getting partition index*/
            stack_push(s, (int*)left);  
            stack_push(s, (int*)(p-1));
            stack_push(s,(int*)(p+1));
            stack_push(s,(int*)right);
            }
        }
    }
