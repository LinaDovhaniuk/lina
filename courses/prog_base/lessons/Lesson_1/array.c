void fillArray(int a[10]){
    int i;
    for (i=0; i<10; i++){
        a[i]= i+1;
    }
}

void shiftArray(int a[10]){
    int i;
    int n=10;
    int tmp = a[n-1];
    for (i= n-2; i>=0; i--){
        a[i + 1]= a[i];
    }
    a[0]=tmp;

}

void printArray(int a[10]){
    int i;
    for (i=0; i<10; i++){
        printf("%i", a[i]);
    }
    puts("");
}

