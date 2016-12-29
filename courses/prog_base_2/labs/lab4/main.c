#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"
#include "server.h"
#include "list.h"


int main(){
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);

    char buffer[10000];
    char bufferCopy[10000];
    socket_t * client = NULL;

    list_t * pupils = list_new();
    char jsonText[10000];
    FILE * fp = fopen("pupil.json","r");
    fread(jsonText,sizeof(char),10000,fp);
    pupil_createPupilsList(pupils,cJSON_Parse(jsonText));
    fclose(fp);

    while (1) {
		socket_t * client = socket_accept(server);
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
                //http_request_t req = http_get_request_parse(buffer);
                //printf("%s %s\n", req.form[1]->key, req.form[1]->value);
			}
			else if(strncmp(request.uri,"/api/pupils/",strlen("/api/pupils/"))==0){
			    int id;
			    int num = sscanf(request.uri, "/api/pupils/%d", &id);
                if(num != 0){
                        pupil_t * p = server_getPupilById(pupils,id);
                        if(p == NULL){
                            server_sendWrongIndex(client);

                        } else
                        server_sendJson(client,pupil_pupilToJson(p));
                }
			}
			else if(strcmp(request.uri, "/pupils")==0){
                server_sendListAsHtml(client,pupils);
			}
			else if(strncmp(request.uri,"/pupils/",strlen("/pupils/"))==0){
			    int id;
			    int num = sscanf(request.uri, "/pupils/%d", &id);
                if(num != 0){
                        pupil_t * p = server_getPupilById(pupils,id);
                        if(p == NULL){
                            server_wrongIndex_html(client);

                        } else
                        server_sendHtml(client,pupil_getHtml(p,pupil_getId(p)));
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
                    server_deletePupil_html(client,pupils,Id);
                }
                else {
                    server_wrongIndex_html(client);
                }
            }
		}
		else if (strcmp(request.method, "POST") == 0){
            if (strcmp(request.uri,"/api/pupils")==0) {
                server_addPupil(client,pupils,buffer);
            }
            else if (strcmp(request.uri,"/pupils")==0) {
                server_newHtmlPupil(client,pupils,buffer);
            }
		}

		socket_free(client);

	}


    socket_free(client);
    socket_free(server);
    list_free(pupils);
    lib_free();
    return 0;
}
