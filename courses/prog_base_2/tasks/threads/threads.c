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
#include "DigitReader.h"


typedef struct text_s {
    char * symb;
    char str[MAX_NUM];
    int num;
    mutex_t * mu;
} text_t;

int main() {
    srand(time(NULL));
    text_t string;
    strcpy(string.str,"Hello 4841534 guys!\0");
    string.mu = mutex_new();
    string.num = 0;

    symbolSetter_t* firstSet = SymbolSetter_create(string);
    symbolSetter_t* secondSet = SymbolSetter_create(string);
    digitReader_t * firstReader = DigitReader_create(string);
    digitReader_t * secondReader = DigitReader_create(string);
    digitReader_t * thirdReader = DigitReader_create(string);
    symbolSetter_remove(self);
    symbolSetter_remove(self);
    DigitReader_remove(self);
    DigitReader_remove(self);
    DigitReader_remove(self);

    mutex_free(string.mu);
    return 0;
}
