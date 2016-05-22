#include "nlp.h"
#include "list.h"

struct text_s{
	char * text;
	list_t * sentences;
};

struct sentence_s{
	char * sentence;
	list_t * words;
};

struct word_s{
	char * word;
};


text_t text_create(char * text){
	text_t txt = (text_t)malloc(sizeof(struct text_s));
	txt->text = malloc(sizeof(char)*(strlen(text) + 1));
	strcpy(txt->text, text);
	txt->sentences = list_new();
	return txt;
}
void text_remove(text_t self){
	free(self->text);
	for (int i = 0; i < list_getSize(self->sentences); i++){
		sentence_remove(list_get(self->sentences, i));
	}
	list_free(self->sentences);
	free(self);
}

sentence_t sentence_create(char * sentence){
	sentence_t sent = (sentence_t)malloc(sizeof(struct sentence_s));
	sent->sentence = malloc(sizeof(char)*(strlen(sentence) + 1));
	strcpy(sent->sentence, sentence);
	sent->words = list_new();
	return sent;
}
void sentence_remove(sentence_t self){
	free(self->sentence);
	for (int i = 0; i < list_getSize(self->words); i++){
		word_remove(list_get(self->words, i));
	}
	list_free(self->words);
	free(self);
}

word_t word_create(char * word){
	word_t w = (word_t)malloc(sizeof(struct word_s));
	w->word = malloc(sizeof(char)*(strlen(word) + 1));
	strcpy(w->word, word);
	return w;
}
void word_remove(word_t word){
	free(word->word);
	free(word);
}

FILE * file_open(char * title, char * mode){
	FILE * fp;
	fp = fopen(title, mode);
	if (fp == NULL) {
		return NULL;
	}
	return fp;
}

void  file_close(FILE * self){
	fclose(self);
}

void  text_separation(text_t self){
	char * copy = malloc(sizeof(char)*strlen(self->text) + sizeof(char));
	char * static_copy = copy;
	strcpy(copy, self->text);
	char * sentence = strtok(copy, "!.?");
	while (sentence != NULL){
		char sent[500]; 
		strcpy(sent, sentence);
		sentence_t s = sentence_create(sent);
		list_push_back(self->sentences, s);
		//sentence_separation(s);
		sentence = strtok(NULL, "!.?");
	}

	for (int i = 0; i < list_getSize(self->sentences); i++){
		sentence_separation((sentence_t)list_get(self->sentences, i));
	}

	free(static_copy);
}

void  sentence_separation(sentence_t self){
	char * copy = malloc(sizeof(char)*strlen(self->sentence) + sizeof(char));
	char* static_copy = copy;
	strcpy(copy, self->sentence);
	char * word = strtok(copy, " ,-:;");
	while (word != NULL){
		char wrd[300];
		strcpy(wrd, word);
		word_t wordNew = word_create(wrd);
		list_push_back(self->words, wordNew);
		word = strtok(NULL, " ,-:;");
	}
	free(static_copy);
}

int text_getNumOfWords(text_t self){
	int count = 0;
	for (int i = 0; i < list_getSize(self->sentences); i++){
		sentence_t tmp = list_get(self->sentences, i);
		count += list_getSize(tmp->words);
	}
	return count;
}

int compare(void * first, void *second){
	word_t word1 = *((word_t*)(first));
	word_t word2 = *((word_t*)(second));
	return strlen(word1->word) - strlen(word2->word);
}

void word_sortUnique(text_t self,FILE * file){
	word_t * words = malloc(sizeof(word_t)*text_getNumOfWords(self));
	int count = 0;
	for (int i = 0; i < list_getSize(self->sentences); i++){
		sentence_t tmp = list_get(self->sentences,i);
		for (int j = 0; j < list_getSize(tmp->words); j++){
			words[count++] = list_get(tmp->words, j);
		}
	}
	word_t * unique_words = malloc(sizeof(word_t)*count);
	int uniqueCount = 0;
	for (int i = 0; i < count; i++){
		int unique = 1;
		for (int j = 0; j < count; j++){
			if (i != j && (strcmp(words[i]->word,words[j]->word) == 0)){
				unique = 0;
			}
		}
		if (unique) unique_words[uniqueCount++] = words[i];
	}
	qsort(unique_words, uniqueCount, sizeof(word_t), compare);
	
	for (int i = 0; i < uniqueCount; i++){
		fprintf(file, "%s : %d\n", unique_words[i]->word, strlen(unique_words[i]->word));
	}
}






