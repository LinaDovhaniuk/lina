#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_NUM 100

#include <windows.h>
#include "thread.h"
#include "mutex.h"


typedef struct text_s {
    char * symb;
    char str[MAX_NUM];
    int num;
    mutex_t * mu;
} text_t;

void * SymbolSetter(void * args){
    text_t *tmp = (text_t*)args;
    while(1){
        mutex_lock(tmp->mu);
        tmp->symb = &(tmp->str[tmp->num]);
        (tmp->num)++;
        if(tmp->num == 100){
            tmp->num = 0;
        }
        mutex_unlock(tmp->mu);
    }
    return NULL;
}

void * DigitReader(void* args){
    text_t * tmp = (text_t*)args;
    while(1){
        mutex_lock(tmp->mu);
        if(isdigit(tmp->symb[0])){
            printf("%c",tmp->symb[0]);
        }
        mutex_unlock(tmp->mu);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    text_t string;
    strcpy(string.str,"Hello 4841534 guys!\0");
    string.mu = mutex_new();
    string.num = 0;
    thread_t * firstSetter = thread_create_args( SymbolSetter, &string);
    thread_t * secondSetter = thread_create_args( SymbolSetter, &string);
    thread_t * firstReader = thread_create_args(DigitReader, &string);
    thread_t * secondReader = thread_create_args(DigitReader, &string);
    thread_t * thirdReader = thread_create_args(DigitReader, &string);
    thread_join(thirdReader);  // wait here
    thread_free(firstSetter);
    thread_free(secondSetter);
    thread_free(firstReader);
    thread_free(secondReader);
    thread_free(thirdReader);
    mutex_free(string.mu);
    return 0;
}
