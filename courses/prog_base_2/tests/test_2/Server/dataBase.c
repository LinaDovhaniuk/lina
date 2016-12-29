#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#include "dataBase.h"
#include "pupil.h"
#include "cJSON.h"

struct db_s{
    sqlite3 * db;
};

db_t * db_new(const char * dbFile){
    db_t * self = malloc(sizeof(struct db_s));
    int rc = sqlite3_open(dbFile, & self->db);
    if (SQLITE_ERROR == rc){
        puts("Can't open database");
        exit(1);
    }
    return self;
}

void db_free(db_t * self){
    sqlite3_close(self->db);
    free(self);
}

void db_parse(db_t * self, list_t * list_of_pupils){
    const char * sqlQuery = "SELECT * FROM Pupil;";

    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);

    while (1){
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc){
            puts("Can't select!");
            exit(1);
        }
        else if (SQLITE_DONE == rc){
            break;
        }
        else if (SQLITE_ROW == rc){
            int id = sqlite3_column_int(stmt, 0);
            char * name = (char *)sqlite3_column_text(stmt, 1);
            char * surname = (char *)sqlite3_column_text(stmt, 2);
            int Class = sqlite3_column_int(stmt, 3);
            double score = sqlite3_column_double(stmt, 4);
            double growth = sqlite3_column_double(stmt, 5);

            pupil_t * p = pupil_create();
            pupil_addInfo(p, id, name, surname, Class, score,growth);
            list_add(list_of_pupils, p);
        }
    }

    sqlite3_finalize(stmt);
}



void pupil_getJSON(db_t * self, list_t * list_of_pupils){

    //cJSON * jStudent = cJSON_CreateObject();
    cJSON * jsonText =  cJSON_CreateArray();

    for (int i = 0; i < list_size(list_of_pupils); i++){
        cJSON *jPupil = cJSON_CreateObject();
            cJSON_AddItemToObject(jPupil, "name", cJSON_CreateString(pupil_getName(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "surname", cJSON_CreateString(pupil_getSurname(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "score", cJSON_CreateNumber(pupil_getScore(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "class", cJSON_CreateNumber(pupil_getClass(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "growth", cJSON_CreateNumber(pupil_getGrowth(list_get(list_of_pupils,i))));
        cJSON_AddItemToArray(jsonText,jPupil);
    }


}
