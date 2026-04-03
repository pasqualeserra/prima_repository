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

