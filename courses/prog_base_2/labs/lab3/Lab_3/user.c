#include "user.h"
#include "event.h"

user_t user_create(char * name){
	user_t  user = (user_t)malloc(sizeof(struct user_s));
	user->numOfEvents = 0;
	strcpy(user->name, name);
	return user;
}

char* user_getName(user_t user){
	return user->name;
}

void  user_addEvent(user_t self,event_t event){
	if (self->numOfEvents == MAX_NUM_OF_EVENTS){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("%s, %s\n",self->name, ERROR_EVENTS_OVERFLOW);
		SetConsoleTextAttribute(hConsole, 15);
		return;
	}
	self->events[self->numOfEvents++] = event;
}

void user_remove(user_t self){
	for (int i = 0; i < self->numOfEvents; i++){
		free(self->events[i]);
	}
	free(self);
}

group_t group_create(char * name){
	group_t group = (group_t)malloc(sizeof(struct group_s));
	strcpy(group->title, name);
	group->numOfEvents = 0;
	group->numOfUsers = 0;
	return group;
}
void group_addEvent(group_t self, event_t event){
	if (self->numOfEvents == MAX_NUM_OF_EVENTS){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("%s, %s\n",self->title, ERROR_EVENTS_OVERFLOW);
		SetConsoleTextAttribute(hConsole, 15);
		return ;
	}
	self->events[self->numOfEvents++] = event;
	return 0;
}
void group_remove(group_t self){
	for (int i = 0; i < self->numOfEvents; i++){
		free(self->events[i]);
	}
	for (int j = 0; j < self->numOfUsers; j++){
		free(self->users[j]);
	}
	free(self);
}

void group_addUser(user_t user, group_t group){
	if (group->numOfUsers == MAX_NUM_OF_USERS_IN_GROUP){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("%s, %s\n",group->title, ERROR_USER_OVERFLOW);
		SetConsoleTextAttribute(hConsole, 15);
		return ;
	}
	group->users[group->numOfUsers++] = user;
}

int group_getNumOfUsers(group_t group){
	return group->numOfUsers;
}
int group_getNumOfEvents(group_t group){
	return group->numOfEvents;
}
int user_getNumOfEvents(user_t user){
	return user->numOfEvents;
}



