#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define MAX_NUM_OF_USERS 8
#define MAX_NUM_OF_EVENTS 5
#define MAX_NUM_OF_GROUPS 8
#include "user.h"
#include "headers.h"

struct helper_s{
	user_t  users[MAX_NUM_OF_USERS];
	int numOfUsers;

	group_t groups[MAX_NUM_OF_GROUPS];
	int numOfGroup;

	event_t events[MAX_NUM_OF_EVENTS];
	int numOfEvents;
};

helper_t helper_create();
int helper_addEvent(helper_t helper, event_t event);
void helper_notification(helper_t self);
void  helper_addUser(helper_t self, user_t user);
void  helper_addGroup(helper_t self, group_t group);
void helper_remove(helper_t self);


