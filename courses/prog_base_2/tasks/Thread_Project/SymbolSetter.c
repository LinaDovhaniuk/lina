#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_NUM 100

#include <windows.h>
#include "thread.h"
#include "mutex.h"
#include "SymbolSetter.h"

struct symbolSetter_s{
    thread_t * SymbSet;
};

symbolSetter_t * SymbolSetter_create(text_t * string){
    sumbolSetter_t setter;
    setter.SymbSet = thread_create_args( SymbolSetter,string);
    return &setter;
}
void symbolSetter_remove(symbolSetter_t * self){
    thread_free(self->SymbSet);
 }

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
        Sleep(640000);
    }
    return NULL;
}
