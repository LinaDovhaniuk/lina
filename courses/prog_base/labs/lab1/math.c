
#include <math.h>

double calc(double(x) , double(y) , double(z)){
	double a;
	if (x != y && x != 0 && sin(y) != 0 && z != 0){
		a = pow(x, (y + 1)) / pow((x - y), 1 / z) + 6 * y + z / x + pow(x, 1 / fabs(sin(y)));
	}
	else {
		return NAN;
	}
	return a;
}
