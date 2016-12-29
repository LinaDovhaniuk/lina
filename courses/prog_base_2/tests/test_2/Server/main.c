#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <windows.h>

#include "list.h"
#include "server.h"
#include "dataBase.h"

int main(){
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);

    char buffer[10240];
    socket_t * client = NULL;

    const char * dbFile = "pupil.db";
    db_t * db = db_new(dbFile);

    list_t * pupil = list_new();

    while(1){
        client = socket_accept(server);
        socket_read(client, buffer, sizeof(buffer));

        if(strlen(buffer) != 0){
            printf(">> Got request:\n%s\n", buffer);
            http_request_t request = http_request_parse(buffer);

            if (strcmp(request.uri, "/info") == 0){
                server_info(client, &request);
            }
            else if (strcmp(request.uri, "/database") == 0){
                server_db(client, &request, db, pupil);
            }
            else if (strcmp(request.uri, "/dir-remove") == 0){
                server_sendInputPage(client,&request);
            }
            else if (strcmp(request.uri, "/removed") == 0){
                server_dir(client,&request);
            }


            else
            {
                server_notFound(client);
            }
        }
    }

    socket_free(client);
    socket_free(server);
    list_free(pupil);
    db_free(db);
    lib_free();
    return 0;
}

