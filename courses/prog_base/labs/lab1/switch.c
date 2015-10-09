#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int opval = 1, aval = 5, bval = 4;
    int resultVal;

    resultVal = exec(opval, aval, bval);

    printf("%i", resultVal);
    return 0;
}

int exec(int op, int a, int b) {
    if (op<0)
    {
     op*=-1;
     int c=a;
     a=b;
     b=c;
    }
	int result;
	switch (op){
	case 0: result = -a;break;
	case 1: result = a + b;break;
	case 2: result = a - b;break;
	case 3: result = a*b;break;
	case 4: if (b!=0){
	    result = a / b;
	} else {
	     return 0;}break;
	case 5: result =  abs(a);break;
	case 6: result =  pow(a, b);break;
	case 7:
	case 13:
	case 77: if (b!=0){
	    result =  a%b;
	} else {
        return  0;
	}break;
	case 8: result =  (b > a) ? b : a;break;
	case 9: result =  (a < b) ? a : b;break;
	case 10:
	    switch(abs(b)%8){
            case 0: result = abs(a)* sizeof(char);
            case 1: result = abs(a)*  sizeof(signed char);
            case 2: result = abs(a)*  sizeof(short);
            case 3: result = abs(a)* sizeof(unsigned int);
            case 4: result = abs(a)* sizeof(long);
            case 5: result = abs(a)* sizeof(unsigned long long);
            case 6: result = abs(a)* sizeof(float);
            case 7: result = abs(a)* sizeof(double);
            } break;
	case 11: result =  floor(pow(a, 6 + b) / (0 + M_PI));break;
	default: if (op < 100){
				 result =  (op % abs(a + 1)) + (op % abs(b + 1));
	}
			 else if (op >= 100)
				 result = -1;

	}
	return result;
}
