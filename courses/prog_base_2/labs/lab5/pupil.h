#ifndef PUPIL_H_INCLUDED
#define PUPIL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "cJSON.h"
#include "list.h"
#include "http.h"
typedef struct pupil_s pupil_t;


pupil_t * pupil_create(void);
void pupil_remove(pupil_t * self);
void pupil_addInfo(pupil_t * self, int id,char * name,char * surname, int Class, double score, double growth);
char * pupil_getHtml(pupil_t* self, int Id);
cJSON * pupil_listToJson(list_t * pupils);
cJSON* pupil_pupilToJson(pupil_t * p);
char * pupil_getName(pupil_t * self);
char * pupil_getSurname(pupil_t * self);
int pupil_getClass(pupil_t * self);
double pupil_getScore(pupil_t * self);
double pupil_getGrowth(pupil_t * self);
int pupil_getId(pupil_t * self);

#endif // PUPIL_H_INCLUDED
