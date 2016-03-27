#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_NUM 100

#include <windows.h>
#include "thread.h"
#include "mutex.h"
#include "DigitReader.h"

struct digitReader_s{
    thread_t * digRead;
};

digitReader_t * DigitReader_create(text_t * string){
    digitReader_t reader;
    reader.digRead = thread_create_args(DigitReader,string);
    return &setter;
}
 void DigitReader_remove(digitReader_t * self){
    thread_free(self->digRead);
 }

void * DigitReader(void* args){
    text_t * tmp = (text_t*)args;
    while(1){
        mutex_lock(tmp->mu);
        if(isdigit(tmp->symb[0])){
            printf("%c",tmp->symb[0]);
        }
        mutex_unlock(tmp->mu);
        Sleep(640000);
    }
    return NULL;
}
