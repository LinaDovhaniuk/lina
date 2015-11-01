#include <stdlib.h>
#include <stdio.h>

char * process(char * resultStr, const char * textLines[],
               int linesNum, const char * extraStr);

int main(void) {
    char result[100];
    const char *text[] = {
        "This text",
        "is already",
        "divided into",
        "lines."
    };
    int linesNum = sizeof(text) / sizeof(text[0]);
    char extra[100] = "otni";
    char * res = process(result, text, linesNum, extra);
    puts("=== Result ===");
    puts(res);
}

char * process(char * resultStr, const char * textLines[],
               int linesNum, const char * extraStr){
    int sizeOfExtraStr = sizeof (extraStr);
    int resultIndex = 0;
    char inversedString[100] = "";

    for (int i = 0; i < sizeOfExtraStr; i++){
        inversedString[i] = extraStr[sizeOfExtraStr - i];
    }

    for (int i = 0; i < linesNum; i++){
        for (int j = 0; j < sizeof(textLines[i]); j++){
            if (textLines[i][j] == extraStr[0]){
                int isEqual = 1;
                for (int k = 1; k < sizeof(extraStr); k++){
                    if (textLines[i][j+k] != extraStr[k]){
                        isEqual = 0;
                        break;
                    }
                }
                if (isEqual == 1){
                    resultIndex = i;
                    break;
                }
            }
        }
    }

    char result[100] = "";

    for (int m = 0; m < sizeof(inversedString); m++){
        result[m] = inversedString[m];
    }

    result[sizeof(inversedString) + 1] = ' ';
    result[sizeof(inversedString) + 2] = resultIndex;

    return result;

}
