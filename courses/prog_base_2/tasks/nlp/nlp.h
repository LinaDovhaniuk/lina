#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define MAX_NUM_OF_SENTENCES 100
#define MAX_NUM_OF_WORDS 10000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct text_s * text_t;
typedef struct sentence_s * sentence_t;
typedef struct word_s * word_t;
typedef struct word_unique_s * word_unique_t;

text_t text_create(char * text);
void text_remove(text_t self);

sentence_t sentence_create(char * sentence);
void sentence_remove(sentence_t self);

word_t word_create(char * word);
void word_remove(word_t word);

FILE * file_open(char * title, char * mode);
void  file_close(FILE * self);

void  text_separation(text_t self);
void  sentence_separation(sentence_t self);
int text_getNumOfWords(text_t self);
int compare(const void * first, const void *second);
void word_sortUnique(text_t self, FILE * file);

