#include "pupil.h"

struct pupil_s{
    char name[50];
    char surname[50];
    char sex[20];
    int year;
    char birthday[20];
    double score;
    int Class;
    int id;
};

pupil_t * pupil_create(void) {

    return malloc(sizeof(struct pupil_s));
}

void pupil_remove(pupil_t * self) {
    free(self);
}



void pupil_addInfo(pupil_t * self,char * name,char * surname, char * birthday,char * sex, int Class, double score,int year,int id) {
    strcpy(self->name, name);
    strcpy(self->surname, surname);
    strcpy(self->birthday,birthday);
    strcpy(self->sex,sex);
    self->Class = Class;
    self->score = score;
    self->year = year;
    self->id = id;
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
            "Birthday: %s<br>"
            "Sex: %s<br>"
            "Year: %i<br>"
            "Class: %i<br>"
            "Score: %.1f"
            "</p>",
            self->id,self->name, self->surname, self->birthday,
            self->sex, self->year, self->Class,self->score);
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
char * pupil_getJSON(pupil_t * self){
    cJSON * pupil = cJSON_CreateObject();
    cJSON_AddItemToObject(pupil, "id", cJSON_CreateString(self->id));
    cJSON_AddItemToObject(pupil, "name", cJSON_CreateString(self->name));
    cJSON_AddItemToObject(pupil, "surname", cJSON_CreateString(self->surname));
    cJSON_AddItemToObject(pupil, "birthday", cJSON_CreateString(self->birthday));
    cJSON_AddItemToObject(pupil, "sex", cJSON_CreateString(self->sex));
    cJSON_AddItemToObject(pupil, "year", cJSON_CreateNumber(self->year));
    cJSON_AddItemToObject(pupil, "score", cJSON_CreateNumber(self->score));
    cJSON_AddItemToObject(pupil, "class", cJSON_CreateNumber(self->Class));
    char * jPupil = cJSON_Print(pupil);
    return jPupil;
}

void pupil_createPupilsList(list_t * self, cJSON * pupils){
    for(int i = 0;  i < cJSON_GetArraySize(pupils); i++){
        cJSON* pupil = cJSON_GetArrayItem(pupils,i);
        cJSON * id = cJSON_GetObjectItem(pupil,"id");
        cJSON * name = cJSON_GetObjectItem(pupil,"name");
        cJSON * surname = cJSON_GetObjectItem(pupil,"surname");
        cJSON * birthday = cJSON_GetObjectItem(pupil,"birthday");
        cJSON * sex = cJSON_GetObjectItem(pupil,"sex");
        cJSON * year = cJSON_GetObjectItem(pupil,"year");
        cJSON * score = cJSON_GetObjectItem(pupil,"score");
        cJSON * Class = cJSON_GetObjectItem(pupil,"class");
        pupil_t * p = pupil_create();
        pupil_addInfo(p,
                      name->valuestring,
                      surname->valuestring,
                      birthday->valuestring,
                      sex->valuestring,
                      year->valueint,
                      score->valuedouble,
                      Class->valueint,
                      id->valueint);
    list_push_back(self,p);
    }
}

cJSON * pupil_listToJson(list_t * pupils){
    cJSON * arr = cJSON_CreateArray();
    for(int i=0; i< list_getSize(pupils); i++){
        cJSON *jPupil = pupil_pupilToJson(list_get(pupils,i));
        cJSON_AddItemToArray(arr,jPupil);
    }
    return arr;
}

cJSON* pupil_pupilToJson(pupil_t * pupil){
     cJSON *jPupil = cJSON_CreateObject();
            cJSON_AddItemToObject(jPupil,"id",cJSON_CreateNumber(pupil_getId(pupil)));
            cJSON_AddItemToObject(jPupil, "name", cJSON_CreateString(pupil_getName(pupil)));
            cJSON_AddItemToObject(jPupil, "surname", cJSON_CreateString(pupil_getSurname(pupil)));
            cJSON_AddItemToObject(jPupil, "birthday", cJSON_CreateString(pupil_getBirthday(pupil)));
            cJSON_AddItemToObject(jPupil, "sex", cJSON_CreateString(pupil_getSex(pupil)));
            cJSON_AddItemToObject(jPupil, "score", cJSON_CreateNumber(pupil_getScore(pupil)));
            cJSON_AddItemToObject(jPupil, "class", cJSON_CreateNumber(pupil_getClass(pupil)));
            cJSON_AddItemToObject(jPupil,"year", cJSON_CreateNumber(pupil_getYear(pupil)));
        return jPupil;
}


int checkInputData(char * name, char * surname, char * birthday,char * sex, char * Class, char * score, char * year){
    int ibuf;
    char st_data[25];
    strcpy(st_data,birthday);
    char * str;
    str = strtok(st_data,"-");
    if (strlen(str) != 4 || atoi(str) < 1 || atoi(str) > 2016 ) return 0;
    str = strtok(NULL,"-");
    if (strlen(str) != 2 || atoi(str) < 1 || atoi(str) > 12) return 0;
    str = strtok(NULL,"\0");
    if (strlen(str) != 2 || atoi(str) < 1 || atoi(str) > 31 ) return 0;

   // for (int i = 0; i < strlen(birthday); i++){
     //   if (!(isalnum(i) || birthday[i] == '-')) return 0;
    //}

    if(!sscanf(Class,"%i",&ibuf)) return 0;
    if(!sscanf(year,"%i",&ibuf)) return 0;
    if(!sscanf(score,"%f",&ibuf)) return 0;
    if(strlen(name)>20 || strlen(surname)>20 || strlen(sex) > 8 ) return 0;

    return 1;
}

int pupil_deletePupilById(list_t * pupils,int id){
    for(int i=0; i < list_getSize(pupils);i++){
        pupil_t * p = list_get(pupils,i);
        if(pupil_getId(p) == id){
            list_remove(pupils,i);
            return 1;
        }
    }
    return 0;
}

char * pupil_getName(pupil_t * self){
    return self->name;
}

char * pupil_getSurname(pupil_t * self){
    return self->surname;
}


int pupil_getClass(pupil_t * self){
    return self->Class;
}

double pupil_getScore(pupil_t * self){
    return self->score;
}

char * pupil_getSex(pupil_t * self){
    return self->sex;
}
char * pupil_getBirthday(pupil_t * self){
    return self->birthday;
}
int pupil_getYear(pupil_t * self){
    return self->year;
}
int pupil_getId(pupil_t * self){
    return self->id;
}

