#include "nlp.h"

int main(){
	FILE * input = file_open("input.txt", "r");

	char buff [5000];

	int count = fread(buff, sizeof(char),5000, input);
	buff[count] = '\0';

	text_t text = text_create(buff);
	text_separation(text);
	FILE * output = file_open("output.txt", "w");
	word_sortUnique(text,output);
	text_remove(text);
	file_close(input);
	file_close(output);
	return 0;
}