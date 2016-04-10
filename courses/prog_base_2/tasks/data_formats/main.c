#include "pupil.h"

/*void print_element_names(xmlNode * a_node){
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("node type: Element, name: %s\n", cur_node->name);
        }

        print_element_names(cur_node->children);
    }
}*/

// gcc main.c -I include -L  lib -llibxml2
int main() {
    pupils_t p = pupils_create();

    pupil_ParseFromFile(p,"pupil.xml");
    /*char line[100];
    char text[1000] = "";
    FILE * fr = fopen("pupil.xml", "r");
    while(fgets(line,100,fr)){
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
    for(xmlNode * xCur = xRootEl->children; NULL != xCur; xCur = xCur->next){
        if(XML_ELEMENT_NODE == xCur->type){
            printf("Tag name <%s>\n",xCur->name);

             for(xmlNode * xJ = xCur->children; NULL != xJ; xJ = xJ->next){
                if(XML_ELEMENT_NODE == xJ->type){
                        if(strcmp(xJ->name,"class")==0){
                            xmlNode * xGroup = xJ;
                            xmlNode *xFac = xGroup->children->next;
                            char * name = xmlGetProp(xGroup,"name");
                            char * fac = xmlNodeGetContent(xFac);
                            printf("\t%10s: %s %s\n", "class", name, fac);
                            continue;
                        }
                    const char * content = xmlNodeGetContent(xJ);
                    printf("\t%10s: %s\n",xJ->name, content);
                }
            }
        }
    }*/



    return 0;
}

