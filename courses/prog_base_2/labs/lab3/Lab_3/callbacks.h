#pragma once

#include "headers.h"
#include "user.h"
#include "event.h"


void user_notification_firstCallback(user_t user, event_t event);
void user_notification_secondCallback(user_t user, event_t event);
void notification_group_callback(group_t group, event_t event);

