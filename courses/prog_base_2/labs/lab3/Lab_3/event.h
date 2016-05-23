#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "callbacks.h"
#include "headers.h"


typedef enum {
	STATUS_OK,
	WRONG_INDEX,
	OVERFLOW,
	NULL_INPUT_DATA,
	UNDERFLOW
}STATUS;

struct event_s{
	char title[256];
	char notification[256];
	time_t time;
	user_t users[MAX_NUM_OF_EVENTS_USER];
	int numOfUsers;
	group_t groups[MAX_NUM_OF_EVENTS_GROUP];
	int numOfGroups;
	STATUS status;
};

event_t event_create(char * notification, char * title, time_t time);
void event_remove(event_t self);
char * event_getNotification(event_t self);
char * event_getUserName(event_t self, int index);
void event_addUser(event_t event, user_t user);
time_t event_getTime(event_t event);
user_t event_getUser(event_t event, int index);
int event_getNumOfUsers(event_t event);
int event_getNumOfGroups(event_t event);
group_t event_getGroup(event_t event, int index);
void event_addGroup(event_t event, group_t group);
STATUS event_getStatus(event_t self);