#include "event.h"

event_t event_create(char * notification, char * title, time_t time, user_notification_cb user_callback, group_notification_cb group_callback){
	event_t self = (event_t)malloc(sizeof(struct event_s));
	strcpy(self->notification,notification);
	strcpy(self->title, title);
	self->time = time;
	self->callback = user_callback;
	self->group_callback = group_callback;
	return self;
}

void event_remove(event_t self){
	free(self);
}