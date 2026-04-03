typedef struct c_queue* queue; //definition of the queue type

queue newQueue(); //creates a new empty queue and returns a pointer to it 

int emptyQueue( queue q); //verifies if the queue is empty: returns 1 if the queue is empty otherwise if 0

int enqueue(queue q, int e); //add the element e to the tail of the queue and returns 1 if the operation goes right otherwise 0

int dequeue(queue q); //remove the element at the head of the queue , returns 1 if the operation goes right otherwise 0

