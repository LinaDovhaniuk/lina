#include "helper.h"
#include "user.h"
#include "event.h"


helper_t helper_create(){
	helper_t helper = (helper_t)malloc(sizeof(struct helper_s));
	helper->numOfUsers = 0;
	helper->numOfGroup = 0;
	helper->numOfEvents = 0;
	return helper;
}

void helper_notification(helper_t self){
	int count = 0;
	while (count < self->numOfEvents){
		for (int i = 0; i < self->numOfEvents; i++){
			if (event_getNumOfUsers(self->events[i]) != 0){
				for (int j = 0; j < event_getNumOfUsers(self->events[i]); j++){
					user_notification_cb cb = user_getCB(self->users[j]);
					if (NULL != cb)
						cb(event_getUser(self->events[i], j), self->events[i]);
				}
			}
			if (event_getNumOfGroups(self->events[i]) != 0){
				for (int j = 0; j < event_getNumOfGroups(self->events[i]); j++){
					group_getCB(self->groups[j])(event_getGroup(self->events[i], j), self->events[i]);
				}
			}
			Sleep(1000);
			count++;
		}
	}
	


		/*int user_count = 0;
		int group_count = 0;
		for (int i = 0; i < self->numOfUsers; i++){
			for (int j = 0; j < self->users[i]->numOfEvents; j++){
				t = time(0);
				if (self->users[i]->events[j] != NULL && self->users[i]->events[j]->time < t){
					if (self->users[i]->events[j]->callback != NULL){
						self->users[i]->events[j]->callback(self->users[i], self->users[i]->events[j]);
						//event_remove(self->users[i]->events[j]);
						self->users[i]->events[j] = NULL;
					}
				}
				if (self->users[i]->events[j] != NULL){
					user_count++;
				}
			}
		}

		for (int i = 0; i < self->numOfGroup; i++){
			for (int j = 0; j < self->groups[i]->numOfEvents; j++){
				t = time(0);
				if (self->groups[i]->events[j] != NULL && self->groups[i]->events[j]->time < t){
					if (self->groups[i]->events[j]->group_callback != NULL){
						self->groups[i]->events[j]->group_callback(self->groups[i], self->groups[i]->events[j]);
						//event_remove(self->groups[i]->events[j]);
						self->groups[i]->events[j] = NULL;
					}
				}
				if (self->groups[i]->events[j] != NULL){
					group_count++;
				}
			}
		}
		Sleep(1000);
		if (user_count == 0 && group_count == 0)
			break;
		}*/
}

void  helper_addUser(helper_t self,user_t user){
	self->users[self->numOfUsers++] = user;
}

void  helper_addGroup(helper_t self, group_t group){
	self->groups[self->numOfGroup++] = group;
}

void helper_remove(helper_t self){
	free(self);
}

int helper_addEvent(helper_t helper, event_t event){
	if (helper->numOfEvents < MAX_NUM_OF_EVENTS){
		helper->events[helper->numOfEvents++] = event;
		return 1;
	}
	else {
		return 0;
	}
}