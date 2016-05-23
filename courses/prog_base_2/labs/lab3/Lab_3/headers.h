#pragma once
#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !
#include "cmocka.h"

#define ERROR_USER_OVERFLOW "Sorry, you can`t add user!"
#define ERROR_EVENTS_OVERFLOW "Sorry, you can`t add event!"
#define MAX_NUM_OF_EVENTS_USER 8
#define MAX_NUM_OF_EVENTS_GROUP 8

typedef struct user_s * user_t;
typedef struct group_s * group_t;
typedef struct helper_s * helper_t;
typedef struct event_s * event_t;
typedef void(*user_notification_cb)(user_t user, event_t event);
typedef void(*group_notification_cb)(group_t group, event_t event);

