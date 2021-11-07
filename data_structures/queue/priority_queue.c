/**
 * @file
 * @brief [Priority queue](https://en.wikipedia.org/wiki/Priority_queue) implementation
 * @details
 * priority queue is implemented using array upto 100 elements.
 * @author [Kumar Yash](https://github.com/kumaryash18)
 */
 
#include <stdio.h>	/// for IO operations
#include <stdlib.h>	/// for exit()
#include <stdint.h>	/// for uint8_t, uint32_t

/**
 * @brief structure to associate value with it's priority
 */
struct item {
	char value;			///< value to be stored in the queue
	uint8_t priority;	///< priority of the value
};

typedef struct item si;
uint32_t size = 100;		///< maximum size of the queue

/**
 * @brief array implementation of queue
 */
struct pq {
	si queue[100];		///< array queue
	int rear;			///< stores index of rear element
	int front;			///< stores index of front element
};
struct pq q;			///< global declaration of queue q

/**
 * @brief funtion to enque
 * @param item value to be enqued
 * @returns void
 */
void enque(si item) {
	if(q.rear == size-1) {
		printf("queue overflow...");
		exit(0);
	}
	
	if(q.rear == -1) {
		q.front=0; q.rear=0;
		q.queue[q.rear] = item;
	}
	else {
		int i;
		for(i = q.rear; i >= 0 && (q.queue[i].priority > item.priority); i--)
			q.queue[i+1] = q.queue[i];
		q.queue[i+1] = item; q.rear++;
	}
}

/**
 * @brief funtion to deque
 * @returns dequed value
 */
si deque() {
	si item;
	if(q.front == -1) {
		printf("queue underflow...");
		exit(0);
	}
	
	item = q.queue[q.front];
	if(q.front == q.rear) {
		q.front = -1;
		q.rear = -1;
	}
	else {
		int i;
		for(i = q.front+1; i <= q.rear; i++)
			q.queue[i-1] = q.queue[i];
		q.rear--;
	}
	return item;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	q.front = q.rear = -1;		/// initialize
	si temp;
	temp.value = 's';
	temp.priority = 3;
	enque(temp);
	temp.value = 'a';
	temp.priority = 2;
	enque(temp);
	printf("%c ", deque().value);
	printf("%c ", deque().value);
	printf("%c ", deque().value);
	return 0;
}
