#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void fprocess(const char * pread, const char * pwrite){
    FILE *fpwrite;
    FILE *fpread;

    char sep[]={' ', ',','.','!'};
    char *istr;
    char mystring[800];
    int res=0;

    fpread = fopen(pread, "r");
    fpwrite = fopen(pwrite, "w");

    for (int i = 0; i<=5; i++){
        fgets(mystring, 800, fpread);
    }

    printf("The initial string : %s\n\n", mystring);
    fprintf(fpwrite, "The initial string : %s\n\n", mystring);

    istr = strtok (mystring,sep);

    while(NULL != istr){
        printf("%s\n",istr);
        fprintf(fpwrite,"%s\n",istr);
    // Выделение очередной части строки
        istr = (NULL, sep);
    }

    res += strlen(istr);
    printf("The length of the string is %s",res);
    fprintf(fpwrite,"The length of the string is %s",res);

    fclose(fpwrite);
    fclose(fpread);

}

