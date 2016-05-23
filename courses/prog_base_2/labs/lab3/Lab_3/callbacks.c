#include "callbacks.h"


void user_notification_firstCallback(user_t user, event_t event){
	printf("Dear %s, event %s (%s) start at %s",user->name,event->title,event->notification,ctime(&(event->time)));

}

void user_notification_secondCallback(user_t user, event_t event){
	printf("%s, attention please. Event %s (%s) start at %s", user->name, event->title, event->notification, ctime(&(event->time)));
	
}

void notification_group_callback(group_t group, event_t event){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("%s : \n", group->title);
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < group->numOfUsers; i++){
		printf("\t\t\t   %s\n", group->users[i]);
	}
	printf("event %s (%s) start at %s", event->title, event->notification, ctime(&(event->time)));
	
}



