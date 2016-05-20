#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define MAX_NUM_OF_EVENTS 5
#include <stdlib.h>
#include <stdio.h>
#include "event.h"
#include "headers.h"
#define MAX_NUM_OF_USERS_IN_GROUP 15

struct user_s{
	char name[256];
	event_t events[MAX_NUM_OF_EVENTS];
	int numOfEvents;
	int countOfUsers;
};

struct group_s{
	user_t users[MAX_NUM_OF_USERS_IN_GROUP];
	int numOfUsers;
	char title[256];
	event_t events[MAX_NUM_OF_EVENTS];
	int numOfEvents;
};

 
user_t user_create(char * name);

void user_addEvent(user_t self, event_t event);
void user_remove(user_t self);

group_t group_create(char * name);
void group_addEvent(group_t self, event_t event);
void group_remove(group_t self);
void group_addUser(user_t self, group_t group);

int group_getNumOfUsers(group_t group);
int group_getNumOfEvents(group_t group);
char* user_getName(user_t user);
