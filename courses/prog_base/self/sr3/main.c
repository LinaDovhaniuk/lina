#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void fillRand(int size, struct Point p[size]);
void prt(int size, struct Point p[size]);

int main(){
    int size = 15;
    struct Point p[size];
    srand(time(NULL));
    fillRand(size,p);
    prt(size,p);

}

struct Point{
    int x,y;
};

void fillRand(int size, struct Point p[size]){
    int i;
    for (i=0; i<size; i++){
        p[i].x = rand()%10;
        p[i].y = rand()%10;
    }
}

void prt(int size, struct Point p[size]){
    int i;
    for(i=0; i<size; i++){
        printf("Coordinates are : [ %i ; %i ]\n", p[i].x, p[i].y);
    }
}

void dstP1(struct Point *p1, struct Point *p2){
    float res;
    res = sqrt(pow(p1->x - p2->x,2)+pow(p1->y-p2->y,2));

    return res;
}
void dstP2(struct Point *p1, struct Point *p3){
    float res2;
    res2 = sqr(pow(p1->x - p3->x,2)+pow(p1->y-p3->y,2));

    return res2;
}

void rectangle(int size, struct Point p[size]){
    int i,j;
    int Mi,Mj;
    int M1i, M1j;
    float minDst = 0, dst, dst1, minDst1 = 0;
     for (i=0; i<size; i++){
        for (j=i; j<size; j++){
            dst=dstP(&p[i], &p[j]);
            dst1=dstP(&p[i], &p[j]);
            if(dst<minDst){
                minDst = dst;

                Mi=i;
                Mj=j;
            }
            if(dst1<minDst1){
                minDst1 = dst1;
                Mi=i;
                Mj=j;
            }
        }
     }

}
