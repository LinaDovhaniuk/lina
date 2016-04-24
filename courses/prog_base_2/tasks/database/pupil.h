#ifndef PUPIL_H_INCLUDED
#define PUPIL_H_INCLUDED
#include <sqlite3.h>

typedef struct pupil_s pupil_t;

typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);

int pupil_insertPupil(db_t * self, pupil_t * pupil);
pupil_t * db_getPupilById(db_t * self, int id);
void db_updatePupil(db_t * self, pupil_t * pupil, int id);
void db_deletePupil(db_t * self, int id);

int db_countPupils(db_t * self);

int db_getPupilsTask(db_t * self, int K, int P);
static void _fillPupils(sqlite3_stmt * stmt, pupil_t * pupil);

void pupil_print(pupil_t * pupil);
void pupil_printList(pupil_t * pupil, int len);

#endif // PUPIL_H_INCLUDED
