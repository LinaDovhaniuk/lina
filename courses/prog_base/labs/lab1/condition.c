
#include <math.h>

int satisfies(int a, int b, int c) {
	int result;
	int modmin, sum2;
	int min, max;

	//���� �� ����� ��'���;
	if ((a < 0) && (b < 0) && (c < 0)){
		if ((a < b) && (b <= c) || (a < c) && (c <= b)){
			//������ ������ ���������� ����� (modmin), ���� ���� ����� (sum2);
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
		//���� sum2 ����� -256, � modmin � �������� ����� � modmin ����� 256;
		if (sum2 < -256 && (int)(log2(modmin)) % 1 == 0){
			result = 1;
		}
		//���� ������ sum2 ������ �� modmin � sum2 ����� - 256;
		else if (abs(sum2) > modmin && sum2 > -256){
			result = 1;
		}
	}
	//���� �� ����� ������ ;
	else if (a >= 0 && b >= 0 && c >= 0){
		if ((a > b) && (b >= c) || (a > c) && (c >= b)){
			//������ ��������;
			max = a;
		}
		if ((c > b) && (b >= a) || (c > a) && (a >= b)){
			max = b;
		}
		if ((b > a) && (a >= c) || (b > c) && (c >= a)){
			max = c;
		}
		if ((a < b) && (b <= c) || (a < c) && (c <= b)){
			//������ �����;
			min = a;
		}
		if ((c < b) && (b <= a) || (c < a) && (a <= b)){
			min = b;
		}
		if ((b < a) && (a <= c) || (b < c) && (c <= a)){
			min = c;
		}
		//���������
		if ((max + min) < 256){
			result = 1;
		}
		}
	else {
		if ((a*b*c) < 0){
		//���� ��'����
			if (a < 0){
				//���������
				if (a > -256){
					result = 1;
				}
				result = (a > -256);
			}
			if (b < 0){
				if (b > -256){
					//���������
					result = 1;
				}
			}
			if (c < 0){
				if (c > -256){
					//���������
					result = 1;
				}
			}
		}
		else {
		// ��� ��'�����
			if(a<0 && b<0){
				//���������
				if ((a + b)*(6 + 0) > -256){
					result = 1;
				}
			}
			else if (a<0 && c<0){
				//���������
				if ((a + c)*(6 + 0) > -256){
					result = 1;
				}
			}
			else {
				//���������
				if ((b + c)*(6 + 0) > -256){
					result = 1;
				}
			}
		}
	}
	return result;
}
