#include <stdio.h>

//1!*2!*...
int main(){
int j, factNum, resultNum, endNum;
scanf("%i", &endNum);


for (i=1; i<endNum; i++){
    factNum *=i;
    resultNum *= fractNum;
}
printf("result is : %i", resultNum);
return 0;
}
//#include <stdlib.h>
//#include <math.h>


/*int max(int array[], int length){
    int k=0;
    int maximum = array [k];
    for (k=0; k < length -1; k++){
        if (array[k+1] > maximum){
            maximum = array [k+1];
        }
    }
return (maximum);
}

int main(){
    int array[5] = {56, 4, 39, 122, -11} ;
    int result = max(array,5);
    printf("Result = %i", result);

}
/*
int is_prime(long long num){
int i;
int is_simple = 1;
for (i=2; i<= sqrt(num); i++){
    if(num%i ==0){
    is_simple =0;
        break;
    }
}
return(is_simple);
}
int main(){
 long long N;
 scanf("lld", &N);

 int i;
  for(i =2; i<N; i++){
    if (is_prime(i) == 1){
        printf("%lld\n", i);
    }
  }
return 0;
}*/
