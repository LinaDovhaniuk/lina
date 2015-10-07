#include <math.h>

int exec(int, int, int);
int max(int a, int b);
int min(int a, int b);

int SizeOfData_Type(int data_type){
	switch (data_type){
	case 0: return sizeof(char);
	case 1: return sizeof(signed char);
	case 2: return sizeof(short);
	case 3: return sizeof(unsigned int);
	case 4: return sizeof(long);
	case 5: return sizeof(unsigned long long);
	case 6: return sizeof(float);
	case 7: return sizeof(double);
	default: return 0;
		}
}

int max(int a, int b) {
    return b > a ? b : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int exec(int op, int a, int b) {
	int result;
	switch (op){
	case 0: return -a;
	case 1: return a + b;
	case 2: return a - b;
	case 3: return a*b;
	case 4: return a / b;
	case 5: return abs(a);
	case 6: return pow(a, b);
	case 7:
	case 13:
	case 77: return a%b;
	case 8: return max(a, b);
	case 9: return min(a, b);
	case 10: return abs(a) * SizeOfData_Type(abs(b)%8);
	case 11: return floor(pow(a, 6 + b) / (0 + M_PI));
	default: if (op < 100){
				 return (op % abs(a + 1)) + (op % abs(b + 1));
	}
			 else if (op >= 100)
				 return -1;

	}
	return result;
}
