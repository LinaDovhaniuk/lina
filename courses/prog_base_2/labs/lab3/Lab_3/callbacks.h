#pragma once

#include "headers.h"
#include "user.h"
#include "event.h"


void YellowNotification_callback(user_t user, event_t event);
void WhiteNotification_callback(user_t user, event_t event);
void PinkNotification_callback(user_t user, event_t event);
void notification_group_callback(group_t group, event_t event);
void error_message_callback(user_t user, char * error);
