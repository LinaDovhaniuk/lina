#include "clinic.h"

void clinicNotification_callback(clinic_t clinic,doctor_t doctor, pacient_t pacient){
	printf("Dear %s, patient  %s was added to your list of patients in %s clinic ! ",doctor->name,pacient->name, clinic->title);
}

struct pacient_s{
	char * name;
	char * doctor;
};

struct doctor_s{
	char * name;
	char * speciality;
	int numOfPacients;
	list_t * pacients;
};

struct clinic_s{
	char* title;
	int numOfDoctors;
	int numOfPacients;
	list_t * doctors;
	list_t * pacients;
	list_t * events;
};

typedef struct subs_s{
    void * receiver;
    ñlinic_notification_cb callback;
}subs_t;


doctor_t doctor_create(){
	doctor_t doctor = (doctor_t)malloc(sizeof(struct doctor_s));
	doctor->numOfPacients = 0;
	doctor->name = "\0";
	return doctor;
}

int doctor_getNumOfPacients(doctor_t self){
	return self->numOfPacients;
}

list_t * doctor_getPacientList(doctor_t self){
    return self->pacients;
}



void clinic_subs(clinic_t clinic,ñlinic_notification_cb callback) {
    subs_t * sb = malloc(sizeof(struct subs_s));
    sb->receiver = receiver;
    sb->callback = callback;
    list_add(clinic->events, sb);
}

void clinic_assign(clinic_t clinic, doctor_t doctor, pacient_t pacient){
    for(int i = 0; i < clinic->numOfDoctors; i ++){

    }
}

void pacient_addDoctor(doctor_t doctor,pacient_t pacient){
    doctor->numOfPacients[doctor->numOfPacients++] = pacient;
}

void clinic_event(clini_t c,subs_t sub, doctor_t d, pacient_t p){
    clinic_subs(c,sub->callback(clinic,d,p));
    clinic_addDoctor(c,d);
    clinic_addPacient(c,p);
    clinic_assign(c,d,p);
}



void doctor_remove(doctor_t self){
	for (int i = 0; i < self->numOfPacients; i++){
		free(self->pacients[i]);
	}
	free(self);
}

clinic_t clinic_create(){
	clinic_t clinic = (clinic_t)malloc(sizeof(struct clinic_s));
	clinic->numOfDoctors = 0;
	clinic->numOfPacients = 0;
	clinic->title = "\0";
	return clinic;
}

pacient_t clinic_removePacient(clinic_t clinic, pacient_t pacient){
    int index = -1;
    for(int i = 0; i < clinic->numOfPacients; i ++){
        if (strcmp(pacient->name,clinic->pacients[i]->name)==0){
            index = i;
            break;
        }
    }
    if (index == -1){
        return 0;
    } else
        return list_remove(clinic->pacients,index);
}

doctor_t cinic_removeDoctor(clinic_t clinic, doctor_t doctor){
    int index = -1;
    for(int i = 0; i < clinic->numOfDoctors; i ++){
        if (strcmp(doctor->name,clinic->doctors[i]->name)==0){
            index = i;
            break;
        }
    }
    if(index == -1){
        return 0;
    } else
        return list_remove(clinic->doctors,index);
}


void clinic_addPacient(clinic_t clinic, pacient_t pacient){
    list_add(clinic->pacients,pacient);
}

void clinic_addDoctor(clinic_t clinic, doctor_t doctor){
    list_add(clinic->doctors,doctor);
}

void clinic_remove(clinic_t self){
	for (int i = 0; i < self->numOfDoctors; i++){
		free(self->doctors[i]);
	}
	free(self);
}

pacient_t pacient_create(){
	pacient_t pacient = (pacient_t)malloc(sizeof(struct pacient_s));
	pacient->doctor = "\0";
	pacient->name = "\0";
	return pacient;
}
void pacient_remove(pacient_t self){
	free(self);
}



int clinic_getNumOfDoctors(clinic_t self){
	return self->numOfDoctors;
}

list_t  * clinic_getDoctorList(clinic_t self){
    return self->doctors;
}

int clinic_getNumOfPacients(clinic_t self){
	return self->numOfPacients;
}

list_t * clinic_getPacientList(clinic_t self){
    return self->pacients;
}

char* clinic_getClinicTitle(clinic_t clinic){
    return clinic->title;
}



