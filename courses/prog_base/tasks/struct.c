#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



struct Photos{
    char name[30];
    time_t datePh;
    int sizePh;

};

void count(int size, struct Photos ph[]){
    //t = 1449394733 06.12.15
    time_t start,end;
    int count = 1;
    int* resindecies = (int*)malloc(size*sizeof(time_t));
    int arrIndex = 0;
    end = time(NULL);
    int i;
    int result;
    for (i = 1; i < size; i++){
        result = difftime(end, ph[i].datePh);
        if (result < (end - 2629743) ){
            count++;
            resindecies[arrIndex] = i;
            arrIndex++;
        }
    }
}

void change(struct Photos *ph, const char* newValue){
    strcpy(ph->name, newValue);
}

void print(int size, struct Photos* ph){
   /* time_t t1 = 1449049133 ;//02.12.15
       time_t t2 = 1446457133;//02.11.15
        time_t t3 = 1448703533;//28.11.15
        time_t t4 = 1448185133;//22.11.15
        time_t t5 = 1449308333;//05.12.15
*/

    int i;

    for (i = 0; i < 5; i++){
        printf("%d. %s\n", i + 1, ph[i].name);
        printf("Date : %s", ctime(&(ph[i].datePh)));
        printf("  Memory allocated to this photo  : %d mb\n", ph[i].sizePh);
    }
}

int main(void){
    struct Photos test;
    struct Photos ph[5] = {"Travel",1449049133,5, "Family",1446457133, 7, "Friends",1448703533, 9, "NewYear",1448185133, 8,  "School",1449308333, 6};
    int size = sizeof(ph) / (sizeof(test));

    char newName[30];
	int indexCh = 1, result = 0;
	print(size, ph);
	count(size, ph);
	puts("");
	do {
		fflush(stdin);
		printf("Type the number of the photo and it's new name :\n");
		result = scanf("%d %s", &indexCh, newName);
		if (result < 2 || indexCh <= 0 || indexCh > 5) puts("Try again ");
	} while (result < 2 || indexCh <= 0 || indexCh > 5);

	change(&(ph[indexCh-1]), newName);
	print(size, ph);
	getchar();
	getchar();
	return EXIT_SUCCESS;
}
