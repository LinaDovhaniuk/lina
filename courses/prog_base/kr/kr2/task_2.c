#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct dragon{
    char name[100];
    int sizeDr;
    int age;
};
struct Film{
    char fm[100];
   // struct dragon d;
    int date;
};

void count(int size, struct Film f[]){
    //t = 1449394733 06.12.15
    time_t end;
    int count = 1;
    end = time(NULL);
    int i;
    int result;
    for (i = 0; i < 3; i++){
        printf("%d. %s\n", i+1, f[i].fm);
        printf("Date of release %d \n", f[i].date);
        result = difftime(end, f[i].date);
        if (result < (end - 818763558) ){
            count++;
        }
    }
	printf("The number of films (<1995)%i", count);
}

void print (int size,struct dragon * dr ){
    int i;

    for (i = 0; i < 3; i++){

        printf("%d. %s\n", i + 1, dr[i].name);
        printf("Size : %i", dr[i].sizeDr);
        printf("  Age  : %d \n", dr[i].age);

    }
}

void pr(int size,struct dragon * dr, struct Film *f ){
    int i;
    time_t end = time(NULL);
    for (i = 0; i < 3; i++){
        if (dr[i].sizeDr>20 && f[i].date < (end - 818763558)){
        printf("%d. %s\n", i + 1, dr[i].name);
        printf("Size : %i", dr[i].sizeDr);
        printf("  Age  : %d \n", dr[i].age);
        }
    }
}

int main(){
    printf("Actors :\n");
    struct dragon test;
    struct dragon dr[3] = {"First", 15,150,"Second", 30, 200,"Third", 40, 170};
    int size = sizeof(dr) / (sizeof(test));

    print(size, dr);

    printf("\nThe correct actors :\n");
    struct Film  f[3] = {"Dragons", 2010,"Arrr", 2000, "Blabla", 1900};
    pr(size,dr,f);

    printf("\nFilms :\n");
    //struct Film  f[3] = {"Dragons", 2010,"Arrr", 2000, "Blabla", 1900};
    count(size,f);


}
