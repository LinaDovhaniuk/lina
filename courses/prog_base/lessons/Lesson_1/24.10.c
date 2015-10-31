#include <stdio.h>
#include <stdlib.h>

void fillArray(int a[10]);
void shiftArray(int a[10]);
void printArray(int a[10]);

int main(){
    int arr[10]; /*create array of 10 ints*/
    fillArray(arr);/*fill array with numbers*/
    shiftArray(arr);   /*shift array circular*/
    printArray(arr);   /* print array for me*/
    return 0;

 }
