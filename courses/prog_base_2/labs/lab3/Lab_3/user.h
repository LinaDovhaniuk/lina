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
	user_notification_cb callback;
};

struct group_s{
	user_t users[MAX_NUM_OF_USERS_IN_GROUP];
	int numOfUsers;
	char title[256];
	group_notification_cb callback;
};

 
user_t user_create(char * name, user_notification_cb cb);

void user_remove(user_t self);

group_t group_create(char * title, group_notification_cb cb);
void group_remove(group_t self);
void group_addUser(user_t self, group_t group);
char* group_getTitle(group_t group);

user_notification_cb user_getCB(user_t user);
group_notification_cb group_getCB(group_t group);

int group_getNumOfUsers(group_t group);
char* user_getName(user_t user);
