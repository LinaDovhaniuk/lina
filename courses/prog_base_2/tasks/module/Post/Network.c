#include "Network.h"

#define MAX_NUM_OF_POSTS 50
#define MAX_SIZE_OF_POST 100

struct list_s{
   post_t posts[MAX_NUM_OF_POSTS];
    int numOfPosts;
};

struct post_s{
    char * text;
    int numOfReposts;
};

list_t Network_create(){
    list_t rem = (list_t)malloc(sizeof(struct list_s));
    rem->numOfPosts = 0;
    return rem;
}

int Network_getNumOfReposts(list_t self, int indexOfPost){
    if(indexOfPost > Network_getNumOfPosts(self)){
        return -1;
    }
    return self->posts[indexOfPost]->numOfReposts;
}
void Network_deletePost(list_t self, int indexOfPost){
    for(int i = indexOfPost+1;  i < self->numOfPosts; i++){
        strcpy(self->posts[i-1]->text, self->posts[i]->text);
        self->posts[i-1]->numOfReposts = self->posts[i]->numOfReposts;
    }
    free(self->posts[self->numOfPosts-1]->text);
    free(self->posts[self->numOfPosts-1]);
    self->numOfPosts--;
}
void Network_addPost(list_t self, char * text){
    self->posts[self->numOfPosts] = (post_t)malloc(sizeof(struct post_s));
    self->posts[self->numOfPosts]->text = (char*)malloc(MAX_SIZE_OF_POST * sizeof(char));
    strcpy(self->posts[self->numOfPosts]->text,text);
    self->numOfPosts++;
}
void Network_addPostByIndex(list_t self, int indexOfPost, char* text){
    self->posts[self->numOfPosts] = (post_t)malloc(sizeof(struct post_s));
    self->posts[self->numOfPosts++]->text = (char*)malloc(MAX_SIZE_OF_POST * sizeof(char));
    for (int i = self->numOfPosts-1; i>=indexOfPost+1; i--){
        strcpy(self->posts[i]->text, self->posts[i-1]->text);
        self->posts[i]->numOfReposts = self->posts[i-1]->numOfReposts;
    }
    strcpy(self->posts[indexOfPost]->text,text);

}
int Network_getPostIndexWithMaxNumOfReposts(list_t self){
    int max = Network_getNumOfReposts(self,0);
    int index=0;
    for(int i = 1; i < self->numOfPosts; i++){
        if(Network_getNumOfReposts(self,i) > max){
            max = Network_getNumOfReposts(self,i);
            index = i;
        }
    }
    return index;
}
void Network_setNumOfRepost(list_t self){
    srand((unsigned)time(NULL));
    for(int i = 0; i < self->numOfPosts; i++){
        self->posts[i]->numOfReposts = rand()%88;
    }
}
char* Network_getPostByIndex(list_t self, int indexOfPost){
    if(indexOfPost > Network_getNumOfPosts(self)){
        return -1;
    }
    return self->posts[indexOfPost]->text ;
}

list_t Network_getArrayWithParameter(list_t self, int minNumOfReposts){
    list_t tmp = Network_create();
    for(int i = 0; i < self->numOfPosts; i++){
        if(Network_getNumOfReposts(self,i) > minNumOfReposts){
            Network_addPost(tmp, self->posts[i]->text);
            tmp->posts[tmp->numOfPosts - 1]->numOfReposts = Network_getNumOfReposts(self,i);
        }
    }
    return tmp;
}

int Network_getNumOfPosts(list_t self){
    return self->numOfPosts;
}

void Network_remove(list_t self){
    for (int i = 0; i< self->numOfPosts; i++){
        free(self->posts[i]->text);
    }
    for (int i = 0; i< self->numOfPosts; i++){
        free(self->posts[i]);
    }
    free(self);
}


