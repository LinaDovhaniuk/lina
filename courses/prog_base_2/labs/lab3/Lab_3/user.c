#include "user.h"
#include "event.h"

user_t user_create(char * name, user_notification_cb cb){
	if (strlen(name) < 30 && cb != NULL){
		user_t user = (user_t)malloc(sizeof(struct user_s));
		strcpy(user->name, name);
		user->callback = cb;
		return user;
	}
	else {
		return NULL;
	}
}

char* user_getName(user_t user){
	return user->name;
}


void user_remove(user_t self){
	free(self);
}

group_t group_create(char * title, group_notification_cb cb){
	if (strlen(title) < 30 || cb != NULL){
		group_t group = (group_t)malloc(sizeof(struct group_s));
		strcpy(group->title, title);
		group->numOfUsers = 0;
		group->callback = cb;
		return group;
	}
	else return NULL;
}

void group_remove(group_t self){
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

char* group_getTitle(group_t group){
	return group->title;
}

user_notification_cb  user_getCB(user_t user){
	return user->callback;
}
group_notification_cb group_getCB(group_t group){
	return group->callback;
}



