#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void length(char *tmp, char * p1);
int main(){

    char * fileName = "input.txt";
    char * outPut = "output.txt";
    FILE * fp;
    char tmp ;
    int status = 0;
    int count = 1;
    char str[100];

    char *p1;
    char * p2;

    fp = fopen(fileName, "r");
    if (NULL == fp && status != 1) {
        puts("Error!");
        status = 1;
        return EXIT_FAILURE;
    }

    tmp = fgetc(fp);
    char tmp1 = tmp;
    while (EOF != tmp && status!=1) {
        printf("%c", tmp);
        tmp = fgetc(fp);

    }

fclose(fp);

length(str,p1);
printf("%s",p2);



fp = fopen("output.txt", "w");
    if (fp == NULL) {
        puts("Error opening output.txt!");
        return EXIT_FAILURE;
    }

    fprintf(fp, "%c", p2);

    fclose(fp);
    return 0;


}

void length(char *str, char * p1){
int len;
char * p2;
const char space[] = " ";
p1=strtok(str,space);
 while (p1!=NULL)
     {
      len=strlen(p1);

           p2=p1;
          }
      p1=strtok(NULL," ");

printf("%c", p2);
}


