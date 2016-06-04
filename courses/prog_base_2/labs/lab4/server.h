#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#include "pupil.h"
#include <windows.h>
#include "cJSON.h"
#include "socket.h"
#include "http.h"
typedef struct {
	char method[8];
	char uri[256];
} server_request_t;
server_request_t server_request_parse(char * request) ;

void server_notFound(socket_t * client);
void server_sendInputPage(socket_t* client,http_request_t * req);


pupil_t * server_getPupilById(list_t * l,int id);

void server_sendJson(socket_t* socket, cJSON* root);
void server_sendWrongIndex(socket_t * client);
void server_addPupil(socket_t * client,list_t * pupils,char * buf);
void server_sendWrongInputData(socket_t * client);

void server_sendHtml(socket_t* client, char* pageText);
void server_addPupilHtml(socket_t * client, list_t * pupils);
void server_wrongInputData_html(socket_t * client);
void server_wrongIndex_html(socket_t * client);
void server_deletePupil_html(socket_t * client,list_t * pupils, int id);
void server_sendAsHtml(list_t * pupils,socket_t * client);
void server_openPage(socket_t * client);
void server_newHtmlPupil(socket_t * client,list_t * pupils,char * buf);




#endif // SERVER_H_INCLUDED
