#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "sqlite3.h"
#include "list.h"
#include "pupil.h"

typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);

void db_parse(db_t * self, list_t * list_of_pupils);




#endif // DATABASE_H_INCLUDED
