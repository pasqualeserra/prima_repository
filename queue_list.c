#include <stdio.h>
#include <stdlib.h>
#include "it.h"
#include "queue_list.h"

struct node {
int item;
struct node* next;
}; 

struct c_queue{
struct node* tail;
struct node* head;
int size;
};

queue newQueue()
{
    queue q; //creating the queue variable
    
    q = (queue)malloc(sizeof(struct c_queue)); //allocating dinamic memory in the heap for the pointer variable
    
    if( q == NULL )// verifiying if the allocation gone wrong 
    {
        printf("Not enough memory to create the queue."); //warning the user
    
        return NULL; //returning NULL value
    }

    q->head = NULL; //initializing the queue's head pointer at NULL value
    q->tail = NULL; //initializing the queue's tail pointer at NULL value
    q->size = 0; //initializing the queue's size at 0
    
    return q; //returning the queue variable
}

int emptyQueue( queue q)
{
    if( q -> size == 0)// checking if the size of the queue is equal to 0
        return 1; //returning 1 if that's true
    else 
        return 0;//returning 0 if the queue is not empty
}

int enqueue(queue q, int e)
{
    struct node* new = malloc(sizeof(struct node)); //allocating the memory space to store the new element of the queue
    if(new == NULL) //checking if the allocatin goes wrong
    {
        printf("Not enough memory to add the element to the queue."); //if that's the case i warn the user 
        return 0; //returning 0 to warn the user that the add gone wrong 
    }
    
    new->item = e; //initializing the item field of the new element with the value of the formal parameter
    new -> next = NULL; //iniatilizing the next field of the new element with the new value, because that's the tail of the queue
    q -> tail = new; //updating the queue's tail reference with the new element reference

    if(q -> size == 0)//checking if the size of the queue is 0 so the queue is empty
    {   
        q -> head = new; //if that is the case whe initialize the reference to the queue's head with the reference of the new element
    }
    (q -> size)++; //increasing the size of the queue
    return 1; //returning 1
}

int dequeue( queue q)
{
    if(q -> size == 0) //checking if the size of the queue is 0
    {
        printf("Impossible to remove an element in an empty queue."); //warning the user
        return 0; //returning 0 to represent failure 
    }

    struct node* temp = q -> head; //declaring and initializing a node pointer variable to store the reference of the head's element
    q->head = q->head->next; //updating the queue head's reference to the next element of the previous head 
    free(temp); //freeing up the space in memory allocated to store the previous head element
    (q -> size)--; //decreasing the queue's size

    return 1; //returning 1 to represent success
}