#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include <jansson.h>
#include "cJSON.h"
#include "CURL\include\curl\curl.h"
#include "socket.h"
#include "server.h"
#include "http.h"


char * textInfo(char * text){
	char * buffer = malloc(sizeof(char)* 10240);
		sprintf(buffer,
		"HTTP/1.1 200 OK\n"
		"Content-Type: text/json\n"
		"Content-Length: %zu\n"
		"\n%s", strlen(text), text);

	return buffer;
}

void server_info(socket_t * client, http_request_t * req){
	char buffer[10240] = ""; 
	if (strcmp(req->method, "GET") == 0)	{

		cJSON * jStudent = cJSON_CreateObject();
		cJSON_AddItemToObject(jStudent, "student", cJSON_CreateString("Lina Dovhaniuk"));
		cJSON_AddItemToObject(jStudent, "group", cJSON_CreateString("KP-51"));
		cJSON_AddItemToObject(jStudent, "variant", cJSON_CreateNumber(23));
		char * jsonString = cJSON_Print(jStudent);
		
		char * text = textInfo(jsonString);
		strcat(buffer, text);
		free(text); 
	}

	socket_write_string(client, buffer);
	socket_close(client);
}

int main(){
	lib_init();
	socket_t * server = socket_new();
	socket_bind(server, 5000);      
	socket_listen(server); 

	char buffer[10000];
	socket_t * client = NULL;

	while (1){
		client = socket_accept(server); 
		socket_read(client, buffer, sizeof(buffer));

		if (strlen(buffer) != 0) {
			printf(">> Got request:\n%s\n", buffer);
			http_request_t request = http_request_parse(buffer);
			if (strcmp(request.uri, "/") == 0){
				server_homepage(client);
			}
			else if (strcmp(request.uri, "/info") == 0){
				server_info(client, &request);
			}
			else
			{
				server_notFound(client);
			}
		}
	}

	socket_free(client);
	socket_free(server);
	lib_free();
	return 0;
}