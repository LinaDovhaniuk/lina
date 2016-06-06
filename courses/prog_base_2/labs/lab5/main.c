#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"
#include "server.h"
#include "list.h"
#include "dataBase.h"


int main(){
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);

    const char * dbFile = "pupils.db";
    db_t * db = db_new(dbFile);

    char buffer[10000];
    char bufferCopy[10000];
    socket_t * client = NULL;

    list_t * pupils = list_new();
    db_parse(db,pupils);

    while (1) {
		 client = socket_accept(server);
		socket_read(client, buffer, sizeof(buffer));
		printf("%s", buffer);
		strcpy(bufferCopy, buffer);
		server_request_t request = server_request_parse(buffer);
		if (strcmp(request.method, "GET") == 0){
            if(strcmp(request.uri,"/")==0){
                server_openPage(client);
            }
			else if (strcmp(request.uri,"/api/pupils")==0){
                server_sendJson(client,pupil_listToJson(pupils));
			}
			else if (strstr(request.uri, "/api/pupils?") != 0){
                server_sendJson(client,db_task(db,buffer));
			}
			else if(strncmp(request.uri,"/api/pupils/",strlen("/api/pupils/"))==0){
			    int id;
			    int num = sscanf(request.uri, "/api/pupils/%d", &id);
                if(num != 0){
                        pupil_t * p = server_getPupilById(id,db);
                        if(p == NULL){
                            server_sendWrongIndex(client);

                        } else
                        server_sendJson(client,pupil_pupilToJson(p));
                }
			}
			else if(strcmp(request.uri, "/pupils")==0){
                server_sendTableAsHtml(client,db);
			}
			else if(strncmp(request.uri,"/pupils/",strlen("/pupils/"))==0){
			    int id;
			    int num = sscanf(request.uri, "/pupils/%d", &id);
                if(num != 0){
                        pupil_t * p = server_getPupilById(id,db);
                        if(p == NULL){
                            server_wrongIndex_html(client);

                        } else
                        server_sendHtml(client,pupil_getHtml(p,db_getPupilById(db,id)));
                }
			}
			else if(strcmp(request.uri, "/new-pupil")==0){
                server_addPupilHtml(client,pupils);
			}
		}
		else if (strcmp(request.method, "DELETE") == 0){
            if (strstr(request.uri, "/api/pupils/") != NULL){
				int id;
				int isNumber = sscanf(request.uri, "/api/pupils/%d", &id);
				if (isNumber){
                    server_deletePupil(client,pupils, id);
				}
				else{
					server_sendWrongIndex(client);
				}
            }
            else if (strstr(request.uri,"/pupils/")!= NULL){
                int Id;
                int num = sscanf(request.uri,"/pupils/%d", &Id);
                if(num){
                    server_deletePupil_html(client,pupils,Id,db);
                }
                else {
                    server_wrongIndex_html(client);
                }
            }
		}
		else if (strcmp(request.method, "POST") == 0){
            if (strcmp(request.uri,"/api/pupils")==0) {
                server_addPupil(client,pupils,buffer,db);
            }
            else if (strcmp(request.uri,"/pupils")==0) {
                server_newHtmlPupil(client,pupils,buffer,db);
            }
		}

		socket_free(client);

	}
    socket_free(client);
    socket_free(server);
    list_free(pupils);
    db_free(db);
    lib_free();
    return 0;
}

