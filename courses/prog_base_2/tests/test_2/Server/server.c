#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "server.h"
#include "pupil.h"
#include "windows.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <windows.h>

static char * textToJSON(char * text);
static char * textToJSON(char * text){
    char * buffer = malloc(sizeof(char) * 10240);

    sprintf(buffer,
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/json\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(text), text);

    return buffer;
}


void server_notFound(socket_t * client)
{
    char buffer[1024] = "";
    char * pageText = "404 Page Not Found!";

    sprintf(buffer,
            "HTTP/1.1 404 Not Found\n"
            "Content-Type: text/html\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(pageText), pageText);

    socket_write_string(client, buffer);
    socket_close(client);
}

void server_info(socket_t * client, http_request_t * req){
    char buffer[10240] = "";

    if (strcmp(req->method, "GET") == 0){
        cJSON * jText = cJSON_CreateObject();
        cJSON_AddItemToObject(jText, "student", cJSON_CreateString("Lina Dovhaniuk"));
        cJSON_AddItemToObject(jText, "group", cJSON_CreateString("KP-51"));
        cJSON_AddItemToObject(jText, "variant", cJSON_CreateNumber(23));
        char * pageText = cJSON_Print(jText);

        char * text = textToJSON(pageText);
        strcat(buffer, text);
        free(text);
    }

    socket_write_string(client, buffer);
    socket_close(client);
}

void server_db(socket_t * client, http_request_t * req, db_t * db, list_t * pupil){
    char buffer[10240] = "";

    if (strcmp(req->method, "GET") == 0){
        db_parse(db, pupil);

    cJSON * jsonText =  cJSON_CreateArray();

    for (int i = 0; i < list_size(pupil); i++){
        cJSON *jPupil = cJSON_CreateObject();
            cJSON_AddItemToObject(jPupil, "name", cJSON_CreateString(pupil_getName(list_get(pupil,i))));
            cJSON_AddItemToObject(jPupil, "surname", cJSON_CreateString(pupil_getSurname(list_get(pupil,i))));
            cJSON_AddItemToObject(jPupil, "score", cJSON_CreateNumber(pupil_getScore(list_get(pupil,i))));
            cJSON_AddItemToObject(jPupil, "class", cJSON_CreateNumber(pupil_getClass(list_get(pupil,i))));
            cJSON_AddItemToObject(jPupil, "growth", cJSON_CreateNumber(pupil_getGrowth(list_get(pupil,i))));
        cJSON_AddItemToArray(jsonText,jPupil);
    }

        char * jsonArray = cJSON_Print(jsonText);

        strcat(buffer, jsonArray);
        free(jsonArray);
    }

    socket_write_string(client, buffer);
    socket_close(client);
}
int dir_exists(const char * dirname) {
    struct stat buffer;
    return (stat (dirname, &buffer) == 0) && S_ISDIR(buffer.st_mode);
}

void server_dir(socket_t * client, http_request_t * req){
    char buffer[10240] = "";
    if (strcmp(req->method, "POST") == 0) {
        char * title = (char *)http_request_getArg(req, "title");
        if( dir_exists(title) == 1){
            if(RemoveDirectoryA((LPCTSTR )title) == 1){
                cJSON *jResp = cJSON_CreateObject();
                cJSON_AddItemToObject(jResp, "Title", cJSON_CreateString(title));
                cJSON_AddItemToObject(jResp, "Status", cJSON_CreateString("Deleted"));
                char * response = cJSON_Print(jResp);
                sprintf(buffer,
                    "HTTP/1.1 200 OK\n"
                    "Content-Type: text/html\n"
                    "Content-Length: %zu\n"
                    "\n%s", strlen(response),response);
            }
        }
        else{
            cJSON *jResp = cJSON_CreateObject();
            cJSON_AddItemToObject(jResp, "Title", cJSON_CreateString(title));
            cJSON_AddItemToObject(jResp, "Status", cJSON_CreateString("Not exist"));
            char * response = cJSON_Print(jResp);
            sprintf(buffer,
            "HTTP/1.1 404 Not Found\n"
            "Content-Type: text/html\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(response), response);
        }

    }
    socket_write_string(client, buffer);
    socket_close(client);
}



void server_sendInputPage(socket_t* client,http_request_t * req){
    char buffer[10240] = "";
    if (strcmp(req->method, "GET") == 0){
	char page[2000];
	FILE* finput = fopen("input.html", "r");
	int len = fread(page, sizeof(char), sizeof(page) / sizeof(char), finput);
	page[len] = '\0';
	fclose(finput);

	 sprintf(buffer,
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/html\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(page), page);
    }
    socket_write_string(client, buffer);
    socket_close(client);
}


