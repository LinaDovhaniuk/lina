#include "Network.h"
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

static void create_void_zeroCount(void **state){
	list_t list = Network_create();
	assert_int_equal(Network_getNumOfPosts(list), 0);
	Network_remove(list);
}

static void getNumOfPosts_hasOneNumOfPost_countOne(void **state){
	list_t list = Network_create();
	Network_addPost(list, "Hello");
	assert_int_equal(Network_getNumOfPosts(list), 1);
	Network_remove(list);
}
static void getNumOfReposts_hasSomeNumOsRepost_moreThanZero(void ** state){
	list_t list = Network_create();

	Network_addPost(list, "Hello");
	Network_setNumOfRepost(list);
	assert_true(Network_getNumOfReposts(list, 0) > 0);
	Network_remove(list);
}
static void getNumOfRepost_hasOneNumOfRepost_lessThanZero(void ** state){
	list_t list = Network_create();

	Network_addPost(list, "It`s so bed");
	Network_setNumOfRepost(list);
	assert_true(Network_getNumOfReposts(list, 0) > 0);
	Network_remove(list);
}
static void addPost_PushText_CheckOfCompilanceText(void ** state){
	list_t list = Network_create();
	Network_addPost(list, "Hello!");
	assert_string_equal(Network_getPostByIndex(list, 0), "Hello!");
	Network_remove(list);

}
static void addPostByIndex_PushText_hasInvalidIndex(void ** state){
	list_t list = Network_create();
	Network_addPostByIndex(list, -8, "Alohamora");
	assert_int_equal(Network_GetStatus(list), INVALID_INDEX);
	Network_remove(list);
}

static void addPostByIndex_PushText_hasPushedText(void ** state){
	list_t list = Network_create();
	Network_addPost(list, "Slooozhna");
	Network_addPostByIndex(list, 1, "Alohamora");
	assert_string_equal(Network_getPostByIndex(list, 1), "Alohamora");
	Network_remove(list);
}

static void deletePost_deleteByInvalidIndex(void ** state){
	list_t list = Network_create();
	Network_deletePost(list, 59);
	assert_int_equal(Network_GetStatus(list), INVALID_INDEX);
	Network_remove(list);
}
static void deletePost_createPost_removePost_unmodifiedNumOfPost(void ** state){
	list_t list = Network_create();
	Network_addPost(list, "Hello");
	Network_deletePost(list, 0);
	assert_int_equal(Network_getNumOfPosts(list), 0);
	Network_remove(list);
}
static void deletePost_hasNoPost_status(void ** state){
	list_t list = Network_create();
	Network_deletePost(list, 0);
	assert_int_equal(Network_GetStatus(list), NETWORK_EMPTY);
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(create_void_zeroCount),
		cmocka_unit_test(getNumOfPosts_hasOneNumOfPost_countOne),
		cmocka_unit_test(getNumOfReposts_hasSomeNumOsRepost_moreThanZero),
		cmocka_unit_test(getNumOfRepost_hasOneNumOfRepost_lessThanZero),
		cmocka_unit_test(addPost_PushText_CheckOfCompilanceText),
		cmocka_unit_test(addPostByIndex_PushText_hasInvalidIndex),
		cmocka_unit_test(addPostByIndex_PushText_hasPushedText),
		cmocka_unit_test(deletePost_deleteByInvalidIndex),
		cmocka_unit_test(deletePost_createPost_removePost_unmodifiedNumOfPost),

	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
