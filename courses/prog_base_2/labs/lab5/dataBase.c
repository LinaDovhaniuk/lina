#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#include "dataBase.h"
#include "pupil.h"
#include "cJSON.h"
#include "sqlite3.h"



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
            list_push_back(list_of_pupils, p);
        }
    }

    sqlite3_finalize(stmt);
}

void pupil_getJSON(db_t * self, list_t * list_of_pupils){
    cJSON * jsonText =  cJSON_CreateArray();

    for (int i = 0; i < list_getSize(list_of_pupils); i++){
        cJSON *jPupil = cJSON_CreateObject();
            cJSON_AddItemToObject(jPupil, "id", cJSON_CreateNumber(pupil_getId(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "name", cJSON_CreateString(pupil_getName(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "surname", cJSON_CreateString(pupil_getSurname(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "score", cJSON_CreateNumber(pupil_getScore(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "class", cJSON_CreateNumber(pupil_getClass(list_get(list_of_pupils,i))));
            cJSON_AddItemToObject(jPupil, "growth", cJSON_CreateNumber(pupil_getGrowth(list_get(list_of_pupils,i))));
        cJSON_AddItemToArray(jsonText,jPupil);
    }
}

int db_deletePupilById(db_t * self,list_t * pupils,int id){
    const char * sqlQuery = "DELETE FROM Pupil WHERE Id = @id;";

    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);

    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc){
        return 0;
    }
    list_free(pupils);
    pupils = list_new();
    db_parse(self,pupils);
    sqlite3_finalize(stmt);
    return 1;
}

int db_addPupil(db_t * self,list_t * pupils, char * buf){
    const char * sqlQuery = "INSERT INTO Pupil (Name,Surname,Score,Class,Growth) VALUES (@name,@surname,@score,@Class,@growth);";
    int last = -1;
    int rc;
    sqlite3_stmt * stmt = NULL;
    rc = sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);
    printf("\nReturn cod: %i\n", rc);
    http_request_t req = http_request_parse(buf);
        char * name = (char *)http_request_getArg(&req, "name");
        char * surname = (char *)http_request_getArg(&req, "surname");
        char * score = (char *)http_request_getArg(&req, "score");
        char * Class = (char *)http_request_getArg(&req, "class");
        char * growth = (char *)http_request_getArg(&req,"growth");

    rc =  sqlite3_bind_text(stmt,1,name,strlen(name), NULL);
    printf("\nReturn cod: %i\n", rc);
    sqlite3_bind_text(stmt,2,surname,strlen(surname),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,3,score,strlen(score),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,4,Class,strlen(Class),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,5,growth,strlen(growth),SQLITE_TRANSIENT);

    rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc){
        return 0;
    }
    else if (SQLITE_MISMATCH == rc){
       return -1;
    }

    last = (int)sqlite3_last_insert_rowid (self->db);
    sqlite3_finalize(stmt);
    return last;
}

pupil_t * db_getPupilById(db_t * self,int id){
    const char * sqlQuery = "SELECT * FROM Pupil WHERE Id = ?";
    pupil_t * p = pupil_create();
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);

   int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc){
            puts("Can't select!");
            return NULL;
        }
        else if (SQLITE_ROW == rc){
            int id = sqlite3_column_int(stmt, 0);
            char * name = (char *)sqlite3_column_text(stmt, 1);
            char * surname = (char *)sqlite3_column_text(stmt, 2);
            int Class = sqlite3_column_int(stmt, 3);
            double score = sqlite3_column_double(stmt, 4);
            double growth = sqlite3_column_double(stmt, 5);

            pupil_addInfo(p, id, name, surname, Class, score,growth);

        }
    sqlite3_finalize(stmt);
    return p;
}

cJSON * db_task(db_t * self,char * buf){
    cJSON * arr = cJSON_CreateArray();
    const char * sqlQuery = "SELECT * FROM  Pupil WHERE Class = @class ORDER BY Score DESC LIMIT @lim;";
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);

    http_request_t req = http_get_request_parse(buf);
        char * Class = (char *)http_request_getArg(&req, "class");
        char * limit = (char *)http_request_getArg(&req, "lim");
    sqlite3_bind_text(stmt,1,Class,strlen(Class),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,2,limit,strlen(limit),SQLITE_TRANSIENT);

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
            cJSON_AddItemToArray(arr,pupil_pupilToJson(p));
        }
    }
    sqlite3_finalize(stmt);
    return arr;
}

int db_getNewId(db_t* db){
    const char * sqlQuery = "SELECT seq FROM sqlite_sequence WHERE name = \"Pupil\"";
    int res = 0;
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(db, sqlQuery, strlen(sqlQuery), &stmt, NULL);


   int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc){
            puts("Can't select!");
            return -1;
        }
        else if (SQLITE_ROW == rc){
            res = sqlite3_column_int(stmt, 0);

        }
    return res;
}


