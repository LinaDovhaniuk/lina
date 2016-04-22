#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "queue.h"

typedef int (*check_func)(queue_t self);
typedef void (*reaction_func)(void);

typedef struct dynamic_s {
    HANDLE hLib;
    check_func check;
    reaction_func reaction;
} dynamic_t;

dynamic_t * dynamic_init(const char * dllName);
void dynamic_clean(dynamic_t * dyn);

const char * userChoice();

int main(void) {

    const char * dllName = userChoice();
    dynamic_t * dll = dynamic_init(dllName);
    if (NULL == dll) {
        printf("Can't load dynamic!\n");
        return 1;
    }
    if (NULL == dll->check) {
        printf("Can't get check function!\n");
        return 1;
    }
    if (NULL == dll->reaction) {
        printf("Can't get reaction function!\n");
        return 1;
    }
    printf("Dynamic loaded!");
    srand(time(NULL));
    int day = 1;
    queue_t queue = queue_create();
    while (1) {

        queue_enqueueSomeWork(queue,rand()%24);
        day++;
        if(day == 5){
            day = 1;
            if(dll->check(queue)){
                dll->reaction();
            }
            else printf("OK!\n");
        Sleep(88);
        queue_remove(queue);
        queue = queue_create();
        }

    }

    return 0;
}

const char * userChoice() {
    int dllNum = 0;
    while (dllNum < 1 || dllNum > 2) {
        printf("Choose DLL to load:\n1. Lab2DLL1\n2. Lab2DLL2\n> ");
        scanf("%i", &dllNum);
        if (dllNum == 1) {
            return "Lab2DLL1.dll";
        } else if (dllNum == 2) {
            return "Lab2DLL2.dll";
        }
    }
    return NULL;
}

dynamic_t * dynamic_init(const char * dllName) {
    dynamic_t * dyn = malloc(sizeof(struct dynamic_s));
    dyn->hLib = LoadLibrary(dllName);
    dyn->check = NULL;
    dyn->reaction = NULL;
    if (NULL != dyn->hLib) {
        dyn->check = (check_func)GetProcAddress(dyn->hLib, "Check");
        dyn->reaction = (reaction_func)GetProcAddress(dyn->hLib, "Reaction");
        return dyn;
    } else {
        return NULL;
    }
}

void dynamic_clean(dynamic_t * dyn) {
    FreeLibrary(dyn->hLib);
    free(dyn);
}


