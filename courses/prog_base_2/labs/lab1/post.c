#include "post.h"
#include <time.h>


struct post_s{
	struct car_s * arrayOfCars[NUM_OF_CARS];
	int numOfPost;
	int numOfCars;
	int * fine[NUM_OF_CARS];
	int status;
};
struct car_s{
	char machineNumber[11];
	int speed;
	char viol;
};

enum VIOLATION{
	stopping_rule,
	prohibited_signal,
	exit_at_crossroads,
	counter_strip,
	road_sings,
	phone,
	nothing
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
	return p;
}

car_t * post_addCar(post_t * self){
	self->arrayOfCars[self->numOfCars] = (car_t*)malloc(sizeof(struct car_s));
	sprintf(self->arrayOfCars[self->numOfCars]->machineNumber, "%c%c %d%d%d%d %c%c", rand() % 26 + 65, rand() % 26 + 65, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 26 + 65, rand() % 26 + 65);
	self->arrayOfCars[self->numOfCars]->speed = rand() % 120 + 80;
	self->numOfPost = rand() % 5 + 1;
	self->arrayOfCars[self->numOfCars]->viol = post_getRandomViolation();
	for (int i = 0; i < self->numOfCars + 1; i++){
		if (self->arrayOfCars[i]->speed > 100){
			self->fine[i] = (self->arrayOfCars[i]->speed) * 3;
		}
		else
			self->fine[i] = (self->arrayOfCars[i]->speed) * 0;
	}
	self->status = POST_OK;
	(self->numOfCars)++;
	return self->arrayOfCars[self->numOfCars - 1];
}
int post_getMachineSpeed(post_t * self, int index){
	return self->arrayOfCars[index]->speed;
}

int post_getNumOfCars(post_t * self){
	return self->numOfCars;
}
char* post_getMachineNumber(post_t * self, int index){
	return self->arrayOfCars[index]->machineNumber;
}
char * post_getMachineViolation(post_t * self, int index){
	const char * arrayOfViolations[] = {
		"stopping_rule",
		"prohibited_signal",
		"exit_at_crossroads",
		"counter_strip",
		"road_sings",
		"phone",
		"nothing"
	};
	return arrayOfViolations[self->arrayOfCars[index]->viol];
}
enum VIOLATION * post_getMachineViolationEnum(post_t * self, int index){
	return self->arrayOfCars[index]->viol;
}
int post_getNumOfPost(post_t * self, int index){
	return self->numOfPost;
}
int post_getViolationFine(post_t * self, int index){
	return self->fine[index];
}



void post_remove(post_t * self){
	for (int i = 0; i<self->numOfCars; i++){
		free(self->arrayOfCars[i]);
	}
	free(self);
}
