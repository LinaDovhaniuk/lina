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
void pupil_addInfo(pupil_t * self,char * name,char * surname,char * sex, char * birthday, int Class, double score,int year,int id);

char * pupil_getHtml(pupil_t* self, int Id);

char *pupil_getJSON(pupil_t * self);

char * pupil_getName(pupil_t * self);

char * pupil_getSurname(pupil_t * self);

int pupil_getClass(pupil_t * self);

double pupil_getScore(pupil_t * self);
char * pupil_getSex(pupil_t * self);
char * pupil_getBirthday(pupil_t * self);
int pupil_getYear(pupil_t * self);
void pupil_createPupilsList(list_t * self, cJSON * pupils);
int pupil_getId(pupil_t * self);
cJSON * pupil_listToJson(list_t * pupils);
cJSON* pupil_pupilToJson(pupil_t * pupil);
int checkInputData(char * name, char * surname, char * birthday,char * sex, char * Class, char * score, char * year);
int pupil_deletePupilById(list_t * pupils,int id);


#endif // PUPIL_H_INCLUDED
