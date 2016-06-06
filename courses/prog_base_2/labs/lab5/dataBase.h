#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "sqlite3.h"
#include "list.h"
#include "pupil.h"

typedef struct db_s db_t;

struct db_s{
    sqlite3 * db;
};

db_t * db_new(const char * dbFile);
void db_free(db_t * self);
void db_parse(db_t * self, list_t * list_of_pupils);
void pupil_getJSON(db_t * self, list_t * list_of_pupils);
int db_deletePupilById(db_t * self,list_t * pupils,int id);
int db_addPupil(db_t * db,list_t * pupils, char * buf);
pupil_t * db_getPupilById(db_t * db,int id);
cJSON * db_task(db_t * self,char * buf);
int db_getNewId(db_t* db);





#endif // DATABASE_H_INCLUDED
