#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include <jansson.h>
#include "CURL\include\curl\curl.h"

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
	strcpy((char*)stream, (char*)ptr);
	return size*count;
}


int mainRemove2(void){
	/*json_t* test = json_pack("{s:s}", "LINA", "SDAST");
	puts(json_dumps(test, JSON_INDENT(3)));*/
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	char resString[5000];

	char* resuestFields = "result=4";

	curl_easy_setopt(curl, CURLOPT_URL, "http://prog-base.appspot.com/");//GET
	//curl_easy_setopt(curl, CURLOPT_URL, "http://pb-homework.appspot.com/var/2");//POST
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, resuestFields);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resString);

	res = curl_easy_perform(curl);

	if (res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
		curl_easy_strerror(res));

	puts(resString);
	curl_easy_cleanup(curl);

	curl_global_cleanup();



	getchar();
}