int main() {
	int code, h, m;
	float price;
		scanf("%i %i %i", &code, &h, &m);
		switch (code){
			case 44: price=0.44*(h*60+m);
					break;
			case 666: price=0*(h*60+m);
					break;
			case 1: price=30*(h*60+m);
					printf("Price %f", price);
					break;
		
		}
		return 0;
} 