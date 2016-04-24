#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sqlite3.h"
#include "pupil.h"

struct db_s{
    sqlite3 * db;
};

struct pupil_s{
    int id;
    char name[256];
    char surname[256];
    double score;
    int Class;
    double growth;
};


db_t * db_new(const char * dbFile){
    db_t * self = malloc(sizeof(struct db_s));
    int rc = sqlite3_open(dbFile, & self->db);
    if (SQLITE_ERROR == rc){
        printf("can't open database\n");
        exit(1);
    }
    return self;
}

void db_free(db_t * self){
    sqlite3_close(self->db);
}

int pupil_insertPupil(db_t * self, pupil_t * pupil){
   int newStudentId = -1;
   sqlite3_stmt * stmt = NULL;
   int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Pupil (Id,Name,Surname,Score,Class,Growth) VALUES (?,?,?, ?,?, ?);", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    sqlite3_bind_int(stmt, 1,pupil->id);
    sqlite3_bind_text(stmt, 2,pupil->name,strlen(pupil->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,pupil->surname,strlen(pupil->surname),SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,4,pupil->score);
    sqlite3_bind_int(stmt, 5,pupil->Class);
    sqlite3_bind_double(stmt, 6,pupil->growth);


    if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not inserted! %i\n", rc);
    }
     int newPupilId = (int)sqlite3_last_insert_rowid (self->db);
     sqlite3_finalize(stmt);
    return newPupilId;
}

pupil_t * db_getPupilById(db_t * self, int id){
    pupil_t * pupil = malloc(sizeof(pupil_t*));
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT * FROM Pupil WHERE Id = ?;", -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
     while (1){
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc){
            printf("can't select students\n");
            exit(1);
        }
        else if (SQLITE_DONE == rc){
            sqlite3_finalize(stmt);
            return pupil;
}
        else
        {
            _fillPupils(stmt,pupil);
        }
    }
    sqlite3_finalize(stmt);
}



void db_updatePupil(db_t * self, pupil_t * pupil, int id){
    sqlite3_stmt * stmt = NULL;
    int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"UPDATE Pupil SET Id = ? Name = ?,Surname = ?,Score = ?, Class = ?, Growth = ? WHERE Id = ?;", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    sqlite3_bind_int(stmt, 1,pupil->id);
    sqlite3_bind_text(stmt, 2,pupil->name,strlen(pupil->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,pupil->surname,strlen(pupil->surname),SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,4,pupil->score);
    sqlite3_bind_int(stmt, 5,pupil->Class);
    sqlite3_bind_double(stmt, 6,pupil->growth);

     if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not updated! %i\n", rc);
    }
     sqlite3_finalize(stmt);
}

void db_deletePupil(db_t * self, int id){
    sqlite3_stmt * stmt = NULL;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db, "DELETE FROM Pupil WHERE Id = ?;", -1, &stmt, 0)){
        printf("Not prepared!\n");
    }
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    if (SQLITE_DONE != rc) {
        printf("Not deleted! %i\n", rc);
    }
    sqlite3_finalize(stmt);
}

int db_countPupils(db_t * self){
    int rc;
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM Pupil;", -1, &stmt, 0);
    rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc){
        printf("can't select count\n");
        exit(1);
    }
    int count = sqlite3_column_int(stmt,0);
    sqlite3_finalize(stmt);
    return count;
}

static void _fillPupils(sqlite3_stmt * stmt, pupil_t * pupil){
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    double score = sqlite3_column_double(stmt, 3);
    int Class = sqlite3_column_int(stmt, 4);
    double growth = sqlite3_column_double(stmt, 5);
    pupil->id = id;
    strcpy(pupil->name, (const char *)name);
    strcpy(pupil->surname, (const char *)surname);
    pupil->score = score;
    pupil->Class = Class;
    pupil->growth = growth;
}

int db_getPupilsTask(db_t * self, int K, int P){
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM Pupil WHERE Class = @P ORDER BY Score DESC LIMIT @K;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);

    int PIndex = sqlite3_bind_parameter_index(stmt, "@P");
    sqlite3_bind_int(stmt, PIndex, P);

    int KIndex = sqlite3_bind_parameter_index(stmt, "@K");
    sqlite3_bind_int(stmt, KIndex, K);


    int count = 0;
    while (1){
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc){
            printf("can't select students\n");

            exit(1);
        }
        else if (SQLITE_ROW == rc){
            int count = sqlite3_column_count(stmt);
            for (int i = 0; i < count; i++) {
                const char * colName = sqlite3_column_name(stmt, i);
                const char * value = sqlite3_column_text(stmt, i);
                printf("%10s : %s\n", colName, value);
            }
            printf("\n");

        }
        else if (SQLITE_DONE == rc){
            break;
        }
    }

    sqlite3_finalize(stmt);
    return count;
}

void pupil_print(pupil_t * pupil) {
    printf("Id: %i\nName: %s\nSurname: %s\nScore: %s\nClass: %s\nGrowth: %f\n\n",
        pupil->id,pupil->name, pupil->surname,pupil->score,pupil->Class, pupil->growth);
}

void pupil_printList(pupil_t * pupil, int len) {
    for (int i = 0; i < len; i++) {
        pupil_print(&pupil[i]);
    }
}
