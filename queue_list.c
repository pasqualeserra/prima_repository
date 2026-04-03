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