#include "Network.h"
#include <assert.h>

int main(){

    list_t list = Network_create();

   Network_addPost(list,"Hello!!!!!!!! :) ");
   assert(strcmp(Network_getPostByIndex(list,0),"Hello!!!!!!!! :) ") == 0);
   assert(Network_getNumOfPosts(list) == 1);
   assert(Network_getPostByIndex(list,10)== -1);


   /*Network_addPost(list,"Hello!!!!!!!! :) ");

    Network_addPost(list,"!!!!!!!! :) ");
    Network_addPostByIndex(list,1, "Lina");
    printf("%s\n",Network_getPostByIndex(list,0));
    printf("%s\n",Network_getPostByIndex(list,1));
    printf("%s\n",Network_getPostByIndex(list,2));
    printf("%i\n",Network_getNumOfPosts(list));

    Network_setNumOfRepost(list);
    printf("%i\n",Network_getPostIndexWithMaxNumOfReposts(list));
    printf("%s\n",Network_getPostByIndex(list,0));
    printf("%s\n\n",Network_getPostByIndex(list,1));
    list_t array = Network_getArrayWithParameter(list,8);
    printf("%s\n",Network_getPostByIndex(array,0));
    //Network_deletePost(list,0);*/


    Network_remove(list);
    return 0;
}
