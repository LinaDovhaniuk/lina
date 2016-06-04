#include "server.h"


server_request_t server_request_parse(char * request) {
	server_request_t req;
	if (request[0] == '\0'){
		strcpy(req.method, "KEEPALIVE");
		strcpy(req.uri, "/");
		return req;
	}
	ptrdiff_t methodLen = strstr(request, " ") - request;
	memcpy(req.method, request, methodLen);
	req.method[methodLen] = '\0';
	const char * uriStartPtr = request + strlen(req.method) + 1;
	const char * uriEndPtr = strstr(uriStartPtr, " ");
	ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
	memcpy(req.uri, uriStartPtr, uriLen);
	req.uri[uriLen] = '\0';
	return req;
}

void server_notFound(socket_t * client){
    char buffer[1024] = "";
    char * pageText = "404 Page Not Found!";

    sprintf(buffer,
            "HTTP/1.1 404 Not Found\n"
            "Content-Type: text/html\n"
            "Content-Length: %u\n"
            "\n%s", strlen(pageText) + 1, pageText);

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
            "Content-Length: %u\n"
            "\n%s", strlen(page), page);
    }
    socket_write_string(client, buffer);
    socket_close(client);
}

void server_sendHtml(socket_t* client, char* pageText){
	char homeBuf[10024];
	sprintf(homeBuf,
		"HTTP/1.1 %s\n"
		"Content-Type: text/html\n"
		"Content-Length: %d\n"
		"Connection: keep-alive\r\n\r\n"
		"\n%s",  "200 OK", strlen(pageText)+1, pageText);
	socket_write_string(client, homeBuf);
	socket_close(client);
}

void server_sendJson(socket_t* socket, cJSON* root){
	char * buffer = malloc(sizeof(char) * 10240);
	char * json = cJSON_Print(root);
	sprintf(buffer,
		"HTTP/1.1 200 OK\n"
		"Content-Type: application/json\n"
		"Content-Length: %d\n"
		"Connection: keep-alive\r\n\r\n"
		"%s", strlen(json), json);
    socket_write_string(socket, buffer);
	socket_close(socket);
}

pupil_t * server_getPupilById(list_t * l,int id){
    for(int i = 0; i < list_getSize(l); i++){
        pupil_t * p = list_get(l,i);
        if(pupil_getId(p) == id){
            return p;
        }
    }
    return NULL;
}

void server_deletePupil(socket_t * client,list_t * l,int id){
    if(pupil_deletePupilById(l,id) == 1){
        cJSON *jResp = cJSON_CreateObject();
        cJSON_AddItemToObject(jResp, "status", cJSON_CreateString("Ok"));
        cJSON_AddItemToObject(jResp, "description", cJSON_CreateString("Pupil with this Id deleted"));
        server_sendJson(client,jResp);
    }
    else server_sendWrongIndex(client);
}

void server_sendWrongIndex(socket_t * client){
    cJSON *jResp = cJSON_CreateObject();
    cJSON_AddItemToObject(jResp, "status", cJSON_CreateString("Error"));
    cJSON_AddItemToObject(jResp, "description", cJSON_CreateString("Pupil with this Id does not exist"));
	server_sendJson(client, jResp);
}

void server_sendWrongInputData(socket_t * client){
    cJSON *jResp = cJSON_CreateObject();
    cJSON_AddItemToObject(jResp, "status", cJSON_CreateString("Error"));
    cJSON_AddItemToObject(jResp, "description", cJSON_CreateString("Wrong input data"));
	server_sendJson(client, jResp);
}

void server_addPupil(socket_t * client,list_t * pupils,char * buf){

        http_request_t req = http_request_parse(buf);
        int id = pupil_getMaxId(pupils) + 1;
        char * name = (char *)http_request_getArg(&req, "name");
        char * surname = (char *)http_request_getArg(&req, "surname");
        char * birthday = (char *)http_request_getArg(&req, "birthday");
        char * sex = (char *)http_request_getArg(&req,"sex");
        char * score = (char *)http_request_getArg(&req, "score");
        char * Class = (char *)http_request_getArg(&req, "class");
        char * year = (char *)http_request_getArg(&req,"year");

        if(checkInputData(name,surname,birthday,sex,Class,score,year) == 1){
            pupil_t * p = pupil_create();
            pupil_addInfo(p,name,surname,birthday,sex,atoi(Class),atof(score),atoi(year),id);
            list_push_back(pupils,p);

            cJSON * pupil = pupil_pupilToJson(p);
            server_sendJson(client,pupil);
        }
        else{
            server_sendWrongInputData(client);
        }
}


int pupil_getMaxId(list_t * pupils){
    int maxId = -1;
    for(int i = 0; i < list_getSize(pupils); i ++){
        pupil_t * p = list_get(pupils,i);
        if(pupil_getId(p) > maxId){
            maxId = pupil_getId(p);
        }
    }
    return maxId;
}

void server_sendListAsHtml(socket_t * client,list_t * pupils){
    char html[5000]= "<html>"
                        "<head>"
                            "<title>My lab 4, my hell, my love</title>"
                                "<body>"
                                    "<ul>";
    for(int i=0; i< list_getSize(pupils); i++){
        char pupil[400];
        pupil_t * p = list_get(pupils,i);
        sprintf(pupil,"<li><a href= http://127.0.0.1:5000/pupils/%d>%s %s : id - %d</a></li>",pupil_getId(p),pupil_getName(p),pupil_getSurname(p),pupil_getId(p));
        strcat(html,pupil);
    }
    strcat(html,"</ul></body></head></html>");
    server_sendHtml(client,html);
}

void server_addPupilHtml(socket_t * client, list_t * pupils){
    char* buf = malloc(sizeof(char)*10000);
    FILE * f = fopen("page.html","r");
    int size = fread(buf,sizeof(char),10000,f);
    buf[size]='\0';
    server_sendHtml(client,buf);
    free(buf);
}

void server_wrongInputData_html(socket_t * client){
    char* buf = malloc(sizeof(char)*10000);
    FILE * f = fopen("error.html","r");
    int size = fread(buf,sizeof(char),10000,f);
    buf[size]='\0';
    server_sendHtml(client,buf);
    free(buf);
}

void server_wrongIndex_html(socket_t * client){
    char* buf = malloc(sizeof(char)*10000);
    FILE * f = fopen("index.html","r");
    int size = fread(buf,sizeof(char),10000,f);
    buf[size]='\0';
    server_sendHtml(client,buf);
    free(buf);
}

void server_deletePupil_html(socket_t * client,list_t * pupils, int id){
    if(pupil_deletePupilById(pupils,id) == 1){
        server_sendListAsHtml(client,pupils);
    }
    else server_wrongIndex_html(client);
}
void server_openPage(socket_t * client){
     char* buf = malloc(sizeof(char)*10000);
    FILE * f = fopen("first.html","r");
    fread(buf,sizeof(char),10000,f);
    server_sendHtml(client,buf);
    free(buf);
}
void server_newHtmlPupil(socket_t * client,list_t * pupils,char * buf){
     http_request_t req = http_request_parse(buf);
        int id = pupil_getMaxId(pupils) + 1;
        char * name = (char *)http_request_getArg(&req, "name");
        char * surname = (char *)http_request_getArg(&req, "surname");
        char * birthday = (char *)http_request_getArg(&req, "birthday");
        char * sex = (char *)http_request_getArg(&req,"sex");
        char * score = (char *)http_request_getArg(&req, "score");
        char * Class = (char *)http_request_getArg(&req, "class");
        char * year = (char *)http_request_getArg(&req,"year");

        if(checkInputData(name,surname,birthday,sex,Class,score,year) == 1){
            pupil_t * p = pupil_create();
            pupil_addInfo(p,name,surname,birthday,sex,atoi(Class),atof(score),atoi(year),id);
            list_push_back(pupils,p);

            server_sendHtml(client,pupil_getHtml(p,pupil_getId(p)));
        }
        else{
            server_wrongInputData_html(client);
        }
}











