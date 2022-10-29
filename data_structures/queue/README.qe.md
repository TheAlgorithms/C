
# What is a Circular Queue?
A circular queue is similar to a linear queue as it is also based on the FIFO (First In First Out) principle except that the last position is connected to the first position in a circular queue that forms a circle. It is also known as a Ring Buffer.

# Operations on Circular Queue
he following are the operations that can be performed on a circular queue:


Front: It is used to get the front element from the Queue.
Rear: It is used to get the rear element from the Queue.
enQueue(value): This function is used to insert the new value in the Queue. The new element is always inserted from the rear end.
deQueue(): This function deletes an element from the Queue. The deletion in a Queue always takes place from the front end.
# Scenarios for inserting an element
There are two scenarios in which queue is not full:

If rear != max - 1, then rear will be incremented to mod(maxsize) and the new value will be inserted at the rear end of the queue.
If front != 0 and rear = max - 1, it means that queue is not full, then set the value of rear to 0 and insert the new element there.
There are two cases in which the element cannot be inserted:

When front ==0 && rear = max-1, which means that front is at the first position of the Queue and rear is at the last position of the Queue.
front== rear + 1;
# Algorithm to insert an element in a circular queue

Step 1: IF (REAR+1)%MAX = FRONT
Write " OVERFLOW "
Goto step 4
[End OF IF]

Step 2: IF FRONT = -1 and REAR = -1
SET FRONT = REAR = 0
ELSE IF REAR = MAX - 1 and FRONT ! = 0
SET REAR = 0
ELSE
SET REAR = (REAR + 1) % MAX
[END OF IF]

Step 3: SET QUEUE[REAR] = VAL


Step 4: EXIT

# Dequeue Operation
The steps of dequeue operation are given below:

First, we check whether the Queue is empty or not. If the queue is empty, we cannot perform the dequeue operation.
When the element is deleted, the value of front gets decremented by 1.
If there is only one element left which is to be deleted, then the front and rear are reset to -1.
Algorithm to delete an element from the circular queue

Step 1: IF FRONT = -1
Write " UNDERFLOW "
Goto Step 4
[END of IF]

Step 2: SET VAL = QUEUE[FRONT]


Step 3: IF FRONT = REAR
SET FRONT = REAR = -1
ELSE
IF FRONT = MAX -1
SET FRONT = 0
ELSE
SET FRONT = FRONT + 1
[END of IF]
[END OF IF]

Step 4: EXIT