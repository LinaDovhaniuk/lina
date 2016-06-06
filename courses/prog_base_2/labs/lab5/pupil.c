#include "pupil.h"

struct pupil_s{
    int id;
    char name[256];
    char surname[256];
    int Class;
    double score;
    double growth;
};

pupil_t * pupil_create(void) {
    pupil_t * p = malloc(sizeof(struct pupil_s));
    return p;
}

void pupil_remove(pupil_t * self) {
    free(self);
}

void pupil_addInfo(pupil_t * self, int id,char * name,char * surname, int Class, double score, double growth) {
    self->id = id;
    strcpy(self->name, name);
    strcpy(self->surname, surname);
    self->Class = Class;
    self->score = score;
    self->growth = growth;
}

char * pupil_getHtml(pupil_t* self, int Id){
    char * buff = malloc(sizeof(char) * 10240);

    char text[1024] = "";
    sprintf(text,
            "<p>"
            "<a href ='/pupils'>Back to pupils</a><br>"
            "Id: %i<br>"
            "Name: %s<br>"
            "Surname: %s<br>"
            "Score: %.2f<br>"
            "Class: %i<br>"
            "Growth: %.2f<br>"
            "</p>",
            self->id,self->name, self->surname, self->score,
            self->Class, self->growth);
    strcat(buff, text);

    char * pageTextLink = "<a href=\"#\" onclick=\"doDelete()\"/>Delete pupil<br><br></a>\n";
    strcat(buff, pageTextLink);

    char pageTextScript[1024];
    sprintf(pageTextScript,
                "<script>"
                "function doDelete() {"
                "var xhttp = new XMLHttpRequest();"
                "xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/pupils/%i\", true);"
                "xhttp.send();"
                "}"
                "</script> ", Id);
    strcat(buff, pageTextScript);

    return buff;
}


cJSON * pupil_listToJson(list_t * pupils){
    cJSON * arr = cJSON_CreateArray();
    for(int i=0; i< list_getSize(pupils); i++){
        cJSON *jPupil = pupil_pupilToJson(list_get(pupils,i));
        cJSON_AddItemToArray(arr,jPupil);
    }
    return arr;
}

cJSON* pupil_pupilToJson(pupil_t * p){
    cJSON *pupil = cJSON_CreateObject();
    cJSON_AddItemToObject(pupil, "id", cJSON_CreateNumber(pupil_getId(p)));
    cJSON_AddItemToObject(pupil, "name", cJSON_CreateString(pupil_getName(p)));
    cJSON_AddItemToObject(pupil, "surname", cJSON_CreateString(pupil_getSurname(p)));
    cJSON_AddItemToObject(pupil, "score", cJSON_CreateNumber(pupil_getScore(p)));
    cJSON_AddItemToObject(pupil, "class", cJSON_CreateNumber(pupil_getClass(p)));
    cJSON_AddItemToObject(pupil, "growth", cJSON_CreateNumber(pupil_getGrowth(p)));
    return pupil;
}



char * pupil_getName(pupil_t * self){
    return self->name;
}

char * pupil_getSurname(pupil_t * self){
    return self->surname;
}
int pupil_getId(pupil_t * self){
    return self->id;
}

int pupil_getClass(pupil_t * self){
    return self->Class;
}

double pupil_getScore(pupil_t * self){
    return self->score;
}

double pupil_getGrowth(pupil_t * self){
    return self->growth;
}


