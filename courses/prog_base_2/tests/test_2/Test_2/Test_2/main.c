#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include <jansson.h>
#include "CURL\include\curl\curl.h"
#include "socket.h"
#include "server.h"

int mainINFO() {
	lib_init();
	socket_t * server = socket_new();
	socket_bind(server, 5000);
	socket_listen(server);
	FILE* input = fopen("scientists.json", "r");

	json_error_t error;
	json_t* root = json_loadf(input, 0, &error);
	fclose(input);

	char buf[10000];
	while (1) {
		socket_t * client = socket_accept(server);
		socket_read(client, buf, sizeof(buf));
		printf("%s", buf);
		server_request_t request = server_request_parse(buf);
		if (strcmp(request.method, "GET") == 0){
			if (strcmp(request.uri, "/") == 0){
				server_sendHomepage(client);
			}
			else if (strcmp(request.uri, "/scientists") == 0){
				server_sendJson(client, root);
			}
			else if (strcmp(request.uri, "/scientists/new") == 0){
				server_sendInputPage(client);
			}
			else if (strstr(request.uri, "/scientists/") != NULL){
				int id;
				int isNumber = sscanf(request.uri, "/scientists/%d", &id);
				if (isNumber){
					json_t* sc = server_getScientistById(root, id);
					if (NULL == sc) server_sendWrongIndex(client, id);
					else server_sendJson(client, sc);
				}
				else server_sendWrongIndexFormat(client, strstr(request.uri + 1, "/"));
			}
			else server_send404(client);
		}
		else if (strcmp(request.method, "DELETE") == 0){
			if (strstr(request.uri, "/scientists/") != NULL){
				int id;
				int isNumber = sscanf(request.uri, "/scientists/%d", &id);
				if (isNumber){
					json_t* response = server_deleteScientistById(root, id);
					server_sendJson(client, response);
				}
				else{
					json_t* wrongId = json_pack("{s:s,s:s}", "status", "ERROR", "description", "Wrong Id format");
					server_sendJson(client, wrongId);
				}
			}
			else server_send405(client);
		}
		else if (strcmp(request.method, "POST") == 0){
			char* queryPointer = strstr(request.uri, "/scientists?");
			if (queryPointer != NULL){
				json_t* newSc = server_createNewSc(root, queryPointer + strlen("/scientists?"), server_getCurrentFreeId(root));
				server_sendJson(client, newSc);
			}
			else if (strcmp(request.uri, "/scientists") == 0){
				char* browserQueryPointer = strstr(buf, "\r\n\r\n");
				json_t* newSc = server_createNewSc(root, browserQueryPointer + strlen("\r\n\r\n"), server_getCurrentFreeId(root));
				server_sendJson(client, newSc);
			}
			else server_send405(client);
		}
		else if (strcmp(request.method, "KEEPALIVE") == 0){
			//just catching, doing nothing
		}
		else server_send405(client);
		socket_free(client);
		
	}
	socket_free(server);
	lib_free();



	return 0;
}