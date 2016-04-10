#ifndef PUPIL_H_INCLUDED
#define PUPIL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

typedef struct pupils_s * pupils_t;
typedef struct pupil_s * pupil_t;

pupil_t pupil_create(void);
pupils_t pupils_create(void);
void pupil_ParseFromFile(pupils_t self, char * fileName);
//void print_pupils(xmlNode * a_node);
void pupils_remove(pupils_t self);

#endif // PUPIL_H_INCLUDED
