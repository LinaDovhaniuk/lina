#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct post_s* post_t;
typedef struct list_s* list_t;

enum Network_Error{
    NETWORK_SUCCESS,
    NETWORK_OVERFLOW,
    NETWORK_EMPTY,
    INVALID_INDEX
};


list_t Network_create();

int Network_getNumOfReposts(list_t self, int indexOfPost);
int Network_getNumOfPosts(list_t self);
void Network_deletePost(list_t self, int indexOfPost);
void Network_addPost(list_t self, char * text);
void Network_addPostByIndex(list_t self, int indexOfPost, char* text);
int Network_getPostIndexWithMaxNumOfReposts(list_t self);
void Network_setNumOfRepost(list_t self);
char* Network_getPostByIndex(list_t self, int indexOfPost);
list_t Network_getArrayWithParameter(list_t self, int minNumOfReposts);
enum Network_Error Network_GetStatus(list_t self);

void Network_remove(list_t self);


#endif // NETWORK_H_INCLUDED
