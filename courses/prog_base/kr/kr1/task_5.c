#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    int N;
    srand(time(NULL));
    scanf("%d", &N);

    int arr[N];
    for (int i=0; i < N; i++){
     arr[i]=(rand())%100;
     printf("%i ", arr[i]);
    }
    printf("\n");
    int sum;
    for (int i = 1; i < N; i++){
      sum  = arr[i] + arr[i-1];
      printf("%i ", sum);
    }
}
