﻿#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_OF_SING_IN_MACHINE_NUMBER 4
#define NUM_OF_CARS 10


typedef struct post_s post_t;
typedef struct car_s car_t;
enum STATUS {
	POST_OK,
	POST_EMPTY,
	POST_INVALIDINDEX
};
post_t * post_create();
enum STATUS post_getStatus(post_t * self);
car_t * post_addVioletion(post_t * self);
int post_getMachineSpeed(post_t * self, int index);
int post_getNumOfCars(post_t * self);
char* post_getMachineNumber(post_t * self, int index);
char * post_getMachineViolation(post_t * self, int index);
int post_getNumOfPost(post_t * self, int index);
int post_getViolationFine(post_t * self, int index);
void post_remove(post_t * self);


#endif // POST_H_INCLUDED