#define _CRT_SECURE_NO_WARNINGS
#ifndef CLINIC_H_INCLUDED
#define CLINIC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_OF_PACIENTS 10
#define MAX_NUM_OF_DOCTORS 10

#include "list.h"



typedef struct pacient_s * pacient_t;
typedef struct doctor_s * doctor_t;
typedef struct clinic_s * clinic_t;
typedef void(*ñlinic_notification_cb)(clinic_t clinic, doctor_t doctor,pacient_t pacient);

doctor_t doctor_create();

int doctor_getNumOfPacients(doctor_t self);
char * doctor_getSpeciality(doctor_t self);

void doctor_remove(doctor_t self);

clinic_t clinic_create();

int clinic_getNumOfFreePlace(clinic_t self);
int clinic_getNumOfDoctors(clinic_t self);

void clinic_remove(clinic_t self);

pacient_t pacient_create();

char * pacient_getDiadnosis(pacient_t self);

void pacient_remove(pacient_t self);

#endif // CLINIC_H_INCLUDED
