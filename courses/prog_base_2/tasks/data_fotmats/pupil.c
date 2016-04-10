#include "pupil.h"

#define MAX_NUM_OF_PUPILS 3

struct pupils_s{
    int numOfPupils;
    pupil_t pupils[MAX_NUM_OF_PUPILS];
};

struct pupil_s{
    char * name;
    char * surname;
    char * birthdate;
    char * sex;
    char * Class;
    char * speciality;
    int year;
    double score;
    int number;
};

pupil_t pupil_create(void){
    pupil_t p = (pupil_t)malloc(sizeof(struct pupil_s));
    return p;
}

pupils_t pupils_create(void){
    pupils_t p = (pupils_t)malloc(sizeof(struct pupils_s));
    for(int i=0; i < MAX_NUM_OF_PUPILS; i++){
        p->pupils[i] = pupil_create();
    }
    p->numOfPupils = 0;
    return p;
}

void pupil_ParseFromFile(pupils_t self, char * fileName){
    char line[100];
    char text[1000] = "";
    FILE * f = fopen(fileName, "r");
    while(fgets(line,100,f)){
        strcat(text,line);
    }

    xmlDoc * xDoc;
    xDoc = xmlReadMemory(text,strlen(text), NULL ,NULL,0);
    if (xDoc == NULL){
        printf("Error parsing xml from memory");
        return 1;
    }

    xmlNode * xRootEl;
    xRootEl = xmlDocGetRootElement(xDoc);
    printf("\n");
    int i=0;
    for(xmlNode * xCur = xRootEl->children; NULL != xCur; xCur = xCur->next){
        if(XML_ELEMENT_NODE == xCur->type){
            printf("Tag name <%s>\n",xCur->name);

             for(xmlNode * xJ = xCur->children; NULL != xJ; xJ = xJ->next){
                if(XML_ELEMENT_NODE == xJ->type){
                        if(strcmp(xJ->name,"class")==0){
                            xmlNode * xGroup = xJ;
                            xmlNode *xFac = xGroup->children->next;
                            self->pupils[i]->name = xmlGetProp(xGroup,"name");
                            self->pupils[i]->Class = xmlNodeGetContent(xFac);
                            printf("\t%10s: %s %s\n", "class", self->pupils[i]->name, self->pupils[i]->Class);
                            continue;
                        }
                    const char * content = xmlNodeGetContent(xJ);
                    printf("\t%10s: %s\n",xJ->name, content);
                }
            }
        }
    }
    (self->numOfPupils)++;
}


void pupils_remove(pupils_t self){
    for(int i=0; i < self->numOfPupils; i++){
        free(self->pupils[i]);
    }
    free(self);
}
