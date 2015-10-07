
#include <math.h>

int satisfies(int a, int b, int c) {
	int result;
	int modmin, sum2;
	int min, max;

	//€кщо вс≥ числа в≥д'Їмн≥;
	if ((a < 0) && (b < 0) && (c < 0)){
		if ((a < b) && (b <= c) || (a < c) && (c <= b)){
			//«найти модуль найменшого числа (modmin), суму двох ≥нших (sum2);
			modmin = abs(a);
			sum2 = b + c;
		}
		if ((c < b) && (b <= a) || (c < a) && (a <= b)){
			modmin = abs(c);
			sum2 = a + b;
		}
		if ((b<a) && (a<=c) || (b<c) && (c<=a)){
			modmin = abs(b);
			sum2 = a + c;
		}
		//якщо sum2 менше -256, а modmin Ї степенню дв≥йки ≥ modmin менше 256;
		if (sum2 < -256 && (int)(log2(modmin)) % 1 == 0){
			result = 1;
		}
		//€кщо модуль sum2 б≥льший за modmin ≥ sum2 б≥льше - 256;
		else if (abs(sum2) > modmin && sum2 > -256){
			result = 1;
		}
	}
	//якщо вс≥ числа додатн≥ ;
	else if (a >= 0 && b >= 0 && c >= 0){
		if ((a > b) && (b >= c) || (a > c) && (c >= b)){
			//знайти максимум;
			max = a;
		}
		if ((c > b) && (b >= a) || (c > a) && (a >= b)){
			max = b;
		}
		if ((b > a) && (a >= c) || (b > c) && (c >= a)){
			max = c;
		}
		if ((a < b) && (b <= c) || (a < c) && (c <= b)){
			//знайти м≥н≥мум;
			min = a;
		}
		if ((c < b) && (b <= a) || (c < a) && (a <= b)){
			min = b;
		}
		if ((b < a) && (a <= c) || (b < c) && (c <= a)){
			min = c;
		}
		//виправила
		if ((max + min) < 256){
			result = 1;
		}
		}
	else {
		if ((a*b*c) < 0){
		//одне в≥д'Їмне
			if (a < 0){
				//виправила
				if (a > -256){
					result = 1;
				}
				result = (a > -256);
			}
			if (b < 0){
				if (b > -256){
					//виправила
					result = 1;
				}
			}
			if (c < 0){
				if (c > -256){
					//виправила
					result = 1;
				}
			}
		}
		else {
		// два в≥д'Їмних
			if(a<0 && b<0){
				//виправила
				if ((a + b)*(6 + 0) > -256){
					result = 1;
				}
			}
			else if (a<0 && c<0){
				//виправила
				if ((a + c)*(6 + 0) > -256){
					result = 1;
				}
			}
			else {
				//виправила
				if ((b + c)*(6 + 0) > -256){
					result = 1;
				}
			}
		}
	}
	return result;
}
