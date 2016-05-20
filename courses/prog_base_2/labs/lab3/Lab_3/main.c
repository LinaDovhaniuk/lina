#include "headers.h"
#include "callbacks.h"
#include "event.h"
#include "helper.h"
#include "user.h"


static void group_getNumOfUser_SomeUsers_CountTwo(void **state){
	group_t group = group_create("FirstGroup");
	user_t user1 = user_create("First");
	user_t user2 = user_create("Second");
	group_addUser(user1, group);
	group_addUser(user2, group);
	assert_int_equal(group_getNumOfUsers(group), 2);
}

static void group_addEvent_SomeGroupAndSomeEvent_countOne(void ** state){
	group_t group = group_create("FirstGroup");
	event_t event = event_create("Bla bla", "SomeEvent", time(0), NULL, NULL);
	group_addEvent(group, event);
	assert_int_equal(group_getNumOfEvents(group),1);
}

static void user_addEvent_SomeEvent_countOne(void ** state){
	user_t user = user_create("Blaaaaa");
	event_t event = event_create("Bla bla", "SomeEvent", time(0), NULL, NULL);
	user_addEvent(user, event);
	assert_int_equal(user_getNumOfEvents(user), 1);
}

static void user_getName_SomeUser_UsersName(void **state){
	user_t user = user_create("Lina");
	assert_string_equal(user_getName(user), "Lina");
}

static void user_create_SomeUsers_True(void ** state){
	user_t user = user_create("User1");
	assert_non_null(user);
}


int main(){
	
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(group_getNumOfUser_SomeUsers_CountTwo),
		cmocka_unit_test(group_addEvent_SomeGroupAndSomeEvent_countOne),
		cmocka_unit_test(user_getName_SomeUser_UsersName),
		cmocka_unit_test(user_create_SomeUsers_True),
		cmocka_unit_test(user_addEvent_SomeEvent_countOne),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);


	/*helper_t help = helper_create();
	user_t user1 = user_create("Lina");
	user_t user2 = user_create("Fedir");
	user_t user3 = user_create("Nina");
	user_t user4 = user_create("Sasha");
	group_t firstGroup = group_create("MY GROUP!!!!!!    :)    ");

	event_t ev1 = event_create("Cheking the level of knowledge", "Test", time(0),NULL, notification_group_callback);
	event_t ev2 = event_create("Leisure", "Recreation", time(0) + 1, YellowNotification_callback, NULL);
	event_t ev3 = event_create("No water in hostel", "Hell", time(0) + 2, WhiteNotification_callback, NULL);
	event_t ev4 = event_create("Cheking the level of knowledge", "Test", time(0) + 3, PinkNotification_callback, NULL);
	event_t ev5 = event_create("Leisure", "Recreation", time(0) + 4, NULL, notification_group_callback);
	event_t ev6 = event_create("No water in hostel", "Hell", time(0) + 5, WhiteNotification_callback, NULL);
	event_t ev7 = event_create("Cheking the level of knowledge", "Test", time(0) + 6, PinkNotification_callback, NULL);
	event_t ev8 = event_create("Leisure", "Recreation", time(0) + 7, YellowNotification_callback, NULL);
	event_t ev9 = event_create("Leisure", "Recreation", time(0) + 8, NULL, notification_group_callback);
	event_t ev10 = event_create("Leisure", "Recreation", time(0) + 8, YellowNotification_callback, NULL);

	group_addUser(user1, firstGroup);
	group_addUser(user4, firstGroup);

	group_addEvent(firstGroup, ev1);
	group_addEvent(firstGroup, ev5);
	group_addEvent(firstGroup, ev9);

	user_addEvent(user1, ev1);
	user_addEvent(user2, ev2);
	user_addEvent(user1, ev3);
	user_addEvent(user3, ev4);
	user_addEvent(user1, ev6);
	user_addEvent(user1, ev7);
	user_addEvent(user2, ev8);
	user_addEvent(user2, ev10);
	user_addEvent(user2, ev10);
	user_addEvent(user2, ev10);
	user_addEvent(user2, ev10);
	

	helper_addUser(help, user1);
	helper_addUser(help, user2);
	helper_addGroup(help, firstGroup);
	helper_notification(help);

	helper_remove(help);

	return 0;*/
}

