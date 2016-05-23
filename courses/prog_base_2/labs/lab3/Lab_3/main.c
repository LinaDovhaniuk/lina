#include "headers.h"
#include "callbacks.h"
#include "event.h"
#include "helper.h"
#include "user.h"


static void group_getNumOfUser_SomeUsers_CountTwo(void **state){
	group_t group = group_create("FirstGroup", notification_group_callback);
	user_t user1 = user_create("First", user_notification_firstCallback);
	user_t user2 = user_create("Second", user_notification_firstCallback);
	group_addUser(user1, group);
	group_addUser(user2, group);
	assert_int_equal(group_getNumOfUsers(group), 2);
}

static void user_getName_SomeUser_UsersName(void **state){
	user_t user = user_create("Lina", user_notification_firstCallback);
	assert_string_equal(user_getName(user), "Lina");
}

static void user_create_SomeUsers_True(void ** state){
	user_t user = user_create("User1", user_notification_firstCallback);
	assert_non_null(user);
}

static void event_getUserName_SomeEventAndWrongIndex_ErrorIndex(void ** state){
	event_t ev = event_create("Smth", "Title", time(0));
	event_getUserName(ev, 1);
	assert_int_equal(event_getStatus(ev), WRONG_INDEX);
}

static void  event_addGroup_SomeGroup_ErrorOverflow(void ** state){
	event_t ev = event_create("Smth", "Title", time(0));

	group_t g1 = group_create("FirstGroup", notification_group_callback);
	group_t g2 = group_create("FirstGroup", notification_group_callback);
	group_t g3 = group_create("FirstGroup", notification_group_callback);
	group_t g4 = group_create("FirstGroup", notification_group_callback);
	group_t g5 = group_create("FirstGroup", notification_group_callback);
	group_t g6 = group_create("FirstGroup", notification_group_callback);
	group_t g7 = group_create("FirstGroup", notification_group_callback);
	group_t g8 = group_create("FirstGroup", notification_group_callback);
	group_t g9 = group_create("FirstGroup", notification_group_callback);

	event_addGroup(ev, g1);
	event_addGroup(ev, g2);
	event_addGroup(ev, g3);
	event_addGroup(ev, g4);
	event_addGroup(ev, g5);
	event_addGroup(ev, g6);
	event_addGroup(ev, g7);
	event_addGroup(ev, g8);
	event_addGroup(ev, g9);
	assert_int_equal(event_getStatus(ev), OVERFLOW);
}


int main(){
	
	/*const struct CMUnitTest tests[] = {
		cmocka_unit_test(group_getNumOfUser_SomeUsers_CountTwo),
		cmocka_unit_test(user_getName_SomeUser_UsersName),
		cmocka_unit_test(user_create_SomeUsers_True),
		cmocka_unit_test(event_getUserName_SomeEventAndWrongIndex_ErrorIndex),
		cmocka_unit_test(event_addGroup_SomeGroup_ErrorOverflow)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);*/


	helper_t help = helper_create();
	user_t user1 = user_create("Lina", user_notification_secondCallback);
	user_t user2 = user_create("Fedir", user_notification_firstCallback);
	user_t user3 = user_create("Nina", user_notification_secondCallback);
	user_t user4 = user_create("Sasha", user_notification_secondCallback);
	user_t user5 = user_create("Alina", user_notification_firstCallback);
	group_t firstGroup = group_create("MY GROUP!!!!!!    :)    ", notification_group_callback);

	event_t ev1 = event_create("Cheking the level of knowledge", "Test", time(0));
	event_t ev2 = event_create("Leisure", "Recreation", time(0) + 1);
	event_t ev3 = event_create("No water in hostel", "Hell", time(0) + 2);
	event_t ev4 = event_create("Soon you will have a test", "Hard-work", time(0) + 3);
	

	helper_addEvent(help, ev1);
	helper_addEvent(help, ev2);
	helper_addEvent(help, ev3);
	helper_addEvent(help, ev4);

	event_addUser(ev2, user2);
	event_addUser(ev3, user3);
	event_addUser(ev1, user3);
	event_addUser(ev1, user5);
	event_addGroup(ev4, firstGroup);

	group_addUser(user1, firstGroup);
	group_addUser(user4, firstGroup);

		

	helper_addUser(help, user2);
	helper_addUser(help, user3);
	helper_addUser(help, user5);
	helper_addGroup(help, firstGroup);

	helper_notification(help);

	user_remove(user2);
	user_remove(user3);
	user_remove(user5);
	group_remove(firstGroup);
	helper_remove(help);

	event_remove(ev1);
	event_remove(ev2);
	event_remove(ev3);
	event_remove(ev4);
	getchar();
	return 0;
}

