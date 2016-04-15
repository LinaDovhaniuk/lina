#include "post.h"
#include "car.h"
#include <time.h>


struct post_s{
	struct car_s * arrayOfCars[NUM_OF_CARS];
	int numOfPost;
	int numOfCars;
	int status;
};


enum VIOLATION{
	post_stoppingRule,
	post_prohibitedSignal,
	post_exitAtCrossroads,
	post_counterStrip,
	post_roadSings,
	post_phone,
	post_speeding,
	post_nothing
};


enum VIOLATION post_getRandomViolation(){
	return (enum VIOLATION)(rand() % 7);
}

enum STATUS post_getStatus(post_t * self){
	return self->status;
}

post_t * post_create(){
	post_t * p = (post_t *)malloc(sizeof(struct post_s));
	p->numOfCars = 0;
	p->status = POST_EMPTY;
	return p;
}

car_t * post_addViolation(post_t * self){
	car_t * car = car_create();

	car = self->arrayOfCars[self->numOfCars] = car_addCar();
	self->numOfPost = rand() % 5 + 1;
	self->status = POST_OK;
	(self->numOfCars)++;
	return self->arrayOfCars[self->numOfCars - 1];
}

int post_getMachineSpeed(post_t * self, int index){
	if (index > NUM_OF_CARS || index < 0){
		self->status = POST_INVALIDINDEX;
		return -1;
	}
	self->status = POST_OK;
	return car_getSpeed(self->arrayOfCars[index]);
}

int post_getNumOfCars(post_t * self){
	self->status = POST_OK;
	return self->numOfCars;
}
char* post_getMachineNumber(post_t * self, int index){
	if (index >= NUM_OF_CARS || index < 0){
		self->status = POST_INVALIDINDEX;
		return -1;
	}
	self->status = POST_OK;
	return car_getMachineNumber(self->arrayOfCars[index]);
}
char * post_getMachineViolation(post_t * self, int index){
	
	if (index >= NUM_OF_CARS || index < 0){
		self->status = POST_INVALIDINDEX;
		return -1;
	}
	self->status = POST_OK;
	return car_getMachineViolation(self->arrayOfCars[index]);
}

enum VIOLATION * post_getMachineViolationEnum(post_t * self, int index){
	if (index >= NUM_OF_CARS || index < 0){
		self->status = POST_INVALIDINDEX;
		return -1;
	}
	self->status = POST_OK;
	return car_getMachineViolationEnum(self->arrayOfCars[index]);
}

int post_getNumOfPost(post_t * self, int index){
	if (index >= NUM_OF_CARS || index < 0){
		self->status = POST_INVALIDINDEX;
		return -1;
	}
	self->status = POST_OK;
	return self->numOfPost;
}
int post_getViolationFine(post_t * self, int index){
	if (index >= NUM_OF_CARS || index < 0){
		self->status = POST_INVALIDINDEX;
		return -1;
	}
	self->status = POST_OK;
	return car_getFine(self->arrayOfCars[index]);
}



void post_remove(post_t * self){
	free(self);
}