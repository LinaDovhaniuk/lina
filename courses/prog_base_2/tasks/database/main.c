#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pupil.h"
#include <sqlite3.h>

int main(void) {
    const char * dbFile = "pupil.db";
    pupil_t * listOfPupil[100];
    db_t * db = db_new(dbFile);
    puts("Pupils from 11 class with max score : \n");
    int count = db_getPupilsTask(db,3,11);
    printf("Count of pupils in dataBase: %i",db_countPupils(db));

    getch();
    db_free(db);
    return 0;
}
