#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fillRand1(int arr[], int size);
int checkRand1(int arr[], int size);
float meanValue(int arr[], int size);
int minValue(int arr[], int size);
int meanIndex(int arr[], int size);
int minIndex(int arr[], int size);
int maxOccurance(int arr[], int size);
int diff(int arr1[], int arr2[], int res[], int size);
void mult(int arr1[], int arr2[], int res[], int size);
int lt(int arr1[], int arr2[], int size);
void land(int arr1[], int arr2[], int res[], int size);

int main(){
    int size = 8;
    int arr[size];
    int arr1[8]={1,2,3,4,5,6,7,8};
    int arr2[8]={11,12,13,14,15,16,17,18};
    int res[8];

    int index;
    int i;
    srand(time(NULL));
        fillRand1(arr, size);
    for (i=0;i<size;i++)
        printf("%d\t", arr[i]);
        checkRand1(arr, size);
    printf("\n CheckRand = %d\n",checkRand1(arr, size));
        meanValue(arr, size);
    printf("Average value = %.3f\n",meanValue(arr, size));
        minValue(arr, size);
    printf("Min value = %d\n", minValue(arr, size));
        meanIndex(arr, size);
    printf("Index values near the average value = %d\n", meanIndex(arr, size));
        minIndex(arr, size);
    printf("Min index = %i \n ", minIndex(arr,size));
        maxOccurance(arr, size);
    printf("Value, which is most common in the array = %d\n", maxOccurance(arr, size));
        diff(arr1, arr2, res, size);
    printf("Diff = %d\n", diff(arr1, arr2, res, size));
       mult(arr1,arr2,res,size);
    printf("Mult\n");
    for (i=0;i<size;i++)
        printf("%d\t", res[i]);
        printf("\n");
        lt(arr1,arr2,size);
    printf("Less than = %d\n", lt(arr1, arr2, size));
        land(arr1,arr2,res,size);
    for (i=0;i<size;i++)
        printf("%d\t", res[i]);

    return 0;

}

void fillRand1(int arr[], int size){

    int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % (101 - 2)+1;
}

int checkRand1(int arr[], int size){
	int i;
	for (i = 0; i < size; i++){
		if ((arr[i]<1) || (arr[i]>99)){
			return 0;
		}
	}
	return 1;
}

float meanValue(int arr[], int size){
	int i;
	int sum = 0;
	int res;

	for (i = 0; i < size; i++){
		sum += arr[i];

	}
    res= sum/(float)size;
	return res;
}

int minValue(int arr[], int size){
    int i;
	int min = arr[0];
	for (i = 0; i < size; i++){
		if (arr[i]<min){
			min = arr[i];
		}
	}
	return min;
}

int meanIndex(int arr[], int size){
    int i;
    float mean = meanValue(arr, size);
    int index;
    float delta= fabs(arr[0] - mean);
    for(i=1;i<size; i++){
        float deltaMean = fabs(mean - arr[i]);
        if(deltaMean<delta){
            index = i;
            delta = deltaMean;
        }
    }
    return index;
}

 int minIndex(int arr[], int size){
    int i=0;
    int index=0;
    int minimum = arr[0];
     for (i=0; i< size; i++){
            if (arr[i] < minimum){
            minimum = arr[i];
            index = i;
        }
    }
    return index;
}

int maxOccurance(int arr[], int size){
    int i = 0, j =0, counter = 0, max_counter = 0, max_index = 0 ;
        for (i = 0; i < size; i++){
        counter = 0;
            for (j = 0; j < size; j++){
                if (arr[i]==arr[j]){
            counter++;
                }
            }
        if (counter > max_counter){
            max_counter = counter;
            max_index = i;
           }
        if (counter == max_counter){
                if (arr[i] > arr[max_index]){
                        max_index = i;
                }
            }

    }
return arr[max_index];
}

int diff(int arr1[], int arr2[], int res[], int size){
	int i, result;
	for (i = 0; i < size; i++){
		res[i] = arr1[i] - arr2[i];
		if (res[i]!=0) {
			result = 0;
		} else result = 1;
	}
	return result;
}

void mult(int arr1[], int arr2[], int res[], int size){
    int i;
    for (i=0; i< size; i++){
             res[i]= arr1[i]*arr2[i];
    }
}

int lt(int arr1[], int arr2[], int size){
	int i;
	for (i = 0; i < size; i++){
		if (arr1[i] <= arr2[i]){
			return 1;
		}
	}
	return 0;
}

void land(int arr1[], int arr2[], int res[], int size){
    int i;

    for (i=0; i< size; i++){
        arr1[i]=rand()%2;
        arr2[i]=rand()%2;
        res[i]= arr1[i] &&  arr2[i];
        printf("%d\t", arr1[i]);
        printf(" %d\t\n", arr2[i]);
    }
        printf("\n");
}

