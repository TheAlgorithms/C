class MyCircularQueue {
public:
    int front=-1,rear=-1,size;
    int* queue;
    MyCircularQueue(int k) {
        size=k;
        queue=new int[k];
    }
    bool enQueue(int value) {
         if (isFull() ) 
         {
                return false;
         } 
        else 
        {
          if (front == -1) 
              front = 0;
          rear = (rear + 1) % size;
          queue[rear] = value;
          
        }
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) 
        {
            return false;
        } 
        else
        {
          if (front == rear)
          {
            front = -1;
            rear = -1;
          }
          else 
          {
            front = (front + 1) % size;
          }
        
        }
        return true;
    }
    
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        
        return queue[front];
    }
    
    int Rear() {
           if(isEmpty())
        {
            return -1;
        }
        
        return queue[rear];
    }
    
    bool isEmpty() {
        if(front == -1 )
            return true;
         else
            return false;
        
    }
    
    bool isFull() {
        if (front == 0 && rear == size - 1) {
            return true;
        }
        if (front == rear + 1) {
          return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
