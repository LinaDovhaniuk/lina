#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "sqlite3.h"


int main(void){
    sqlite3 * db;
    int rc = 0;
    rc = sqlite3_open("data_base.db", &db);

    if (SQLITE_OK != rc) {
        puts("Error open!");
        return(1);
    }

    printCoach(rc,db);
    printClients(rc,db);
    printClub(rc,db);
    printTraining(rc,db);
    sqlite3_close(db);
    return 0;
}

void printCoach(int rc,sqlite3 * db){
    printf("Coach\n\n");
    sqlite3_stmt * stmt;
    const char * sql = "SELECT * FROM Coach;";
    rc = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
    if (SQLITE_OK != rc) {
        puts("Error prepare!");
        return(1);
    }

    while (1) {
        rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            puts("Error step!");
            return(1);
        }
        else if (SQLITE_DONE == rc){
            break;
        }

        puts("");

    for(int i = 0; i < sqlite3_column_count(stmt); i++) {
            const char * colName = sqlite3_column_name(stmt, i);
            const unsigned char * text = sqlite3_column_text(stmt, i);
            printf("%10s : %s\n", colName, text);
        }
    }

    sqlite3_reset(stmt);

    sqlite3_finalize(stmt);
}

void printClients(int rc,sqlite3 * db){
    printf("Clients\n\n");
    sqlite3_stmt * stmt;
    const char * sql = "SELECT * FROM Client;";
    rc = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
    if (SQLITE_OK != rc) {
        puts("Error prepare!");
        return(1);
    }

    while (1) {
        rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            puts("Error step!");
            return(1);
        }
        else if (SQLITE_DONE == rc){
            break;
        }

        puts("");

    for(int i = 0; i < sqlite3_column_count(stmt); i++) {
            const char * colName = sqlite3_column_name(stmt, i);
            const unsigned char * text = sqlite3_column_text(stmt, i);
            printf("%10s : %s\n", colName, text);
        }
    }

    sqlite3_reset(stmt);

    sqlite3_finalize(stmt);
}

void printClub(int rc,sqlite3 * db){
    printf("Club\n\n");
    sqlite3_stmt * stmt;
    const char * sql = "SELECT * FROM Club;";
    rc = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
    if (SQLITE_OK != rc) {
        puts("Error prepare!");
        return(1);
    }

    while (1) {

        rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            puts("Error step!");
            return(1);
        }
        else if (SQLITE_DONE == rc){
            break;
        }

        puts("");

    for(int i = 0; i < sqlite3_column_count(stmt); i++) {
            const char * colName = sqlite3_column_name(stmt, i);
            const unsigned char * text = sqlite3_column_text(stmt, i);
            printf("%10s : %s\n", colName, text);
        }
    }

    sqlite3_reset(stmt);

    sqlite3_finalize(stmt);
}

void printTraining(int rc,sqlite3 * db){
    printf("Training\n\n");
    sqlite3_stmt * stmt;
    const char * sql = "SELECT * FROM Training;";
    rc = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
    if (SQLITE_OK != rc) {
        puts("Error prepare!");
        return(1);
    }

    while (1) {
        rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            puts("Error step!");
            return(1);
        }
        else if (SQLITE_DONE == rc){
            break;
        }

        puts("");

    for(int i = 0; i < sqlite3_column_count(stmt); i++) {
            const char * colName = sqlite3_column_name(stmt, i);
            const unsigned char * text = sqlite3_column_text(stmt, i);
            printf("%10s : %s\n", colName, text);
        }
    }

    sqlite3_reset(stmt);

    sqlite3_finalize(stmt);
}


void pos(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}


