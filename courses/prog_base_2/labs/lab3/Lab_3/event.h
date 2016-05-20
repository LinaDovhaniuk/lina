#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "callbacks.h"
#include "headers.h"


struct event_s{
	char title[256];
	char notification[256];
	time_t time;
	user_notification_cb callback;
	group_notification_cb group_callback;
};

event_t event_create(char * notification, char * title, time_t time, user_notification_cb user_callback, group_notification_cb group_callback);
void event_remove(event_t self);