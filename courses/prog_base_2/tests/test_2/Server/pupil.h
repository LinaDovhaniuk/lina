#ifndef PUPIL_H_INCLUDED
#define PUPIL_H_INCLUDED

typedef struct pupil pupil_t;

pupil_t * pupil_create(void);
void pupil_remove(pupil_t * self);

void pupil_printOne(pupil_t * self);
void pupil_printAll(pupil_t * self, int size);
void pupil_addInfo(pupil_t * self, int id, char * name, char * surname, int Class, double score, double growth);
char * pupil_getName(pupil_t * self);
char * pupil_getSurname(pupil_t * self);
int pupil_getClass(pupil_t * self);
double pupil_getGrowth(pupil_t * self);
double pupil_getScore(pupil_t * self);


#endif // PUPIL_H_INCLUDED
