#include <stdio.h>
#include <stdlib.h>

int main(){
   /* int n = 0;
    int i;
    int a,b,c;
    for (i=103; i<987; i++){
        c = i%10;
        b = (i/10)%10;
        a = i/100;
    if( a!=b && a!=c && b!=c){
        n++;}
    }
    printf("%i", n);
    */

/*int n, i, a;
scanf("%i", &n);
int x[n];

for (i=0; i<n; i+=1){
    scanf("%i", &x[i]);
    }

for (i = n-1; i >=0; i--){
    printf("%i, ", x[i]);
    }

*/

int sum=0, i;
int x[6]= {1, -2, 3, -5, -4, -5};
    for (i = 0; i<7; i++){
        /*if (i%2 == 0){
            sum +=x[i];*/
        x[i] = abs((x[i])*10);
        printf("%i ", x[i]);
        }
    }
/*printf("%i", sum);*/
