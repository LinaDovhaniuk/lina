#include <math.h>
#include <stdio.h>

double calc(int n, int m);

int main(){

double x;
int  n1=0, i, j;
int n=2;
int m=5;
calc(n,m);


return 0;
}

double calc(int n, int m){
double x=0;
int  n1=0, i, j;

for (i=0; i< n; i++){
    for (j=1; j< m; j++){
 x+= pow(i,2)+ (n1 + 10)/j;
    }
}
printf("%.2f ", x);
}
