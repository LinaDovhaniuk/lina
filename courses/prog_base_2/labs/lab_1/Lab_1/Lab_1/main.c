#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include "cmocka.h"
#include "cmocka_pbc.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "terminal.h"
#include "post.h"
#include <assert.h>


static void create_void_zeroCount(void **state){
	post_t* post = post_create();
	assert_int_equal(post_getNumOfCars(post), 0);
	post_remove(post);
}

static void getRandomViolation_void_someViolation(void ** state){
	assert_in_range(post_getRandomViolation(), 0, 7);
}

static void getNumOfCars_getsSomePost_CountOne(void ** state){
	post_t* post = post_create();
	post_addCar(post);
	assert_int_equal(post_getNumOfCars(post), 1);
	post_remove(post);
}

static void getMachineSpeed_getsSomePost_RandomSpeedFrom60to200(void ** state){
	post_t * post = post_create();
	post_addCar(post);
	assert_true(post_getMachineSpeed(post,0) > 60);
	post_remove(post);
}

static void post_getMachineNumber_getsPost_NumOfElemInMachineNumber(void ** state){
	post_t * post = post_create();
	post_addCar(post);
	int elem = sizeof(post_getMachineNumber(post, 0));
	assert_true(elem, == 11);
	post_remove(post);
}


int main(){
	srand(time(NULL));

	const struct CMUnitTest tests[] = {
		cmocka_unit_test(create_void_zeroCount),
		cmocka_unit_test(getRandomViolation_void_someViolation),
		cmocka_unit_test(getNumOfCars_getsSomePost_CountOne),
		cmocka_unit_test(getMachineSpeed_getsSomePost_RandomSpeedFrom60to200),
		cmocka_unit_test(post_getMachineNumber_getsPost_NumOfElemInMachineNumber),
		

};
	return cmocka_run_group_tests(tests, NULL, NULL);
	/*post_t* post = post_create();
	post_addCar(post);
	post_addCar(post);
	post_addCar(post);
	post_addCar(post);
	//terminal_printLetter(post);
	terminal_printAllViolation(post);
	post_remove(post);
	getchar();
	return 0;*/
}
