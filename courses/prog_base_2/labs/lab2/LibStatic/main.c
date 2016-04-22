#include "queue.h"

struct queue_s {
    int head;
    int tail;
    int size;
    int value[MAX_QUEUE_SIZE];
};

queue_t queue_create(){
    queue_t queue = (queue_t)malloc(sizeof(struct queue_s));
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void queue_enqueueSomeWork(queue_t self,int val){
    if (self->size == MAX_QUEUE_SIZE){
        printf("Error!Overflow!");
    }
    else if(val > 24 || val < 0){
        printf("Invalid value!\n");
    }
    self->value[self->tail]= val;
    (self->tail)++;
    (self->size)++;
}

int queue_dequeueSomeWork(queue_t self){
    if(self->size == 0){
        printf("Error!Queue is EMRTY");
    }
    int delValue= self->value[0];
    for (int i = 0; i < self->size; i++){
        self->value[i] = self->value[i+1];
    }
    (self->size)--;
    (self->head)++;
    return delValue;
}

int queue_getSize(queue_t self){
    return self->size;
}

void queue_printAll(queue_t self){
    for(int i = 0; i < self->size; i++){
        printf("Hours worked : %i\n",self->value[i]);
    }
}

void queue_remove(queue_t self){
   free(self);
}

