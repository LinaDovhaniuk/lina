#include <stdio.h>
#include <stdlib.h>

/*
‘ункц≤€ check приймаЇ масив ц≥лих чисел.
ƒл€ кожного елемента в≥дбуваЇтьс€ перев≥рка чи число б≥льше
K (K < N) - викликати callback-функц≥ю overCB, €ка приймаЇ
значен€ елемента ≥ рахуЇ к≥льк≥сть таких елемент≥в.
якщо згенероване число менше -K - викликати underCB,
€ка також приймаЇ значенн€ елемента ≥ рахуЇ к≥льк≥сть таких елемент≥в.

*/

typedef int(*callback)(int * ,int *);


void check(int * array, int K,int N, callback overCB,callback underCB){
    int countElemOver = 0;
    int countElemUnder = 0;
    for (int i = 0; i < N; i++){
        if (K < array[i]){
            overCB(array,&countElemOver);
        }
        else {
            if(array[i]< -K )
            underCB(array,&countElemUnder);
        }
    }
    printf("\n\nMore than K : %i\n",countElemOver);
    printf("Less than K : %i\n",countElemUnder);
}

void overCB1(int * array, int* countElemOver){
    (*countElemOver)++;
}
void underCB1(int * array, int* countElemUnder){
    (*countElemUnder)++;
}
void overCB2(int * array, int* countElemOver){
    (*countElemOver)++;
    printf("This element is more than K \n");
}
void underCB2(int * array, int* countElemUnder){
    (*countElemUnder)++;
    printf("This element is less than K\n");
}


int main(){
    int  array[] ={5,8,9,11,12,88,-55,7,66,1};
    int N = sizeof(array)/sizeof(int);
    printf("Array : \n");
    for(int i = 0; i < N; i++){
        printf("%i  ",array[i]);
    }
    check(array,9,N,overCB1,underCB1);
    puts("");
    check(array,9,N,overCB2,underCB2);
}
