#include "car.h"
#include "post.h"
#include <time.h>

struct car_s{
	char machineNumber[NUM_OF_ELEM];
	int speed;
	char * viol;
	int viol_index;
	int status;
	int fine;
};

car_t * car_create(){
	car_t * c = (car_t *)malloc(sizeof(struct car_s));
	c->status = CAR_EMPTY;
	return c;
}

void car_setRandomMachineNumber(car_t * CarSelf){
	sprintf(CarSelf->machineNumber, "%c%c %d%d%d%d %c%c", rand() % 26 + 65, rand() % 26 + 65, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 26 + 65, rand() % 26 + 65);
}

char * car_getMachineNumber(car_t * CarSelf){
	return CarSelf->machineNumber;
}

int car_getSpeed(car_t * CarSelf){
	return CarSelf->speed;
}

void car_setRandomSpeed(car_t * CarSelf){
	CarSelf->speed = rand() % 100 + 50;
	car_setFine(CarSelf);
}

void car_setFine(car_t * CarSelf){
	if ((CarSelf->speed) > 100){
		CarSelf->fine = (CarSelf->speed) * 3;
		car_setViolation(CarSelf, "speeding");
	}
	else CarSelf->fine = 0;
}

int car_getFine(car_t * CarSelf){
	return CarSelf->fine;
}

char * car_getMachineViolation(car_t * CarSelf){
	return CarSelf->viol;
}

enum VIOLATION car_getMachineViolationEnum(car_t * CarSelf){
	return (enum VIOLATION)CarSelf->viol_index;
}

void car_setViolation(car_t * CarSelf, char * violation){
	CarSelf->viol = violation;
	CarSelf->viol_index = 6;
}

void car_setRandomViolation(car_t * CarSelf){
	const char * arrayOfViolations[] = {
		"stopping_rule",
		"prohibited_signal",
		"exit_at_crossroads",
		"counter_strip",
		"road_sings",
		"phone",
		"",
		"nothing"
	};
	int ind = 0;
	do{
		ind = rand() % 8;
	} while (ind == 6);
	CarSelf->viol_index = ind;
	CarSelf->viol = arrayOfViolations[ind];
}

car_t * car_addCar(){
	car_t * car = car_create();
	car_setRandomSpeed(car);
	if (car->speed < 100)
		car_setRandomViolation(car);
	car_setRandomMachineNumber(car);
	return car;
}


void car_remove(car_t * self){
		free(self);
}