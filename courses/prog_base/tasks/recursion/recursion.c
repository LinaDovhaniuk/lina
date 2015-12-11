#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int Xdigit(char c){
    if(isxdigit(c))
        return 1;
    else
        return 0;
}
int num(char * str, size_t length){
    if(length==0)
        return 0;
    else
        return Xdigit(*str) + num(str + 1, length - 1);
}
int main(void){
    char str[100];
    puts("Please enter the string : ");
    fgets(str, 100, stdin);
    printf("The number of elements %i ", num(str, strlen(str)));
    return EXIT_SUCCESS;
}
