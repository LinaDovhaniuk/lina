#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX_QUEUE_SIZE 5
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_s * queue_t;

queue_t queue_create();
void queue_enqueueSomeWork(queue_t self,int value);
int queue_dequeueSomeWork(queue_t self);
int queue_getSize(queue_t self);
void queue_printAll(queue_t self);
void queue_remove(queue_t self);


#endif // QUEUE_H_INCLUDED
