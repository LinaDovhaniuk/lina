#include "event.h"

event_t event_create(char * notification, char * title, time_t time){
	if (strlen(title) == 0 || time < 0){
		return NULL;
	}
	event_t self = (event_t)malloc(sizeof(struct event_s));
	strcpy(self->notification,notification);
	strcpy(self->title, title);
	self->time = time;
	self->numOfUsers = 0;
	self->numOfGroups = 0;
	return self;
}

void event_remove(event_t self){
	if (self == NULL){
		self->status = UNDERFLOW;
		return;
	}
	free(self);
}

char * event_getNotification(event_t self){
		return self->notification;
}

char * event_getUserName(event_t self, int index){
	if (index < 0 || index >= self->numOfUsers)
		self->status = WRONG_INDEX;
	else
		return user_getName(self->users[index]);
}


void event_addUser(event_t event, user_t user){
	if (event->numOfUsers >= MAX_NUM_OF_EVENTS_USER)
		event->status = OVERFLOW;
	else if (event == NULL || user == NULL)
		event->status = NULL_INPUT_DATA;
	else{
		event->users[event->numOfUsers++] = user;
		event->status= STATUS_OK;
	}
}

void event_addGroup(event_t event, group_t group){
	if (event->numOfGroups >= MAX_NUM_OF_EVENTS_GROUP)
		event->status = OVERFLOW;
	else if (event == NULL || group == NULL)
		event->status = NULL_INPUT_DATA;
	else{
		event->groups[event->numOfGroups++] = group;
		event->status = STATUS_OK;
	}
}


time_t event_getTime(event_t event){
		return event->time;
}

user_t event_getUser(event_t event, int index){
	if (index < 0 || index > event->numOfUsers){
		event->status = WRONG_INDEX;
		return NULL;
	}
	else
		return event->users[index];
}

group_t event_getGroup(event_t event, int index){
	if (index < 0 || index > event->numOfGroups){
		event->status = WRONG_INDEX;
		return NULL;
	}
	else
		return event->groups[index];
}

int event_getNumOfUsers(event_t event){
	if (event != NULL)
		return event->numOfUsers;
}

int event_getNumOfGroups(event_t event){
		return event->numOfGroups;
}

STATUS event_getStatus(event_t self){
	return self->status;
}