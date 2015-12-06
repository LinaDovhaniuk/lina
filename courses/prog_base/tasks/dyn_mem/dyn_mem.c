#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char* in=(char*)malloc(1000*sizeof(char));
	char* tmp1 = (char*)malloc(3 * sizeof(char));
	gets(in);

	int *i = (int*)malloc(sizeof(int));
	*i = strlen(in) - 1;

	for (*i; (*i) >= 0; (*i)--){
		if (isxdigit(in[*i])){
			tmp1 = in[*i];
            printf("%c", tmp1);
			break;
		}
		else {
            printf("0");
            break;
		}
	}

	free(in);
	free(tmp1);
	free(i);
	getchar();
	return EXIT_SUCCESS;

}
