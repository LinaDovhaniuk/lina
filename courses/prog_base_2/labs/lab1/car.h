#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define NUM_OF_ELEM 11

typedef struct car_s car_t;
enum STATUS_CAR{
	CAR_OK,
	CAR_OVERFLOW,
	CAR_EMPTY,
	CAR_INVALIDINDEX
};

enum STATUS post_getStatus(car_t * self);

car_t * car_create();
car_t * car_addCar();

void car_setRandomViolation(car_t * CarSelf);
char * car_getMachineViolation(car_t * CarSelf);
void car_setViolation(car_t * CarSelf, char * violation);

void car_setRandomSpeed(car_t * CarSelf);
int car_getSpeed(car_t * CarSelf);

void car_setFine(car_t * CarSelf);
int car_getFine(car_t * CarSelf);

char * car_getMachineNumber(car_t * CarSelf);
void car_setRandomMachineNumber(car_t * CarSelf);

void car_remove(car_t * self);


#endif // CAR_H_INCLUDED