#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pupil.h"

struct pupil {
    int id;
    char name[256];
    char surname[256];
    int Class;
    double score;
    double growth;
};

pupil_t * pupil_create(void) {
    return malloc(sizeof(struct pupil));
}

void pupil_remove(pupil_t * self) {
    free(self);
}

void pupil_addInfo(pupil_t * self, int id,char * name,char * surname, int Class, double score, double growth) {
    self->id = id;
    strcpy(self->name, name);
    strcpy(self->surname, surname);
    self->Class = Class;
    self->score = score;
    self->growth = growth;
}

char * pupil_getName(pupil_t * self){
    return self->name;
}

char * pupil_getSurname(pupil_t * self){
    return self->surname;
}

int pupil_getClass(pupil_t * self){
    return self->Class;
}

double pupil_getScore(pupil_t * self){
    return self->score;
}

double pupil_getGrowth(pupil_t * self){
    return self->growth;
}

