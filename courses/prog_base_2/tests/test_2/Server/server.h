#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "socket.h"
#include "http.h"
#include "cJSON.h"
#include "dataBase.h"

void server_homepage(socket_t * client);
void server_notFound(socket_t * client);
void server_sendInputPage(socket_t* client,http_request_t * req);
void server_sendHtml(socket_t* client, char* pageText);
void server_info(socket_t * client, http_request_t * req);
void server_db(socket_t * client, http_request_t * req, db_t * db, list_t * pupil);
void server_dir(socket_t * client, http_request_t * req);
int dir_exists(const char * dirname);


#endif
