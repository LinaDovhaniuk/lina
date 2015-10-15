#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    long long a;
    short i, sing;
    double mantissa, value, result;
    int exponent;

double long2double(long long);
scanf("%lld ", &a);
    if ( (a>>63) == 0){
        exponent = (a >> 52);
        sing = 0;
        }
    else {
        exponent = abs ((a >> 52) +1);
        sing = 1;
    }

for (i=51; i>=0; --i){
    mantissa = mantissa + ((a>>i)&1)* pow(2, i-52);
}
    if (exponent==2047 && mantissa!=0){
        value = NAN;
        printf("%d" , value);
    }
    if (exponent==2047 && mantissa==0 && sing ==1){
        printf("-Infinity");
    }
    if (exponent==2047 && mantissa==0 && sing ==0){
        printf("Infinity");
        }
    if (0<exponent &&  exponent<2047){
        value =pow((-1),sing) * pow(2,(exponent -1023)) * (mantissa+1);
         printf("%.325lf" , value);
    }
    if (exponent==0 && mantissa !=0){
        value=pow((-1),sing) * pow(2 , (-1022)) * (mantissa);
        printf("%.325lf" , value);
    }
    if (exponent==0 && mantissa==0 && sing ==1){
        value = -0;
        printf("%lf" , value);
    }
    if (exponent==0 && mantissa==0 && sing ==0){
        value = 0;
        printf("%lf" , value);
    }
  }

