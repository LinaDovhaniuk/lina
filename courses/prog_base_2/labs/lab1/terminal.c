#include "terminal.h"
#include "post.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>

enum VIOLATION{
	stopping_rule,
	prohibited_signal,
	exit_at_crossroads,
	counter_strip,
	road_sings,
	phone,
	nothing
};

void terminal_printLetter(post_t * self){
	for (int i = 0; i < post_getNumOfCars(self); i++){
		if (post_getMachineViolation(self, i) != nothing || post_getMachineSpeed(self, i) > MAX_SPEED){
			printf("FINE!!!\n");
		}
	}
}

void pos(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void terminal_printAllViolation(post_t * self){
	int column1 = 0;
	int column2 = 0;
	int column3 = 0;
	pos(2, 1);
	printf("First Group Of Violations\n");
	pos(32, 1);
	printf("Second Group Of Violation\n");
	pos(64, 1);
	printf("Pravilnie rebyatushki\n");
	for (int i = 0; i < post_getNumOfCars(self); i++){

		if (post_getMachineViolationEnum(self, i) == stopping_rule || post_getMachineViolationEnum(self, i) == prohibited_signal || post_getMachineViolationEnum(self, i) == exit_at_crossroads){
			
			pos(2, 3 + 10 * column1);
			printf("Post :%i \n", post_getNumOfPost(self, i));
			pos(2, 4 + 10 * column1);
			printf("MachineNumber : %s\n", post_getMachineNumber(self, i));
			pos(2, 5 + 10 * column1);
			printf("Speed :%i\n", post_getMachineSpeed(self, i));
			pos(2, 6 + 10 * column1);
			printf("Fine : %i\n", post_getViolationFine(self, i));
			pos(2, 7 + 10 * column1);
			printf("Violation :%i\n", post_getMachineViolation(self, i));
			column1++;
		}
		else if (post_getMachineViolationEnum(self, i) == counter_strip || post_getMachineViolationEnum(self, i) == road_sings || post_getMachineViolationEnum(self, i) == phone){
			
			pos(32, 3 + 10 * column2);
			printf("Post :%i \n", post_getNumOfPost(self, i));
			pos(32, 4 + 10 * column2);
			printf("MachineNumber : %s\n", post_getMachineNumber(self, i));
			pos(32, 5 + 10 * column2);
			printf("Speed :%i\n", post_getMachineSpeed(self, i));
			pos(32, 6 + 10 * column2);
			printf("Fine : %i\n", post_getViolationFine(self, i));
			pos(32, 7 + 10 * column2);
			printf("Violation :%i\n", post_getMachineViolation(self, i));
			column2++;
		}
		else{
			
			pos(64, 3 + 10 * column3);
			printf("Post : %i \n", post_getNumOfPost(self, i));
			pos(64, 4 + 10 * column3);
			printf("MachineNumber : %s\n", post_getMachineNumber(self, i));
			pos(64, 5 + 10 * column3);
			printf("Speed : %i\n", post_getMachineSpeed(self, i));
			pos(64, 6 + 10 * column3);
			printf("Fine : %i\n", post_getViolationFine(self, i));
			pos(64, 7 + 10 * column3);
			printf("Violation :%s\n", post_getMachineViolation(self, i));
			column3++;
		}
	}
}